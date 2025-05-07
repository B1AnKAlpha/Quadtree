#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <algorithm>
#include <fstream>
#include "common.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QMouseEvent>
#include <QPainter>
#include "drawwidget.h"
#pragma execution_character_set("utf-8")


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , root(nullptr)
{
    ui->setupUi(this);

    // 设置 label 的事件过滤器，仅响应点击

    ui->label->installEventFilter(this);

    // 创建 drawWidget 作为 label 的子控件
    drawWidget = new DrawWidget(ui->label);
    drawWidget->setGeometry(ui->label->rect());
    drawWidget->setAttribute(Qt::WA_TransparentForMouseEvents);
    drawWidget->setAttribute(Qt::WA_TranslucentBackground);
    drawWidget->setStyleSheet("background: transparent;");
    drawWidget->show();

    // 创建 overlay 作为 label 的子控件
    overlay = new OverlayWidget(ui->label);
    overlay->setGeometry(ui->label->rect());
    overlay->setAttribute(Qt::WA_TranslucentBackground);
    overlay->setStyleSheet("background: transparent;");
    overlay->show();


    // 连接矩形完成信号
    connect(overlay, &OverlayWidget::rectangleReady, this, &MainWindow::updateLineEdits);
}



MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);


}

void MainWindow::on_label_2_linkActivated(const QString &link)
{

}
void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    if (overlay && ui->label) {
        overlay->setGeometry(ui->label->geometry());
    }
}


void MainWindow::updateLineEdits(const QPoint &p1, const QPoint &p2) {
    QPoint tl(std::min(p1.x(), p2.x()), std::min(p1.y(), p2.y()));
    QPoint br(std::max(p1.x(), p2.x()), std::max(p1.y(), p2.y()));

    // 线性变换参数
    constexpr double scale1 = 0.0013043478261;
    constexpr double offset1 = 116.0047826086956;

    constexpr double scale2 = -0.00092378752886;
    constexpr double offset2 = 40.16189376443418;

    // 应用变换
    double transformedX1 = tl.x() * scale1 + offset1;
    double transformedX2 = br.x() * scale1 + offset1;
    double transformedY1 = tl.y() * scale2 + offset2;
    double transformedY2 = br.y() * scale2 + offset2;

    ui->lineEdit_3->setText(QString::number(transformedX1, 'f', 6));  // 保留6位小数
    ui->lineEdit_4->setText(QString::number(transformedY1, 'f', 6));
    ui->lineEdit_5->setText(QString::number(transformedX2, 'f', 6));
    ui->lineEdit_6->setText(QString::number(transformedY2, 'f', 6));
}


bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
    if (watched == ui->label && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        QPoint localPos = mouseEvent->pos();  // 鼠标相对于 label 的位置

        // 将事件坐标传递给 overlay
        if (overlay) {
            overlay->setPoint(localPos);
            overlay->update();  // 触发重绘
        }

        return true; // 表示事件已处理
    }
    return QMainWindow::eventFilter(watched, event);
}



void MainWindow::on_pushButton_clicked()
{
    QString lon = ui->lineEdit->text();
    double x = lon.toDouble();
    QString lan = ui->lineEdit_2->text();
    double y = lan.toDouble();

    qDebug() << "输入经度：" << lon << " 转换后：" << x;
    qDebug() << "输入纬度：" << lan << " 转换后：" << y;
    auto result = root->PointSearch(std::make_pair(x, y));
    ui->textEdit->setText("222");
    if (result.empty()) {
        //std::cout << "未查询到\n";
        ui->textEdit->setText("未查询到");
        ui->textEdit->setText(lon+lan);
    } else {

        //ui->textEdit->setText(result);
        ui->textEdit->setText("111");
        printVector(result);


        QFile file("output.txt"); // 你也可以写绝对路径

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ui->textEdit->setText("无法打开文件！");
            return;
        }

        QTextStream in(&file);
        QString fileContent = in.readAll();  // 读取全部内容
        file.close();

        ui->textEdit->setText(fileContent);  // 设置到文本框中
    }


}


