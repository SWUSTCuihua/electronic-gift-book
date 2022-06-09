/********************************************************************************
** Form generated from reading UI file 'total.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOTAL_H
#define UI_TOTAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Total
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_9;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_10;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLabel *label_11;
    QLabel *label_12;

    void setupUi(QWidget *Total)
    {
        if (Total->objectName().isEmpty())
            Total->setObjectName(QString::fromUtf8("Total"));
        Total->resize(509, 321);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(240, 199, 148, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Total->setPalette(palette);
        gridLayout_2 = new QGridLayout(Total);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(Total);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        label_8 = new QLabel(Total);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 3, 2, 1, 1);

        label_2 = new QLabel(Total);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_9 = new QLabel(Total);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        label_9->setFont(font1);

        gridLayout->addWidget(label_9, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(Total);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(0, 30));
        pushButton_2->setFont(font1);

        gridLayout->addWidget(pushButton_2, 5, 3, 1, 1);

        label = new QLabel(Total);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_6 = new QLabel(Total);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_7 = new QLabel(Total);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 2, 2, 1, 1);

        label_5 = new QLabel(Total);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_3 = new QLabel(Total);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_10 = new QLabel(Total);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);

        gridLayout->addWidget(label_10, 3, 1, 1, 1);

        pushButton_3 = new QPushButton(Total);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(0, 30));
        pushButton_3->setFont(font1);

        gridLayout->addWidget(pushButton_3, 4, 3, 1, 1);

        pushButton = new QPushButton(Total);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(0, 20));
        pushButton->setFont(font1);

        gridLayout->addWidget(pushButton, 5, 2, 1, 1);

        label_11 = new QLabel(Total);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);

        gridLayout->addWidget(label_11, 2, 3, 1, 1);

        label_12 = new QLabel(Total);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);

        gridLayout->addWidget(label_12, 3, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(Total);

        QMetaObject::connectSlotsByName(Total);
    } // setupUi

    void retranslateUi(QWidget *Total)
    {
        Total->setWindowTitle(QCoreApplication::translate("Total", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("Total", "100", nullptr));
        label_8->setText(QCoreApplication::translate("Total", "100", nullptr));
        label_2->setText(QCoreApplication::translate("Total", "\346\200\273\346\224\266\345\205\245\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("Total", "\345\274\240\344\270\211", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Total", "\345\205\263\351\227\255", nullptr));
        label->setText(QCoreApplication::translate("Total", "\346\200\273\351\200\201\345\207\272\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("Total", "\346\200\273\351\200\201\345\207\272\346\234\200\345\244\232\344\272\272\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("Total", "100", nullptr));
        label_5->setText(QCoreApplication::translate("Total", "\346\200\273\346\224\266\345\205\245\346\234\200\345\244\232\344\272\272\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Total", "100", nullptr));
        label_10->setText(QCoreApplication::translate("Total", "\346\235\216\345\233\233", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Total", "\346\233\264\346\226\260\346\225\260\346\215\256", nullptr));
        pushButton->setText(QCoreApplication::translate("Total", "\346\237\245\347\234\213\346\211\200\346\234\211", nullptr));
        label_11->setText(QCoreApplication::translate("Total", "TextLabel", nullptr));
        label_12->setText(QCoreApplication::translate("Total", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Total: public Ui_Total {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTAL_H
