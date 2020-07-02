/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New_Project_N;
    QAction *actionopen_O;
    QAction *actionClose_C;
    QAction *actionsave_S;
    QAction *actionsave_as_A;
    QAction *actionexit_X;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu_file_F;
    QMenu *menuEdit;
    QMenu *menuBuild;
    QMenu *menuDebug_D;
    QMenu *menuTool_I;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        action_New_Project_N = new QAction(MainWindow);
        action_New_Project_N->setObjectName(QString::fromUtf8("action_New_Project_N"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/myImages/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New_Project_N->setIcon(icon);
        actionopen_O = new QAction(MainWindow);
        actionopen_O->setObjectName(QString::fromUtf8("actionopen_O"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/myImages/images/openfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionopen_O->setIcon(icon1);
        actionClose_C = new QAction(MainWindow);
        actionClose_C->setObjectName(QString::fromUtf8("actionClose_C"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/myImages/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose_C->setIcon(icon2);
        actionsave_S = new QAction(MainWindow);
        actionsave_S->setObjectName(QString::fromUtf8("actionsave_S"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/myImages/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsave_S->setIcon(icon3);
        actionsave_as_A = new QAction(MainWindow);
        actionsave_as_A->setObjectName(QString::fromUtf8("actionsave_as_A"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/myImages/images/save as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsave_as_A->setIcon(icon4);
        actionexit_X = new QAction(MainWindow);
        actionexit_X->setObjectName(QString::fromUtf8("actionexit_X"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/myImages/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionexit_X->setIcon(icon5);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu_file_F = new QMenu(menubar);
        menu_file_F->setObjectName(QString::fromUtf8("menu_file_F"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuBuild = new QMenu(menubar);
        menuBuild->setObjectName(QString::fromUtf8("menuBuild"));
        menuDebug_D = new QMenu(menubar);
        menuDebug_D->setObjectName(QString::fromUtf8("menuDebug_D"));
        menuTool_I = new QMenu(menubar);
        menuTool_I->setObjectName(QString::fromUtf8("menuTool_I"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_file_F->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuBuild->menuAction());
        menubar->addAction(menuDebug_D->menuAction());
        menubar->addAction(menuTool_I->menuAction());
        menu_file_F->addAction(action_New_Project_N);
        menu_file_F->addAction(actionopen_O);
        menu_file_F->addAction(actionClose_C);
        menu_file_F->addAction(actionsave_S);
        menu_file_F->addAction(actionsave_as_A);
        menu_file_F->addAction(actionexit_X);
        toolBar->addAction(action_New_Project_N);
        toolBar->addAction(actionopen_O);
        toolBar->addAction(actionClose_C);
        toolBar->addAction(actionsave_S);
        toolBar->addAction(actionsave_as_A);
        toolBar->addAction(actionexit_X);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_New_Project_N->setText(QCoreApplication::translate("MainWindow", "New Project(&N)", nullptr));
#if QT_CONFIG(shortcut)
        action_New_Project_N->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionopen_O->setText(QCoreApplication::translate("MainWindow", "open(&O)", nullptr));
#if QT_CONFIG(shortcut)
        actionopen_O->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose_C->setText(QCoreApplication::translate("MainWindow", "Close(&C)", nullptr));
#if QT_CONFIG(shortcut)
        actionClose_C->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionsave_S->setText(QCoreApplication::translate("MainWindow", "save(&S)", nullptr));
#if QT_CONFIG(shortcut)
        actionsave_S->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionsave_as_A->setText(QCoreApplication::translate("MainWindow", "save as(&A)", nullptr));
#if QT_CONFIG(shortcut)
        actionsave_as_A->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionexit_X->setText(QCoreApplication::translate("MainWindow", "exit(&X)", nullptr));
#if QT_CONFIG(shortcut)
        actionexit_X->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS UI Gothic'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:600;\">first mian window</span></p></body></html>", nullptr));
        menu_file_F->setTitle(QCoreApplication::translate("MainWindow", "file(&F)", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit(&E)", nullptr));
        menuBuild->setTitle(QCoreApplication::translate("MainWindow", "Build(&B)", nullptr));
        menuDebug_D->setTitle(QCoreApplication::translate("MainWindow", "Debug(&D)", nullptr));
        menuTool_I->setTitle(QCoreApplication::translate("MainWindow", "Tool(&I)", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
