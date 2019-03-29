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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *exitAction;
    QAction *removeRowAction;
    QAction *insertChildAction;
    QAction *actionAjouter_un_joueur;
    QAction *actionCr_er_une_quipe;
    QAction *actionCr_er_un_tournoi;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *LeftPart;
    QHBoxLayout *ResearchField;
    QLabel *label;
    QLineEdit *lineEdit;
    QTreeView *view;
    QStackedWidget *stackedWidget;
    QWidget *player;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *playerForm;
    QFormLayout *form;
    QLabel *userNameLabel;
    QLineEdit *userNameLineEdit;
    QLabel *heightLabel;
    QDoubleSpinBox *heightDoubleSpinBox;
    QLabel *weightLabel;
    QDoubleSpinBox *weightDoubleSpinBox;
    QLabel *mailLabel;
    QLineEdit *mailLineEdit;
    QLabel *ageLabel;
    QSpinBox *ageSpinBox;
    QPushButton *Valider;
    QWidget *tournament;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *tournamentForm;
    QFormLayout *form_2;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *numberOfTeamsLabel;
    QSpinBox *numberOfTeamsSpinBox;
    QLabel *numberOfRoundsLabel;
    QSpinBox *numberOfRoundsSpinBox;
    QLabel *sportLabel;
    QLineEdit *sportLineEdit;
    QPushButton *Valider_2;
    QWidget *tournamentTree;
    QGraphicsView *graphicsView;
    QWidget *sport;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *actionsMenu;
    QMenu *menuInscription;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(759, 468);
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        removeRowAction = new QAction(MainWindow);
        removeRowAction->setObjectName(QString::fromUtf8("removeRowAction"));
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
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LeftPart = new QVBoxLayout();
        LeftPart->setObjectName(QString::fromUtf8("LeftPart"));
        ResearchField = new QHBoxLayout();
        ResearchField->setObjectName(QString::fromUtf8("ResearchField"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        ResearchField->addWidget(label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        ResearchField->addWidget(lineEdit);


        LeftPart->addLayout(ResearchField);

        view = new QTreeView(centralwidget);
        view->setObjectName(QString::fromUtf8("view"));
        view->setAlternatingRowColors(true);
        view->setSelectionBehavior(QAbstractItemView::SelectItems);
        view->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        view->setAnimated(false);
        view->setAllColumnsShowFocus(true);

        LeftPart->addWidget(view);


        horizontalLayout_2->addLayout(LeftPart);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        player = new QWidget();
        player->setObjectName(QString::fromUtf8("player"));
        verticalLayoutWidget_2 = new QWidget(player);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(2, 6, 361, 381));
        playerForm = new QVBoxLayout(verticalLayoutWidget_2);
        playerForm->setObjectName(QString::fromUtf8("playerForm"));
        playerForm->setContentsMargins(0, 0, 0, 0);
        form = new QFormLayout();
        form->setObjectName(QString::fromUtf8("form"));
        userNameLabel = new QLabel(verticalLayoutWidget_2);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));

        form->setWidget(0, QFormLayout::LabelRole, userNameLabel);

        userNameLineEdit = new QLineEdit(verticalLayoutWidget_2);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));

        form->setWidget(0, QFormLayout::FieldRole, userNameLineEdit);

        heightLabel = new QLabel(verticalLayoutWidget_2);
        heightLabel->setObjectName(QString::fromUtf8("heightLabel"));

        form->setWidget(1, QFormLayout::LabelRole, heightLabel);

        heightDoubleSpinBox = new QDoubleSpinBox(verticalLayoutWidget_2);
        heightDoubleSpinBox->setObjectName(QString::fromUtf8("heightDoubleSpinBox"));

        form->setWidget(1, QFormLayout::FieldRole, heightDoubleSpinBox);

        weightLabel = new QLabel(verticalLayoutWidget_2);
        weightLabel->setObjectName(QString::fromUtf8("weightLabel"));

        form->setWidget(2, QFormLayout::LabelRole, weightLabel);

        weightDoubleSpinBox = new QDoubleSpinBox(verticalLayoutWidget_2);
        weightDoubleSpinBox->setObjectName(QString::fromUtf8("weightDoubleSpinBox"));

        form->setWidget(2, QFormLayout::FieldRole, weightDoubleSpinBox);

        mailLabel = new QLabel(verticalLayoutWidget_2);
        mailLabel->setObjectName(QString::fromUtf8("mailLabel"));

        form->setWidget(3, QFormLayout::LabelRole, mailLabel);

        mailLineEdit = new QLineEdit(verticalLayoutWidget_2);
        mailLineEdit->setObjectName(QString::fromUtf8("mailLineEdit"));

        form->setWidget(3, QFormLayout::FieldRole, mailLineEdit);

        ageLabel = new QLabel(verticalLayoutWidget_2);
        ageLabel->setObjectName(QString::fromUtf8("ageLabel"));

        form->setWidget(4, QFormLayout::LabelRole, ageLabel);

        ageSpinBox = new QSpinBox(verticalLayoutWidget_2);
        ageSpinBox->setObjectName(QString::fromUtf8("ageSpinBox"));

        form->setWidget(4, QFormLayout::FieldRole, ageSpinBox);


        playerForm->addLayout(form);

        Valider = new QPushButton(verticalLayoutWidget_2);
        Valider->setObjectName(QString::fromUtf8("Valider"));

        playerForm->addWidget(Valider);

        stackedWidget->addWidget(player);
        tournament = new QWidget();
        tournament->setObjectName(QString::fromUtf8("tournament"));
        verticalLayoutWidget_3 = new QWidget(tournament);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 30, 351, 361));
        tournamentForm = new QVBoxLayout(verticalLayoutWidget_3);
        tournamentForm->setObjectName(QString::fromUtf8("tournamentForm"));
        tournamentForm->setContentsMargins(0, 0, 0, 0);
        form_2 = new QFormLayout();
        form_2->setObjectName(QString::fromUtf8("form_2"));
        nameLabel = new QLabel(verticalLayoutWidget_3);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        form_2->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(verticalLayoutWidget_3);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        form_2->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        numberOfTeamsLabel = new QLabel(verticalLayoutWidget_3);
        numberOfTeamsLabel->setObjectName(QString::fromUtf8("numberOfTeamsLabel"));

        form_2->setWidget(1, QFormLayout::LabelRole, numberOfTeamsLabel);

        numberOfTeamsSpinBox = new QSpinBox(verticalLayoutWidget_3);
        numberOfTeamsSpinBox->setObjectName(QString::fromUtf8("numberOfTeamsSpinBox"));

        form_2->setWidget(1, QFormLayout::FieldRole, numberOfTeamsSpinBox);

        numberOfRoundsLabel = new QLabel(verticalLayoutWidget_3);
        numberOfRoundsLabel->setObjectName(QString::fromUtf8("numberOfRoundsLabel"));

        form_2->setWidget(2, QFormLayout::LabelRole, numberOfRoundsLabel);

        numberOfRoundsSpinBox = new QSpinBox(verticalLayoutWidget_3);
        numberOfRoundsSpinBox->setObjectName(QString::fromUtf8("numberOfRoundsSpinBox"));

        form_2->setWidget(2, QFormLayout::FieldRole, numberOfRoundsSpinBox);

        sportLabel = new QLabel(verticalLayoutWidget_3);
        sportLabel->setObjectName(QString::fromUtf8("sportLabel"));

        form_2->setWidget(3, QFormLayout::LabelRole, sportLabel);

        sportLineEdit = new QLineEdit(verticalLayoutWidget_3);
        sportLineEdit->setObjectName(QString::fromUtf8("sportLineEdit"));

        form_2->setWidget(3, QFormLayout::FieldRole, sportLineEdit);


        tournamentForm->addLayout(form_2);

        Valider_2 = new QPushButton(verticalLayoutWidget_3);
        Valider_2->setObjectName(QString::fromUtf8("Valider_2"));

        tournamentForm->addWidget(Valider_2);

        stackedWidget->addWidget(tournament);
        tournamentTree = new QWidget();
        tournamentTree->setObjectName(QString::fromUtf8("tournamentTree"));
        graphicsView = new QGraphicsView(tournamentTree);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(5, 31, 351, 361));
        stackedWidget->addWidget(tournamentTree);
        sport = new QWidget();
        sport->setObjectName(QString::fromUtf8("sport"));
        stackedWidget->addWidget(sport);

        horizontalLayout_2->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 759, 26));
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
        actionsMenu->addSeparator();
        actionsMenu->addAction(removeRowAction);
        actionsMenu->addSeparator();
        actionsMenu->addAction(insertChildAction);
        menuInscription->addAction(actionAjouter_un_joueur);
        menuInscription->addAction(actionCr_er_une_quipe);
        menuInscription->addAction(actionCr_er_un_tournoi);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Editable Tree Model", nullptr));
        exitAction->setText(QApplication::translate("MainWindow", "E&xit", nullptr));
