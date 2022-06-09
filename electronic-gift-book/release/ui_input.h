/********************************************************************************
** Form generated from reading UI file 'input.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_H
#define UI_INPUT_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Input
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QPushButton *btn_in_2;
    QPushButton *btn_in;
    QPushButton *cancel;
    QPushButton *btn_in_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QDateEdit *dateEdit;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Input)
    {
        if (Input->objectName().isEmpty())
            Input->setObjectName(QString::fromUtf8("Input"));
        Input->resize(579, 241);
        Input->setMinimumSize(QSize(20, 0));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(240, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush3(QColor(206, 240, 229, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        QBrush brush4(QColor(196, 210, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush4);
        QBrush brush5(QColor(255, 0, 0, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        QBrush brush6(QColor(120, 120, 120, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        QBrush brush7(QColor(51, 153, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        QBrush brush8(QColor(0, 0, 0, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        Input->setPalette(palette);
        gridLayout_3 = new QGridLayout(Input);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btn_in_2 = new QPushButton(Input);
        btn_in_2->setObjectName(QString::fromUtf8("btn_in_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_in_2->sizePolicy().hasHeightForWidth());
        btn_in_2->setSizePolicy(sizePolicy);
        btn_in_2->setMinimumSize(QSize(0, 30));
        btn_in_2->setMaximumSize(QSize(100, 16777215));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        btn_in_2->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        btn_in_2->setFont(font);

        gridLayout_2->addWidget(btn_in_2, 1, 1, 1, 1);

        btn_in = new QPushButton(Input);
        btn_in->setObjectName(QString::fromUtf8("btn_in"));
        sizePolicy.setHeightForWidth(btn_in->sizePolicy().hasHeightForWidth());
        btn_in->setSizePolicy(sizePolicy);
        btn_in->setMinimumSize(QSize(0, 30));
        btn_in->setMaximumSize(QSize(100, 16777215));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        btn_in->setPalette(palette2);
        btn_in->setFont(font);

        gridLayout_2->addWidget(btn_in, 1, 2, 1, 1);

        cancel = new QPushButton(Input);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        sizePolicy.setHeightForWidth(cancel->sizePolicy().hasHeightForWidth());
        cancel->setSizePolicy(sizePolicy);
        cancel->setMinimumSize(QSize(0, 30));
        cancel->setMaximumSize(QSize(100, 16777215));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        cancel->setPalette(palette3);
        cancel->setFont(font);

        gridLayout_2->addWidget(cancel, 1, 3, 1, 1);

        btn_in_3 = new QPushButton(Input);
        btn_in_3->setObjectName(QString::fromUtf8("btn_in_3"));
        sizePolicy.setHeightForWidth(btn_in_3->sizePolicy().hasHeightForWidth());
        btn_in_3->setSizePolicy(sizePolicy);
        btn_in_3->setMinimumSize(QSize(0, 30));
        btn_in_3->setMaximumSize(QSize(100, 16777215));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        btn_in_3->setPalette(palette4);
        btn_in_3->setFont(font);

        gridLayout_2->addWidget(btn_in_3, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(Input);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(18);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(Input);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(Input);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(Input);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(0, 25));
        comboBox->setMaximumSize(QSize(150, 25));
        comboBox->setFont(font);

        gridLayout->addWidget(comboBox, 2, 1, 1, 1);

        label_4 = new QLabel(Input);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit = new QLineEdit(Input);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setMaximumSize(QSize(16777215, 50));
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        lineEdit_2 = new QLineEdit(Input);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy2);
        lineEdit_2->setMinimumSize(QSize(0, 30));
        lineEdit_2->setMaximumSize(QSize(16777215, 50));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush9(QColor(255, 0, 127, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush9);
        QBrush brush10(QColor(255, 0, 0, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush9);
        QBrush brush11(QColor(255, 0, 0, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush9);
        QBrush brush12(QColor(255, 0, 0, 128));
        brush12.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        lineEdit_2->setPalette(palette5);
        lineEdit_2->setFont(font);

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        dateEdit = new QDateEdit(Input);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setFont(font);
        dateEdit->setDate(QDate(2021, 10, 19));

        gridLayout->addWidget(dateEdit, 3, 1, 1, 1);

        checkBox = new QCheckBox(Input);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font);

        gridLayout->addWidget(checkBox, 3, 2, 1, 1);

        checkBox_2 = new QCheckBox(Input);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setFont(font);

        gridLayout->addWidget(checkBox_2, 2, 2, 1, 1);

        checkBox_3 = new QCheckBox(Input);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setFont(font);

        gridLayout->addWidget(checkBox_3, 1, 2, 1, 1);

        checkBox_4 = new QCheckBox(Input);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setFont(font);

        gridLayout->addWidget(checkBox_4, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(Input);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy3);
        textBrowser->setMaximumSize(QSize(100, 500));
        QPalette palette6;
        QBrush brush13(QColor(8, 8, 255, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush13);
        QBrush brush14(QColor(217, 223, 255, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush14);
        QBrush brush15(QColor(8, 8, 255, 128));
        brush15.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush15);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush13);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush14);
        QBrush brush16(QColor(8, 8, 255, 128));
        brush16.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush16);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush14);
        QBrush brush17(QColor(8, 8, 255, 128));
        brush17.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush17);
#endif
        textBrowser->setPalette(palette6);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        textBrowser->setFont(font2);

        verticalLayout->addWidget(textBrowser);


        gridLayout_2->addLayout(verticalLayout, 0, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(Input);

        QMetaObject::connectSlotsByName(Input);
    } // setupUi

    void retranslateUi(QWidget *Input)
    {
        Input->setWindowTitle(QCoreApplication::translate("Input", "Form", nullptr));
        btn_in_2->setText(QCoreApplication::translate("Input", "\344\277\256\346\224\271", nullptr));
        btn_in->setText(QCoreApplication::translate("Input", "\346\267\273\345\212\240", nullptr));
        cancel->setText(QCoreApplication::translate("Input", "\345\205\263\351\227\255", nullptr));
        btn_in_3->setText(QCoreApplication::translate("Input", "\346\237\245\350\257\242", nullptr));
        label_2->setText(QCoreApplication::translate("Input", "\351\207\221\351\242\235\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Input", "\346\267\273\345\212\240\347\261\273\345\236\213\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("Input", "\345\247\223\345\220\215\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Input", "\351\200\201\345\207\272", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Input", "\346\224\266\345\205\245", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Input", "\351\200\201\345\207\272\357\274\210\344\273\243\357\274\211", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Input", "\346\224\266\345\205\245\357\274\210\344\273\243\357\274\211", nullptr));

        label_4->setText(QCoreApplication::translate("Input", "\346\227\245\346\234\237\357\274\232", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("Input", "yyyy/MM/dd", nullptr));
        checkBox->setText(QCoreApplication::translate("Input", "\346\237\245\350\257\242\346\227\266\345\213\276\351\200\211", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Input", "\346\237\245\350\257\242\346\227\266\345\213\276\351\200\211", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Input", "\346\237\245\350\257\242\346\227\266\345\213\276\351\200\211", nullptr));
        checkBox_4->setText(QCoreApplication::translate("Input", "\346\237\245\350\257\242\346\227\266\345\213\276\351\200\211", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Input", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/QStringLiteral/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:12pt;\">\346\263\250\346\204\217\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:12pt;\">  \345\234\250\350\277\233\350\241\214\346\237\245\346\211\276\346\227\266\357\274\214\344\274\232\346\240\271\346\215\256\346\211\200\345\213\276\351\200\211\351\241\271\347\233\256\350\277\233\350\241\214\346\237\245\346\211\276;\350\213\245\344\270\215\345"
                        "\213\276\351\200\211\357\274\214\345\210\231\346\237\245\350\257\242\345\205\250\351\203\250</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Input: public Ui_Input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_H
