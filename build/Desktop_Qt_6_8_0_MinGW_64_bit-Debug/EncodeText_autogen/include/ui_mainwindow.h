/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *writeButton;
    QPushButton *readButton;
    QPushButton *encodeButton;
    QPushButton *decodeButton;
    QTextEdit *keyLineEdit;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(702, 604);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        writeButton = new QPushButton(centralwidget);
        writeButton->setObjectName("writeButton");

        verticalLayout->addWidget(writeButton);

        readButton = new QPushButton(centralwidget);
        readButton->setObjectName("readButton");

        verticalLayout->addWidget(readButton);

        encodeButton = new QPushButton(centralwidget);
        encodeButton->setObjectName("encodeButton");

        verticalLayout->addWidget(encodeButton);

        decodeButton = new QPushButton(centralwidget);
        decodeButton->setObjectName("decodeButton");

        verticalLayout->addWidget(decodeButton);


        verticalLayout_2->addLayout(verticalLayout);

        keyLineEdit = new QTextEdit(centralwidget);
        keyLineEdit->setObjectName("keyLineEdit");

        verticalLayout_2->addWidget(keyLineEdit);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");

        verticalLayout_2->addWidget(textEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 702, 21));
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
        writeButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        readButton->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        encodeButton->setText(QCoreApplication::translate("MainWindow", "Encode", nullptr));
        decodeButton->setText(QCoreApplication::translate("MainWindow", "Decode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