void MainWindow::on_pushButton_2_clicked()
{
    this->root = new QuadNode();   // 正确地使用成员变量
    int DATANUM = 10000;
    Rectangle* bounding_box = new Rectangle();
    double min_lon = 181, max_lon = 0, min_lat = 181, max_lat = 0;

    ui->label_2->setText("正在构建包围盒");

    for (int i = 1; i <= DATANUM; ++i) {
        std::string buffer;
        std::string path = "E:\\Code\\GIS\\Sichashu\\Quadtree\\data\\" + std::to_string(i) + ".txt";
        std::ifstream file(path);
        if (!file.is_open()) continue;

        while (std::getline(file, buffer)) {
            auto gps = str2data(buffer);
            min_lon = std::min(min_lon, gps->longitude);
            min_lat = std::min(min_lat, gps->latitude);
            max_lon = std::max(max_lon, gps->longitude);
            max_lat = std::max(max_lat, gps->latitude);
            delete gps;
        }

        file.close();
    }

    bounding_box->bottom_left = std::make_pair(min_lon, min_lat);
    bounding_box->top_right = std::make_pair(max_lon, max_lat);
    this->root->range = bounding_box;

    ui->label_2->setText("正在构建四叉树");

    for (int i = 1; i <= DATANUM; ++i) {
        std::string buffer;
        std::string path = "E:\\Code\\GIS\\Sichashu\\Quadtree\\data\\" + std::to_string(i) + ".txt";
        std::ifstream file(path);
        if (!file.is_open()) continue;

        while (std::getline(file, buffer)) {
            auto gps = str2data(buffer);
            this->root->InsertNode(gps, 8);  // 用 this->root 插入数据
        }

        file.close();
    }

    ui->label_2->setText("当前进度：四叉树已构建完成");
}



void MainWindow::on_pushButton_3_clicked()
{
    QString lon1 = ui->lineEdit_3->text();
    double x1 = lon1.toDouble();
    QString lan1 = ui->lineEdit_4->text();
    double y1 = lan1.toDouble();
    QString lon2 = ui->lineEdit_5->text();
    double x2 = lon2.toDouble();
    QString lan2 = ui->lineEdit_6->text();
    double y2 = lan2.toDouble();

    Rectangle* rect = new Rectangle(x2, y1, x1, y2);
    //Rectangle* rect = new Rectangle(y1, x2, y2, x1);
    auto result = root->AreaSearch(rect);

    ui->textEdit->setText("222");
    if (result.empty()) {
        //std::cout << "未查询到\n";
        ui->textEdit->setText("未查询到");
       // ui->textEdit->setText(lon+lan);
    } else {

        //ui->textEdit->setText(result);
        ui->textEdit->setText("111");
        printVector(result);


        QFile file("output.txt"); // 你也可以写绝对路径

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ui->textEdit->setText("无法打开文件！");
            return;
        }

        QTextStream in(&file);
        QString fileContent = in.readAll();  // 读取全部内容
        file.close();

        ui->textEdit->setText(fileContent);  // 设置到文本框中
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QString lon1 = ui->lineEdit_3->text();
    double x1 = lon1.toDouble();
    QString lan1 = ui->lineEdit_4->text();
    double y1 = lan1.toDouble();
    QString lon2 = ui->lineEdit_5->text();
    double x2 = lon2.toDouble();
    QString lan2 = ui->lineEdit_6->text();
    double y2 = lan2.toDouble();

    Rectangle* rect = new Rectangle(x2, y1, x1, y2);

    std::vector<int> time1, time2;

    QString timeStr1 = ui->lineEdit_7->text();  // 例如 "2025-05-05 14:30:15"
    QStringList parts1 = timeStr1.split(" ");
    if (parts1.size() == 2) {
        QStringList date1 = parts1[0].split("-");
        QStringList clock1 = parts1[1].split(":");
        if (date1.size() == 3 && clock1.size() == 3) {
            time1.push_back(date1[0].toInt()); // 年
            time1.push_back(date1[1].toInt()); // 月
            time1.push_back(date1[2].toInt()); // 日
            time1.push_back(clock1[0].toInt()); // 时
            time1.push_back(clock1[1].toInt()); // 分
            time1.push_back(clock1[2].toInt()); // 秒
        }
    }

    QString timeStr2 = ui->lineEdit_8->text();  // 例如 "2025-05-05 15:01:30"
    QStringList parts2 = timeStr2.split(" ");
    if (parts2.size() == 2) {
        QStringList date2 = parts2[0].split("-");
        QStringList clock2 = parts2[1].split(":");
        if (date2.size() == 3 && clock2.size() == 3) {
            time2.push_back(date2[0].toInt()); // 年
            time2.push_back(date2[1].toInt()); // 月
            time2.push_back(date2[2].toInt()); // 日
            time2.push_back(clock2[0].toInt()); // 时
            time2.push_back(clock2[1].toInt()); // 分
            time2.push_back(clock2[2].toInt()); // 秒
        }
    }
    QString idxString = ui->lineEdit_9->text();
    double idx = idxString.toDouble();

    auto result = root->AdjacentSearch(rect, time1, time2, idx);

    ui->textEdit->setText("222");
    if (result == nullptr) {
        //std::cout << "未查询到\n";
        ui->textEdit->setText("未查询到");
        // ui->textEdit->setText(lon+lan);
    } else {

        //ui->textEdit->setText(result);
        ui->textEdit->setText("111");
        //printVector(result);
        QFile::remove("output.txt");
        result->print();


        QFile file("output.txt");

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ui->textEdit->setText("无法打开文件！");
            return;
        }

        QTextStream in(&file);
        QString fileContent = in.readAll();  // 读取全部内容
        file.close();

        ui->textEdit->setText(fileContent);  // 设置到文本框中
    }
}



