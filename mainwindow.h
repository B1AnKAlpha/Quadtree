#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "quadtree.h"
#include <QMainWindow>
#include <QPoint>
#include <QLineEdit>
#include "overlaywidget.h"

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
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_label_2_linkActivated(const QString &link);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QuadNode* root = nullptr;
    OverlayWidget *overlay;
    void updateLineEdits(const QPoint &p1, const QPoint &p2);

};




#endif // MAINWINDOW_H
