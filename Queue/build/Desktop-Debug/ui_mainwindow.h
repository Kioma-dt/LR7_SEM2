/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *textNumberFirst;
    QPushButton *buttonGenerateFirst;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *textNumberSecond;
    QPushButton *buttonGenerateSecond;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *buttonMinFirst;
    QPushButton *buttonSwap;
    QPushButton *buttonMinSecond;
    QGridLayout *gridLayout;
    QListWidget *listFirst;
    QListWidget *listSecond;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonAddFirst;
    QPushButton *buttonRemoveFirst;
    QLabel *label_3;
    QLineEdit *textValue;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonAddSecond;
    QPushButton *buttonRemoveSecond;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 20, 781, 531));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout_4->addWidget(label);

        textNumberFirst = new QLineEdit(layoutWidget);
        textNumberFirst->setObjectName("textNumberFirst");

        horizontalLayout_4->addWidget(textNumberFirst);

        buttonGenerateFirst = new QPushButton(layoutWidget);
        buttonGenerateFirst->setObjectName("buttonGenerateFirst");

        horizontalLayout_4->addWidget(buttonGenerateFirst);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_5->addWidget(label_2);

        textNumberSecond = new QLineEdit(layoutWidget);
        textNumberSecond->setObjectName("textNumberSecond");

        horizontalLayout_5->addWidget(textNumberSecond);

        buttonGenerateSecond = new QPushButton(layoutWidget);
        buttonGenerateSecond->setObjectName("buttonGenerateSecond");

        horizontalLayout_5->addWidget(buttonGenerateSecond);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        buttonMinFirst = new QPushButton(layoutWidget);
        buttonMinFirst->setObjectName("buttonMinFirst");

        horizontalLayout_6->addWidget(buttonMinFirst);

        buttonSwap = new QPushButton(layoutWidget);
        buttonSwap->setObjectName("buttonSwap");

        horizontalLayout_6->addWidget(buttonSwap);

        buttonMinSecond = new QPushButton(layoutWidget);
        buttonMinSecond->setObjectName("buttonMinSecond");

        horizontalLayout_6->addWidget(buttonMinSecond);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        listFirst = new QListWidget(layoutWidget);
        listFirst->setObjectName("listFirst");

        gridLayout->addWidget(listFirst, 0, 0, 1, 1);

        listSecond = new QListWidget(layoutWidget);
        listSecond->setObjectName("listSecond");

        gridLayout->addWidget(listSecond, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        buttonAddFirst = new QPushButton(layoutWidget);
        buttonAddFirst->setObjectName("buttonAddFirst");

        horizontalLayout->addWidget(buttonAddFirst);

        buttonRemoveFirst = new QPushButton(layoutWidget);
        buttonRemoveFirst->setObjectName("buttonRemoveFirst");

        horizontalLayout->addWidget(buttonRemoveFirst);


        horizontalLayout_3->addLayout(horizontalLayout);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        textValue = new QLineEdit(layoutWidget);
        textValue->setObjectName("textValue");

        horizontalLayout_3->addWidget(textValue);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        buttonAddSecond = new QPushButton(layoutWidget);
        buttonAddSecond->setObjectName("buttonAddSecond");

        horizontalLayout_2->addWidget(buttonAddSecond);

        buttonRemoveSecond = new QPushButton(layoutWidget);
        buttonRemoveSecond->setObjectName("buttonRemoveSecond");

        horizontalLayout_2->addWidget(buttonRemoveSecond);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 2);


        verticalLayout_2->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "First Queue Number: ", nullptr));
        buttonGenerateFirst->setText(QCoreApplication::translate("MainWindow", "Genearate First", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Second Queue Number: ", nullptr));
        buttonGenerateSecond->setText(QCoreApplication::translate("MainWindow", "Genearate Second", nullptr));
        buttonMinFirst->setText(QCoreApplication::translate("MainWindow", "Push Min In First", nullptr));
        buttonSwap->setText(QCoreApplication::translate("MainWindow", "Swap", nullptr));
        buttonMinSecond->setText(QCoreApplication::translate("MainWindow", "Push Min In Second", nullptr));
        buttonAddFirst->setText(QCoreApplication::translate("MainWindow", "Add To First", nullptr));
        buttonRemoveFirst->setText(QCoreApplication::translate("MainWindow", "Remove From First", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Input Integer: ", nullptr));
        buttonAddSecond->setText(QCoreApplication::translate("MainWindow", "Add To Second", nullptr));
        buttonRemoveSecond->setText(QCoreApplication::translate("MainWindow", "Remove From Second", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
