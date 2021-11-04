/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(438, 308);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 220, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Bodoni MT\";\n"
"background-color: rgb(172, 169, 255);\n"
"border-radius: 10px;\n"
"border-bottom-style:solid;\n"
"border-bottom-width: 5px;\n"
"border-bottom-color: rgb(109, 127, 209);\n"
""));

        verticalLayout->addWidget(label);

        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(listWidget_2);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setStyleSheet(QString::fromUtf8("font: 11pt \"Bodoni MT\";\n"
"background-color: rgb(172, 169, 255);\n"
"border-radius: 10px;\n"
"border-bottom-style:solid;\n"
"border-bottom-width: 5px;\n"
"border-bottom-color: rgb(109, 127, 209);"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 11pt \"Bodoni MT\";\n"
"background-color: rgb(172, 169, 255);\n"
"border-radius: 10px;\n"
"border-bottom-style:solid;\n"
"border-bottom-width: 5px;\n"
"border-bottom-color: rgb(109, 127, 209);\n"
""));

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 11pt \"Bodoni MT\";\n"
"background-color: rgb(172, 169, 255);\n"
"border-radius: 10px;\n"
"border-bottom-style:solid;\n"
"border-bottom-width: 5px;\n"
"border-bottom-color: rgb(109, 127, 209);\n"
""));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("font: 11pt \"Bodoni MT\";\n"
"background-color: rgb(172, 169, 255);\n"
"border-radius: 10px;\n"
"border-bottom-style:solid;\n"
"border-bottom-width: 5px;\n"
"border-bottom-color: rgb(109, 127, 209);\n"
""));

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("font: 11pt \"Bodoni MT\";\n"
"background-color: rgb(172, 169, 255);\n"
"border-radius: 0px;\n"
"border-bottom-style:solid;\n"
"border-bottom-width: 5px;\n"
"border-bottom-color: rgb(109, 127, 209);"));

        verticalLayout_2->addWidget(lineEdit);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 438, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "            NOTES", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Add group of notes", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Archive", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Save and Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
