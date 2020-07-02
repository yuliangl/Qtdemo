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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New_Project_N;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu_file_F;
    QMenu *menuEdit;
    QMenu *menuBuild;
    QMenu *menuDebug_D;
    QMenu *menuTool_I;
    QStatusBar *statusbar;

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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
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

        menubar->addAction(menu_file_F->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuBuild->menuAction());
        menubar->addAction(menuDebug_D->menuAction());
        menubar->addAction(menuTool_I->menuAction());
        menu_file_F->addAction(action_New_Project_N);

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
        menu_file_F->setTitle(QCoreApplication::translate("MainWindow", "file(&F)", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit(&E)", nullptr));
        menuBuild->setTitle(QCoreApplication::translate("MainWindow", "Build(&B)", nullptr));
        menuDebug_D->setTitle(QCoreApplication::translate("MainWindow", "Debug(&D)", nullptr));
        menuTool_I->setTitle(QCoreApplication::translate("MainWindow", "Tool(&I)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
