/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *exitAction;
    QAction *insertRowAction;
    QAction *removeRowAction;
    QAction *insertColumnAction;
    QAction *removeColumnAction;
    QAction *insertChildAction;
    QAction *actionAjouter_un_joueur;
    QAction *actionCr_er_une_quipe;
    QAction *actionCr_er_un_tournoi;
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QTreeView *view;
    QLineEdit *lineEdit;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *actionsMenu;
    QMenu *menuInscription;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(706, 468);
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        insertRowAction = new QAction(MainWindow);
        insertRowAction->setObjectName(QString::fromUtf8("insertRowAction"));
        removeRowAction = new QAction(MainWindow);
        removeRowAction->setObjectName(QString::fromUtf8("removeRowAction"));
        insertColumnAction = new QAction(MainWindow);
        insertColumnAction->setObjectName(QString::fromUtf8("insertColumnAction"));
        removeColumnAction = new QAction(MainWindow);
        removeColumnAction->setObjectName(QString::fromUtf8("removeColumnAction"));
        insertChildAction = new QAction(MainWindow);
        insertChildAction->setObjectName(QString::fromUtf8("insertChildAction"));
        actionAjouter_un_joueur = new QAction(MainWindow);
        actionAjouter_un_joueur->setObjectName(QString::fromUtf8("actionAjouter_un_joueur"));
        actionCr_er_une_quipe = new QAction(MainWindow);
        actionCr_er_une_quipe->setObjectName(QString::fromUtf8("actionCr_er_une_quipe"));
        actionCr_er_un_tournoi = new QAction(MainWindow);
        actionCr_er_un_tournoi->setObjectName(QString::fromUtf8("actionCr_er_un_tournoi"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(270, 0, 441, 411));
        graphicsView->setMinimumSize(QSize(256, 0));
        view = new QTreeView(centralwidget);
        view->setObjectName(QString::fromUtf8("view"));
        view->setGeometry(QRect(0, 40, 271, 371));
        view->setAlternatingRowColors(true);
        view->setSelectionBehavior(QAbstractItemView::SelectItems);
        view->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        view->setAnimated(false);
        view->setAllColumnsShowFocus(true);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 6, 151, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(4, 15, 101, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 706, 26));
        fileMenu = new QMenu(menubar);
        fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
        actionsMenu = new QMenu(menubar);
        actionsMenu->setObjectName(QString::fromUtf8("actionsMenu"));
        menuInscription = new QMenu(menubar);
        menuInscription->setObjectName(QString::fromUtf8("menuInscription"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(fileMenu->menuAction());
        menubar->addAction(actionsMenu->menuAction());
        menubar->addAction(menuInscription->menuAction());
        fileMenu->addAction(exitAction);
        actionsMenu->addAction(insertRowAction);
        actionsMenu->addAction(insertColumnAction);
        actionsMenu->addSeparator();
        actionsMenu->addAction(removeRowAction);
        actionsMenu->addAction(removeColumnAction);
        actionsMenu->addSeparator();
        actionsMenu->addAction(insertChildAction);
        menuInscription->addAction(actionAjouter_un_joueur);
        menuInscription->addAction(actionCr_er_une_quipe);
        menuInscription->addAction(actionCr_er_un_tournoi);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Editable Tree Model", nullptr));
        exitAction->setText(QApplication::translate("MainWindow", "E&xit", nullptr));
#ifndef QT_NO_SHORTCUT
        exitAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        insertRowAction->setText(QApplication::translate("MainWindow", "Insert Row", nullptr));
#ifndef QT_NO_SHORTCUT
        insertRowAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+I, R", nullptr));
#endif // QT_NO_SHORTCUT
        removeRowAction->setText(QApplication::translate("MainWindow", "Remove Row", nullptr));
#ifndef QT_NO_SHORTCUT
        removeRowAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+R, R", nullptr));
#endif // QT_NO_SHORTCUT
        insertColumnAction->setText(QApplication::translate("MainWindow", "Insert Column", nullptr));
#ifndef QT_NO_SHORTCUT
        insertColumnAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+I, C", nullptr));
#endif // QT_NO_SHORTCUT
        removeColumnAction->setText(QApplication::translate("MainWindow", "Remove Column", nullptr));
#ifndef QT_NO_SHORTCUT
        removeColumnAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+R, C", nullptr));
#endif // QT_NO_SHORTCUT
        insertChildAction->setText(QApplication::translate("MainWindow", "Insert Child", nullptr));
#ifndef QT_NO_SHORTCUT
        insertChildAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionAjouter_un_joueur->setText(QApplication::translate("MainWindow", "Ajouter un joueur", nullptr));
        actionCr_er_une_quipe->setText(QApplication::translate("MainWindow", "Cr\303\251er une \303\251quipe", nullptr));
        actionCr_er_un_tournoi->setText(QApplication::translate("MainWindow", "Cr\303\251er un tournoi", nullptr));
        label->setText(QApplication::translate("MainWindow", "Recherche :", nullptr));
        fileMenu->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        actionsMenu->setTitle(QApplication::translate("MainWindow", "&Actions", nullptr));
        menuInscription->setTitle(QApplication::translate("MainWindow", "Inscription", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
