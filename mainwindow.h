#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "quadtree.h"
#include "overlaywidget.h"
#include <QMainWindow>
#include <QPoint>
#include <QLineEdit>
#include <QLabel>
#include <QEvent>
#include "drawwidget.h" // 添加头文件
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:

    bool eventFilter(QObject *watched, QEvent *event) override;
    void showEvent(QShowEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_label_2_linkActivated(const QString &link);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QuadNode* root = nullptr;
    OverlayWidget *overlay;
        DrawWidget *drawWidget; // 成员变量
    // 新增：指定用于画框的 QLabel 控件指针
    QLabel* imageLabel = nullptr;

    // 更新输入框坐标值
    void updateLineEdits(const QPoint &p1, const QPoint &p2);
};

#endif // MAINWINDOW_H