void MainWindow::on_pushButton_5_clicked()
{
    QString lon1 = ui->lineEdit_3->text();
    double x1 = lon1.toDouble();
    QString lan1 = ui->lineEdit_4->text();
    double y1 = lan1.toDouble();
    QString lon2 = ui->lineEdit_5->text();
    double x2 = lon2.toDouble();
    QString lan2 = ui->lineEdit_6->text();
    double y2 = lan2.toDouble();
    QString idxString = ui->lineEdit_9->text();
    int idx = idxString.toInt();
    Rectangle* rect = new Rectangle(x2, y1, x1, y2);
    //Rectangle* rect = new Rectangle(y1, x2, y2, x1);
    auto result = root->TrajectorySearch(rect,idx);

    ui->textEdit->setText("222");
    if (result.empty()) {
        ui->textEdit->setText("未查询到");
        // ui->textEdit->setText(lon+lan);
    } else {

        //ui->textEdit->setText(result);
        ui->textEdit->setText("111");
        printVector(result);


        QFile file("output.txt"); // 你也可以写绝对路径

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ui->textEdit->setText("无法打开文件！");
            return;
        }

        QTextStream in(&file);
        QString fileContent = in.readAll();  // 读取全部内容
        file.close();

        ui->textEdit->setText(fileContent);  // 设置到文本框中

        drawWidget->setAttribute(Qt::WA_TransparentForMouseEvents, false); // 确保不拦截鼠标事件


        drawWidget->loadPointsFromFile("output.txt");
        drawWidget->update();  // 触发重绘

    }
}


void MainWindow::on_pushButton_6_clicked()
{
    QString lon = ui->lineEdit->text();
    double x = lon.toDouble();
    QString lan = ui->lineEdit_2->text();
    double y = lan.toDouble();
    QString newlon = ui->lineEdit_11->text();
    double newx = newlon.toDouble();
    QString newlan = ui->lineEdit_10->text();
    double newy = newlan.toDouble();
    QString idx = ui->lineEdit_9->text();
    int id = idx.toDouble();
    qDebug() << "输入经度：" << lon << " 转换后：" << x;
    qDebug() << "输入纬度：" << lan << " 转换后：" << y;
    auto result = root->PointChange(id,std::make_pair(x, y),newx,newy);
    ui->textEdit->setText("222");
    if (result == false) {
        ui->textEdit->setText("未查询到");
    } else {
        ui->textEdit->setText("更改成功");

    }
}


void MainWindow::on_pushButton_7_clicked()
{
    QString lon = ui->lineEdit->text();
    double x = lon.toDouble();
    QString lan = ui->lineEdit_2->text();
    double y = lan.toDouble();
    QString idx = ui->lineEdit_9->text();
    int id = idx.toDouble();
    qDebug() << "输入经度：" << lon << " 转换后：" << x;
    qDebug() << "输入纬度：" << lan << " 转换后：" << y;
    auto result = root->PointDelete(id,x, y);
    ui->textEdit->setText("222");
    if (result == false) {
        //std::cout << "未查询到\n";
        ui->textEdit->setText("未查询到");
        // ui->textEdit->setText(lon+lan);
    } else {

        //ui->textEdit->setText(result);
        ui->textEdit->setText("删除成功");

    }
}

