/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_exit;
    QAction *action_start_auto;
    QAction *action_pause;
    QAction *action_stop;
    QAction *action_manual;
    QAction *action_prev_step;
    QAction *action_next_step;
    QAction *action_reset;
    QWidget *centralwidget;
    QGraphicsView *graphicsView_demo;
    QGroupBox *groupBox_algs;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_alg;
    QComboBox *comboBox;
    QGroupBox *groupBox_str;
    QRadioButton *radioButton_rnd;
    QGroupBox *groupBox_rnd;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_amt;
    QLineEdit *lineEdit_amt;
    QLabel *label_interv;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_min;
    QLineEdit *lineEdit_min;
    QLabel *label_max;
    QLineEdit *lineEdit_max;
    QPushButton *pushButton_rnd;
    QRadioButton *radioButton_file;
    QPushButton *pushButton_file;
    QRadioButton *radioButton_man;
    QPushButton *pushButton_man;
    QPushButton *pushButton_draw;
    QLabel *label_str_entered;
    QGraphicsView *graphicsView_struct;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_tim;
    QPushButton *pushButton_1;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu_demo;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1020, 623);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1020, 623));
        MainWindow->setMaximumSize(QSize(1020, 623));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_start_auto = new QAction(MainWindow);
        action_start_auto->setObjectName(QString::fromUtf8("action_start_auto"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_start_auto->setIcon(icon);
        action_pause = new QAction(MainWindow);
        action_pause->setObjectName(QString::fromUtf8("action_pause"));
        action_pause->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_pause->setIcon(icon1);
        action_stop = new QAction(MainWindow);
        action_stop->setObjectName(QString::fromUtf8("action_stop"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_stop->setIcon(icon2);
        action_manual = new QAction(MainWindow);
        action_manual->setObjectName(QString::fromUtf8("action_manual"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/img/start_m.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_manual->setIcon(icon3);
        action_prev_step = new QAction(MainWindow);
        action_prev_step->setObjectName(QString::fromUtf8("action_prev_step"));
        action_prev_step->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_prev_step->setIcon(icon4);
        action_next_step = new QAction(MainWindow);
        action_next_step->setObjectName(QString::fromUtf8("action_next_step"));
        action_next_step->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/img/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_next_step->setIcon(icon5);
        action_reset = new QAction(MainWindow);
        action_reset->setObjectName(QString::fromUtf8("action_reset"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        graphicsView_demo = new QGraphicsView(centralwidget);
        graphicsView_demo->setObjectName(QString::fromUtf8("graphicsView_demo"));
        graphicsView_demo->setGeometry(QRect(390, 210, 620, 320));
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        graphicsView_demo->setBackgroundBrush(brush);
        graphicsView_demo->setAlignment(Qt::AlignCenter);
        groupBox_algs = new QGroupBox(centralwidget);
        groupBox_algs->setObjectName(QString::fromUtf8("groupBox_algs"));
        groupBox_algs->setGeometry(QRect(10, 10, 341, 81));
        layoutWidget = new QWidget(groupBox_algs);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 301, 57));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_alg = new QLabel(layoutWidget);
        label_alg->setObjectName(QString::fromUtf8("label_alg"));

        verticalLayout->addWidget(label_alg);

        comboBox = new QComboBox(layoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        groupBox_str = new QGroupBox(centralwidget);
        groupBox_str->setObjectName(QString::fromUtf8("groupBox_str"));
        groupBox_str->setGeometry(QRect(10, 90, 341, 331));
        radioButton_rnd = new QRadioButton(groupBox_str);
        radioButton_rnd->setObjectName(QString::fromUtf8("radioButton_rnd"));
        radioButton_rnd->setGeometry(QRect(10, 30, 311, 24));
        groupBox_rnd = new QGroupBox(groupBox_str);
        groupBox_rnd->setObjectName(QString::fromUtf8("groupBox_rnd"));
        groupBox_rnd->setEnabled(false);
        groupBox_rnd->setGeometry(QRect(10, 60, 321, 141));
        layoutWidget1 = new QWidget(groupBox_rnd);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 11, 301, 96));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_amt = new QLabel(layoutWidget1);
        label_amt->setObjectName(QString::fromUtf8("label_amt"));

        horizontalLayout->addWidget(label_amt);

        lineEdit_amt = new QLineEdit(layoutWidget1);
        lineEdit_amt->setObjectName(QString::fromUtf8("lineEdit_amt"));

        horizontalLayout->addWidget(lineEdit_amt);


        verticalLayout_2->addLayout(horizontalLayout);

        label_interv = new QLabel(layoutWidget1);
        label_interv->setObjectName(QString::fromUtf8("label_interv"));

        verticalLayout_2->addWidget(label_interv);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_min = new QLabel(layoutWidget1);
        label_min->setObjectName(QString::fromUtf8("label_min"));

        horizontalLayout_2->addWidget(label_min);

        lineEdit_min = new QLineEdit(layoutWidget1);
        lineEdit_min->setObjectName(QString::fromUtf8("lineEdit_min"));

        horizontalLayout_2->addWidget(lineEdit_min);

        label_max = new QLabel(layoutWidget1);
        label_max->setObjectName(QString::fromUtf8("label_max"));

        horizontalLayout_2->addWidget(label_max);

        lineEdit_max = new QLineEdit(layoutWidget1);
        lineEdit_max->setObjectName(QString::fromUtf8("lineEdit_max"));

        horizontalLayout_2->addWidget(lineEdit_max);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton_rnd = new QPushButton(groupBox_rnd);
        pushButton_rnd->setObjectName(QString::fromUtf8("pushButton_rnd"));
        pushButton_rnd->setGeometry(QRect(170, 110, 141, 25));
        radioButton_file = new QRadioButton(groupBox_str);
        radioButton_file->setObjectName(QString::fromUtf8("radioButton_file"));
        radioButton_file->setGeometry(QRect(11, 212, 161, 24));
        pushButton_file = new QPushButton(groupBox_str);
        pushButton_file->setObjectName(QString::fromUtf8("pushButton_file"));
        pushButton_file->setEnabled(false);
        pushButton_file->setGeometry(QRect(200, 210, 131, 29));
        radioButton_man = new QRadioButton(groupBox_str);
        radioButton_man->setObjectName(QString::fromUtf8("radioButton_man"));
        radioButton_man->setGeometry(QRect(12, 252, 171, 24));
        pushButton_man = new QPushButton(groupBox_str);
        pushButton_man->setObjectName(QString::fromUtf8("pushButton_man"));
        pushButton_man->setEnabled(false);
        pushButton_man->setGeometry(QRect(200, 250, 131, 29));
        pushButton_draw = new QPushButton(groupBox_str);
        pushButton_draw->setObjectName(QString::fromUtf8("pushButton_draw"));
        pushButton_draw->setEnabled(false);
        pushButton_draw->setGeometry(QRect(200, 290, 131, 29));
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        pushButton_draw->setFont(font);
        label_str_entered = new QLabel(centralwidget);
        label_str_entered->setObjectName(QString::fromUtf8("label_str_entered"));
        label_str_entered->setGeometry(QRect(10, 470, 331, 20));
        graphicsView_struct = new QGraphicsView(centralwidget);
        graphicsView_struct->setObjectName(QString::fromUtf8("graphicsView_struct"));
        graphicsView_struct->setGeometry(QRect(390, 40, 621, 141));
        graphicsView_struct->setAutoFillBackground(false);
        graphicsView_struct->setBackgroundBrush(brush);
        graphicsView_struct->setSceneRect(QRectF(0, 0, 0, 0));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(390, 190, 211, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(390, 20, 91, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(13, 435, 197, 20));
        lineEdit_tim = new QLineEdit(centralwidget);
        lineEdit_tim->setObjectName(QString::fromUtf8("lineEdit_tim"));
        lineEdit_tim->setGeometry(QRect(217, 432, 48, 28));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(272, 432, 80, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1020, 17));
        menu_file = new QMenu(menubar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_demo = new QMenu(menubar);
        menu_demo->setObjectName(QString::fromUtf8("menu_demo"));
        menu_3 = new QMenu(menu_demo);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menu_demo);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu_demo->menuAction());
        menu_file->addSeparator();
        menu_file->addAction(action_reset);
        menu_file->addAction(action_exit);
        menu_demo->addAction(menu_3->menuAction());
        menu_demo->addSeparator();
        menu_demo->addAction(menu_4->menuAction());
        menu_demo->addSeparator();
        menu_demo->addAction(action_start_auto);
        menu_demo->addAction(action_pause);
        menu_demo->addSeparator();
        menu_demo->addAction(action_manual);
        menu_demo->addAction(action_prev_step);
        menu_demo->addAction(action_next_step);
        menu_demo->addSeparator();
        menu_demo->addAction(action_stop);
        menu_4->addSeparator();
        toolBar->addAction(action_start_auto);
        toolBar->addAction(action_pause);
        toolBar->addSeparator();
        toolBar->addAction(action_manual);
        toolBar->addAction(action_prev_step);
        toolBar->addAction(action_next_step);
        toolBar->addSeparator();
        toolBar->addAction(action_stop);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\274\320\276\320\275\321\201\321\202\321\200\320\260\321\206\321\226\321\217 \321\200\320\276\320\261\320\276\321\202\320\270 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\321\226\320\262", nullptr));
        action_exit->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\271\321\202\320\270", nullptr));
#if QT_CONFIG(tooltip)
        action_exit->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\271\321\202\320\270 \321\226\320\267 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\270", nullptr));
#endif // QT_CONFIG(tooltip)
        action_start_auto->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202 (\320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\275\320\276)", nullptr));
        action_pause->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\203\320\267\320\260/\320\277\321\200\320\276\320\264\320\276\320\262\320\266\320\270\321\202\320\270", nullptr));
        action_stop->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", nullptr));
        action_manual->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202 (\320\262\321\200\321\203\321\207\320\275\321\203)", nullptr));
        action_prev_step->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\277\320\265\321\200\320\265\320\264\320\275\321\226\320\271 \320\272\321\200\320\276\320\272", nullptr));
        action_next_step->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\203\320\277\320\275\320\270\320\271 \320\272\321\200\320\276\320\272", nullptr));
        action_reset->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\270\320\275\321\203\321\202\320\270 \320\262\321\201\320\265", nullptr));
#if QT_CONFIG(tooltip)
        graphicsView_demo->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\242\321\203\321\202 \321\203 \320\262\320\270\320\263\320\273\321\217\320\264\321\226 \320\264\321\226\320\260\320\263\321\200\320\260\320\274\320\270 \320\264\320\265\320\274\320\276\320\275\321\201\321\202\321\200\321\203\321\216\321\202\321\214\321\201\321\217 \320\265\320\273\320\265\320\274\320\265\320\275\321\202\320\270 \321\201\321\202\321\200\321\203\320\272\321\202\321\203\321\200\320\270</p><p>\320\262 \320\277\321\200\320\276\321\206\320\265\321\201\321\226 \320\262\320\270\320\272\320\276\320\275\320\260\320\275\320\275\321\217 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\321\203, \320\264\320\265 \321\227\321\205\320\275\321\217 \320\262\320\270\321\201\320\276\321\202\320\260 \320\277\321\200\320\276\320\277\320\276\321\200\321\206\321\226\320\271\320\275\320\260 \320\262\320\265\320\273\320\270\321\207\320\270\320\275\321\226, \321\211\320\276 \320\267\320\261\320\265\321\200\321\226\320\263\320\260\321\224 \320\265\320\273\320\265\320\274\320\265\320"
                        "\275\321\202.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_algs->setTitle(QString());
        label_alg->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274, \321\211\320\276 \320\261\321\203\320\264\320\265 \320\264\320\265\320\274\320\276\320\275\321\201\321\202\321\200\321\203\320\262\320\260\321\202\320\270\321\201\321\214", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "<\320\276\320\261\320\265\321\200\321\226\321\202\321\214 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274>", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Bubble Sort", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Selection Sort", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Insertion Sort", nullptr));

        groupBox_str->setTitle(QCoreApplication::translate("MainWindow", "\320\241\321\202\321\200\321\203\320\272\321\202\321\203\321\200\320\260", nullptr));
        radioButton_rnd->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\277\320\260\320\264\320\272\320\276\320\262\320\260 \320\263\320\265\320\275\320\265\321\200\320\260\321\206\321\226\321\217", nullptr));
        groupBox_rnd->setTitle(QString());
        label_amt->setText(QCoreApplication::translate("MainWindow", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214 \320\265\320\273\320\265\320\274\320\265\320\275\321\202\321\226\320\262", nullptr));
        label_interv->setText(QCoreApplication::translate("MainWindow", "\320\206\320\275\321\202\320\265\321\200\320\262\320\260\320\273\320\270:", nullptr));
        label_min->setText(QCoreApplication::translate("MainWindow", "\320\234\321\226\320\275.", nullptr));
        label_max->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201.", nullptr));
        pushButton_rnd->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\201\321\202\320\270", nullptr));
        radioButton_file->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\265\320\275\320\275\321\217 \321\226\320\267 \321\204\320\260\320\271\320\273\321\203", nullptr));
        pushButton_file->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\321\202\320\270 \321\204\320\260\320\271\320\273", nullptr));
        radioButton_man->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\265\320\275\320\275\321\217 \320\262\321\200\321\203\321\207\320\275\321\203", nullptr));
        pushButton_man->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\201\321\202\320\270", nullptr));
        pushButton_draw->setText(QCoreApplication::translate("MainWindow", "\320\222\321\226\320\264\320\276\320\261\321\200\320\260\320\267\320\270\321\202\320\270 \321\200\320\270\321\201\321\203\320\275\320\276\320\272", nullptr));
        label_str_entered->setText(QString());
#if QT_CONFIG(tooltip)
        graphicsView_struct->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\241\321\202\321\200\321\203\320\272\321\202\321\203\321\200\320\260</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\274\320\276\320\275\321\201\321\202\321\200\320\260\321\206\321\226\321\217 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\321\203", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\321\200\321\203\320\272\321\202\321\203\321\200\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\206\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\274\321\226\320\266 \320\272\321\200\320\276\320\272\320\260\320\274\320\270 (\320\274\321\201):  ", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_tim->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \321\226\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\274\321\226\320\266 \320\272\321\200\320\276\320\272\320\260\320\274\320\270 \320\277\321\200\320\270 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\275\321\226\320\271 \320\264\320\265\320\274\320\276\320\275\321\201\321\202\321\200\320\260\321\206\321\226\321\227 (\320\275\320\265 \321\200\320\265\320\272\320\276\320\274\320\265\320\275\320\264\321\203\321\224\321\202\321\214\321\201\321\217\n"
"\320\262\320\262\320\276\320\264\320\270\321\202\320\270 \320\267\320\275\320\260\321\207\320\265\320\275\320\275\321\217, \320\274\320\265\320\275\321\210\321\226 \320\267\320\260 5 \320\274\321\201 - \320\263\321\200\320\260\321\204\321\226\321\207\320\275\320\260 \321\201\320\272\320\273\320\260\320\264\320\276\320\262\320\260 \320\262\320\270\320\263\320\273\321\217\320\264\320\260\321\202\320\270\320\274\320\265 \320\275\320\265\320\275\320\260\320\271\320\272"
                        "\321\200\320\260\321\211\320\265)", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\201\321\202\320\270", nullptr));
        menu_file->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_demo->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\274\320\276\320\275\321\201\321\202\321\200\320\260\321\206\321\226\321\217", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\270", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\320\206\321\201\321\202\320\276\321\200\321\226\321\217", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
