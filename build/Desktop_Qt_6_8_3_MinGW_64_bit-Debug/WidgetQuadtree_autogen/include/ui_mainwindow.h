/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1094, 588);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 591, 561));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/output_plot3.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 0, 281, 91));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(840, 410, 31, 41));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(600, 450, 461, 91));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(690, 90, 113, 23));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(690, 120, 113, 23));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(670, 150, 80, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(610, 10, 461, 51));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(610, 90, 81, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(610, 120, 81, 31));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(850, 90, 101, 23));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(970, 90, 101, 23));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(850, 120, 101, 23));
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(970, 120, 101, 23));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(930, 60, 81, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_6->setFont(font);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(680, 60, 81, 31));
        label_7->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(920, 150, 80, 24));
        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(850, 180, 101, 23));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(920, 240, 80, 24));
        lineEdit_8 = new QLineEdit(centralwidget);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(970, 180, 101, 23));
        lineEdit_9 = new QLineEdit(centralwidget);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(910, 210, 101, 23));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(920, 280, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1094, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\237\272\344\272\216\345\233\233\345\217\211\346\240\221\347\232\204\350\275\250\350\277\271\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\257\267\345\205\210\347\202\271\345\207\273\346\236\204\345\273\272\345\233\233\345\217\211\346\240\221\346\214\211\351\222\256\350\277\233\350\241\214\345\210\235\345\247\213\345\214\226", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\207\272", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "116.51172", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "39.92123", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\346\236\204\345\273\272\345\233\233\345\217\211\346\240\221", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\273\217\345\272\246", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\347\272\254\345\272\246", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "39.92123", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "39.92123", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "39.92123", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("MainWindow", "39.92123", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\214\272\345\237\237\346\237\245\350\257\242", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\202\271\346\237\245\350\257\242", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "2008-02-01 00:00:00", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("MainWindow", "2008-02-08 00:00:00", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
