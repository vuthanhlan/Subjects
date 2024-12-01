/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
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
    QTextEdit *label1;
    QPushButton *btn_Encrypt;
    QGroupBox *groupBox;
    QPushButton *btn_TaoKhoa;
    QLabel *label_p;
    QLabel *label_q;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *line_p;
    QLineEdit *line_q;
    QLineEdit *line_n;
    QLineEdit *line_phi;
    QLineEdit *line_e;
    QLineEdit *line_d;
    QMenuBar *menubar;
    QMenu *menuRSA;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 30, 71, 16));
        label1 = new QTextEdit(centralwidget);
        label1->setObjectName("label1");
        label1->setGeometry(QRect(270, 20, 211, 31));
        btn_Encrypt = new QPushButton(centralwidget);
        btn_Encrypt->setObjectName("btn_Encrypt");
        btn_Encrypt->setGeometry(QRect(40, 230, 75, 24));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(200, 70, 281, 161));
        btn_TaoKhoa = new QPushButton(groupBox);
        btn_TaoKhoa->setObjectName("btn_TaoKhoa");
        btn_TaoKhoa->setGeometry(QRect(110, 10, 75, 24));
        label_p = new QLabel(groupBox);
        label_p->setObjectName("label_p");
        label_p->setGeometry(QRect(20, 40, 21, 16));
        label_p->setFrameShape(QFrame::NoFrame);
        label_q = new QLabel(groupBox);
        label_q->setObjectName("label_q");
        label_q->setGeometry(QRect(160, 40, 31, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 80, 49, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 80, 49, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 120, 49, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(160, 120, 49, 16));
        line_p = new QLineEdit(groupBox);
        line_p->setObjectName("line_p");
        line_p->setGeometry(QRect(40, 40, 91, 22));
        line_q = new QLineEdit(groupBox);
        line_q->setObjectName("line_q");
        line_q->setGeometry(QRect(180, 40, 81, 22));
        line_n = new QLineEdit(groupBox);
        line_n->setObjectName("line_n");
        line_n->setGeometry(QRect(40, 80, 91, 22));
        line_phi = new QLineEdit(groupBox);
        line_phi->setObjectName("line_phi");
        line_phi->setGeometry(QRect(180, 80, 81, 22));
        line_e = new QLineEdit(groupBox);
        line_e->setObjectName("line_e");
        line_e->setGeometry(QRect(40, 120, 91, 22));
        line_d = new QLineEdit(groupBox);
        line_d->setObjectName("line_d");
        line_d->setGeometry(QRect(180, 120, 81, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuRSA = new QMenu(menubar);
        menuRSA->setObjectName("menuRSA");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuRSA->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Message:", nullptr));
        label1->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        btn_Encrypt->setText(QCoreApplication::translate("MainWindow", "Encrypt", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "T\341\272\241o kh\303\263a", nullptr));
        btn_TaoKhoa->setText(QCoreApplication::translate("MainWindow", "T\341\272\241o Kh\303\263a", nullptr));
        label_p->setText(QCoreApplication::translate("MainWindow", "P:", nullptr));
        label_q->setText(QCoreApplication::translate("MainWindow", "q:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "n:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "phi:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "E:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "d:", nullptr));
        menuRSA->setTitle(QCoreApplication::translate("MainWindow", "RSA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
