/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Quitter;
    QAction *actionFullscreen;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinNbRow;
    QLabel *cycleLabel;
    QLabel *fpsLabel;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menu_Fichier;
    QMenu *menuWindow;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(893, 751);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setBaseSize(QSize(893, 751));
        action_Quitter = new QAction(MainWindow);
        action_Quitter->setObjectName(QStringLiteral("action_Quitter"));
        actionFullscreen = new QAction(MainWindow);
        actionFullscreen->setObjectName(QStringLiteral("actionFullscreen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setFrameShape(QFrame::StyledPanel);
        splitter->setFrameShadow(QFrame::Sunken);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(true);
        splitter->setChildrenCollapsible(false);
        frame = new QFrame(splitter);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(150, 0));
        frame->setMaximumSize(QSize(250, 16777215));
        frame->setBaseSize(QSize(150, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        startButton = new QPushButton(frame);
        startButton->setObjectName(QStringLiteral("startButton"));

        verticalLayout->addWidget(startButton, 0, Qt::AlignTop);

        stopButton = new QPushButton(frame);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setEnabled(false);

        verticalLayout->addWidget(stopButton, 0, Qt::AlignTop);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_2->addWidget(label, 0, Qt::AlignTop);

        spinNbRow = new QSpinBox(frame);
        spinNbRow->setObjectName(QStringLiteral("spinNbRow"));
        spinNbRow->setMaximumSize(QSize(16777215, 26));
        spinNbRow->setMinimum(1);
        spinNbRow->setMaximum(2000);

        horizontalLayout_2->addWidget(spinNbRow, 0, Qt::AlignTop);


        verticalLayout->addLayout(horizontalLayout_2);

        cycleLabel = new QLabel(frame);
        cycleLabel->setObjectName(QStringLiteral("cycleLabel"));
        cycleLabel->setMaximumSize(QSize(16777215, 60));

        verticalLayout->addWidget(cycleLabel);

        fpsLabel = new QLabel(frame);
        fpsLabel->setObjectName(QStringLiteral("fpsLabel"));
        fpsLabel->setMaximumSize(QSize(16777215, 60));

        verticalLayout->addWidget(fpsLabel, 0, Qt::AlignBottom);

        splitter->addWidget(frame);
        graphicsView = new QGraphicsView(splitter);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(623, 0));
        graphicsView->setBaseSize(QSize(623, 0));
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);
        graphicsView->setCacheMode(QGraphicsView::CacheBackground);
        graphicsView->setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing|QGraphicsView::DontClipPainter|QGraphicsView::DontSavePainterState|QGraphicsView::IndirectPainting);
        splitter->addWidget(graphicsView);

        horizontalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 893, 21));
        menu_Fichier = new QMenu(menuBar);
        menu_Fichier->setObjectName(QStringLiteral("menu_Fichier"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_Fichier->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menu_Fichier->addAction(action_Quitter);
        menuWindow->addAction(actionFullscreen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_Quitter->setText(QApplication::translate("MainWindow", "&Quitter", 0));
        action_Quitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionFullscreen->setText(QApplication::translate("MainWindow", "&Fullscreen", 0));
        actionFullscreen->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0));
        startButton->setText(QApplication::translate("MainWindow", "START", 0));
        stopButton->setText(QApplication::translate("MainWindow", "STOP", 0));
        label->setText(QApplication::translate("MainWindow", "Colonnes:", 0));
        cycleLabel->setText(QApplication::translate("MainWindow", "Cycle: 0", 0));
        fpsLabel->setText(QApplication::translate("MainWindow", "FPS: 0", 0));
        menu_Fichier->setTitle(QApplication::translate("MainWindow", "&Fichier", 0));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
