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
#pragma execution_character_set("utf-8")


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    QuadNode* root = new QuadNode();
    overlay = new OverlayWidget(this);
    overlay->setGeometry(this->rect());
    overlay->raise();  // 确保在最上面
    overlay->show();

    // 连接信号槽
    connect(overlay, &OverlayWidget::rectangleReady, this, &MainWindow::updateLineEdits);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_label_2_linkActivated(const QString &link)
{

}
void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    if (overlay) overlay->setGeometry(this->rect()); // 保持覆盖
}

void MainWindow::updateLineEdits(const QPoint &p1, const QPoint &p2) {
    QPoint tl(std::min(p1.x(), p2.x()), std::min(p1.y(), p2.y()));
    QPoint tr(std::max(p1.x(), p2.x()), std::min(p1.y(), p2.y()));
    QPoint br(std::max(p1.x(), p2.x()), std::max(p1.y(), p2.y()));
    QPoint bl(std::min(p1.x(), p2.x()), std::max(p1.y(), p2.y()));

    ui->lineEdit_3->setText(QString("(%1, %2)").arg(tl.x()).arg(tl.y()));
    ui->lineEdit_4->setText(QString("(%1, %2)").arg(tr.x()).arg(tr.y()));
    ui->lineEdit_5->setText(QString("(%1, %2)").arg(br.x()).arg(br.y()));
    ui->lineEdit_6->setText(QString("(%1, %2)").arg(bl.x()).arg(bl.y()));
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