#ifndef QT_NO_SHORTCUT
        exitAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        removeRowAction->setText(QApplication::translate("MainWindow", "Remove Row", nullptr));
#ifndef QT_NO_SHORTCUT
        removeRowAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+R, R", nullptr));
#endif // QT_NO_SHORTCUT
        insertChildAction->setText(QApplication::translate("MainWindow", "Insert Child", nullptr));
#ifndef QT_NO_SHORTCUT
        insertChildAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionAjouter_un_joueur->setText(QApplication::translate("MainWindow", "Ajouter un joueur", nullptr));
        actionCr_er_une_quipe->setText(QApplication::translate("MainWindow", "Cr\303\251er une \303\251quipe", nullptr));
        actionCr_er_un_tournoi->setText(QApplication::translate("MainWindow", "Cr\303\251er un tournoi", nullptr));
        label->setText(QApplication::translate("MainWindow", "Recherche :", nullptr));
        userNameLabel->setText(QApplication::translate("MainWindow", "UserName", nullptr));
        heightLabel->setText(QApplication::translate("MainWindow", "Height (m)", nullptr));
        weightLabel->setText(QApplication::translate("MainWindow", "Weight (kg)", nullptr));
        mailLabel->setText(QApplication::translate("MainWindow", "Mail", nullptr));
        ageLabel->setText(QApplication::translate("MainWindow", "Age", nullptr));
        Valider->setText(QApplication::translate("MainWindow", "Send", nullptr));
        nameLabel->setText(QApplication::translate("MainWindow", "Name", nullptr));
        numberOfTeamsLabel->setText(QApplication::translate("MainWindow", "Number of teams", nullptr));
        numberOfRoundsLabel->setText(QApplication::translate("MainWindow", "Number of rounds", nullptr));
        sportLabel->setText(QApplication::translate("MainWindow", "Sport", nullptr));
        Valider_2->setText(QApplication::translate("MainWindow", "Send", nullptr));
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
