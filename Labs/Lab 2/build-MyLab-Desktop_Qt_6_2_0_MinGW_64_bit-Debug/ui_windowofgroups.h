/********************************************************************************
** Form generated from reading UI file 'windowofgroups.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWOFGROUPS_H
#define UI_WINDOWOFGROUPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windowofgroups
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton;

    void setupUi(QDialog *windowofgroups)
    {
        if (windowofgroups->objectName().isEmpty())
            windowofgroups->setObjectName(QString::fromUtf8("windowofgroups"));
        windowofgroups->resize(400, 300);
        windowofgroups->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 220, 255);"));
        gridLayout = new QGridLayout(windowofgroups);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(windowofgroups);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_2->addWidget(listWidget);


        gridLayout_2->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Bodoni MT\";\n"
"background-color: rgb(172, 169, 255);\n"
"border-radius: 10px;\n"
"border-bottom-style:solid;\n"
"border-bottom-width: 5px;\n"
"border-bottom-color: rgb(109, 127, 209);\n"
""));

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 66, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("font: 11pt \"Bodoni MT\";\n"
"background-color: rgb(172, 169, 255);\n"
"border-radius: 10px;\n"
"border-bottom-style:solid;\n"
"border-bottom-width: 5px;\n"
"border-bottom-color: rgb(109, 127, 209);\n"
""));

        verticalLayout->addWidget(pushButton);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(windowofgroups);

        QMetaObject::connectSlotsByName(windowofgroups);
    } // setupUi

    void retranslateUi(QDialog *windowofgroups)
    {
        windowofgroups->setWindowTitle(QCoreApplication::translate("windowofgroups", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("windowofgroups", "CHOOSE", nullptr));
        pushButton->setText(QCoreApplication::translate("windowofgroups", "Add and Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class windowofgroups: public Ui_windowofgroups {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWOFGROUPS_H
