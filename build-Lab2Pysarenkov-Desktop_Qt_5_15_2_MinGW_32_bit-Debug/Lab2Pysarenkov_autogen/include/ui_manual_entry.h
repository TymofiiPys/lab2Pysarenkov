/********************************************************************************
** Form generated from reading UI file 'manual_entry.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUAL_ENTRY_H
#define UI_MANUAL_ENTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Manual_Entry
{
public:
    QPlainTextEdit *StructEdit;
    QLabel *label_info;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Btn_ex1;
    QPushButton *Btn_ex2;
    QPushButton *Btn_ex3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Btn_enter;
    QPushButton *Btn_cancel;

    void setupUi(QDialog *Manual_Entry)
    {
        if (Manual_Entry->objectName().isEmpty())
            Manual_Entry->setObjectName(QString::fromUtf8("Manual_Entry"));
        Manual_Entry->resize(750, 250);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Manual_Entry->sizePolicy().hasHeightForWidth());
        Manual_Entry->setSizePolicy(sizePolicy);
        Manual_Entry->setMinimumSize(QSize(750, 250));
        Manual_Entry->setMaximumSize(QSize(750, 250));
        StructEdit = new QPlainTextEdit(Manual_Entry);
        StructEdit->setObjectName(QString::fromUtf8("StructEdit"));
        StructEdit->setGeometry(QRect(10, 40, 601, 191));
        label_info = new QLabel(Manual_Entry);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(10, 0, 641, 41));
        layoutWidget = new QWidget(Manual_Entry);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(620, 50, 121, 103));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Btn_ex1 = new QPushButton(layoutWidget);
        Btn_ex1->setObjectName(QString::fromUtf8("Btn_ex1"));

        verticalLayout->addWidget(Btn_ex1);

        Btn_ex2 = new QPushButton(layoutWidget);
        Btn_ex2->setObjectName(QString::fromUtf8("Btn_ex2"));

        verticalLayout->addWidget(Btn_ex2);

        Btn_ex3 = new QPushButton(layoutWidget);
        Btn_ex3->setObjectName(QString::fromUtf8("Btn_ex3"));

        verticalLayout->addWidget(Btn_ex3);

        layoutWidget1 = new QWidget(Manual_Entry);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(620, 170, 121, 67));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Btn_enter = new QPushButton(layoutWidget1);
        Btn_enter->setObjectName(QString::fromUtf8("Btn_enter"));

        verticalLayout_2->addWidget(Btn_enter);

        Btn_cancel = new QPushButton(layoutWidget1);
        Btn_cancel->setObjectName(QString::fromUtf8("Btn_cancel"));

        verticalLayout_2->addWidget(Btn_cancel);


        retranslateUi(Manual_Entry);

        QMetaObject::connectSlotsByName(Manual_Entry);
    } // setupUi

    void retranslateUi(QDialog *Manual_Entry)
    {
        Manual_Entry->setWindowTitle(QCoreApplication::translate("Manual_Entry", "\320\222\320\262\320\265\320\264\320\265\320\275\320\275\321\217 \320\262\321\200\321\203\321\207\320\275\321\203", nullptr));
        label_info->setText(QCoreApplication::translate("Manual_Entry", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \321\201\321\202\321\200\321\203\320\272\321\202\321\203\321\200\321\203 \320\276\320\264\320\275\320\270\320\274 \321\200\321\217\320\264\320\272\320\276\320\274, \321\200\320\276\320\267\320\264\321\226\320\273\321\217\321\216\321\207\320\270 \321\207\320\270\321\201\320\273\320\260 \321\207\320\265\321\200\320\265\320\267 \320\277\321\200\320\276\320\261\321\226\320\273.</p>\n"
"<p align=\"justify\" style=\" margin-top:0"
                        "px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\247\320\270\321\201\320\273\320\260 \321\226\320\267 \320\264\321\200\320\276\320\261\320\276\320\262\320\276\321\216 \321\207\320\260\321\201\321\202\320\270\320\275\320\276\321\216 \320\267\320\260\320\277\320\270\321\201\321\203\320\262\320\260\321\202\320\270 \321\226\320\267 <span style=\" text-decoration: underline;\">\320\272\321\200\320\260\320\277\320\272\320\276\321\216</span> \321\203 \321\217\320\272\320\276\321\201\321\202\321\226 \320\264\320\265\321\201\321\217\321\202\320\272\320\276\320\262\320\276\320\263\320\276 \321\200\320\276\320\267\320\264\321\226\320\273\321\216\320\262\320\260\321\207\320\260</p></body></html>", nullptr));
        Btn_ex1->setText(QCoreApplication::translate("Manual_Entry", "\320\237\321\200\320\270\320\272\320\273\320\260\320\264 1", nullptr));
        Btn_ex2->setText(QCoreApplication::translate("Manual_Entry", "\320\237\321\200\320\270\320\272\320\273\320\260\320\264 2", nullptr));
        Btn_ex3->setText(QCoreApplication::translate("Manual_Entry", "\320\237\321\200\320\270\320\272\320\273\320\260\320\264 3", nullptr));
        Btn_enter->setText(QCoreApplication::translate("Manual_Entry", "\320\222\320\262\320\265\321\201\321\202\320\270", nullptr));
        Btn_cancel->setText(QCoreApplication::translate("Manual_Entry", "\320\241\320\272\320\260\321\201\321\203\320\262\320\260\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Manual_Entry: public Ui_Manual_Entry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUAL_ENTRY_H
