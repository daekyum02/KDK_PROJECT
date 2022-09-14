/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *resetbot;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QPushButton *startbot;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *countnumber;
    QLineEdit *lineEdit;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *help;
    QLabel *label_8;
    QLineEdit *name;
    QLabel *scorelabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(985, 679);
        resetbot = new QPushButton(Widget);
        resetbot->setObjectName(QString::fromUtf8("resetbot"));
        resetbot->setGeometry(QRect(760, 160, 161, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka Heading Semibold")});
        font.setBold(true);
        resetbot->setFont(font);
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(760, 290, 160, 22));
        horizontalSlider->setMinimum(10);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(710, 200, 211, 91));
        startbot = new QPushButton(Widget);
        startbot->setObjectName(QString::fromUtf8("startbot"));
        startbot->setGeometry(QRect(760, 80, 161, 61));
        startbot->setFont(font);
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 70, 491, 491));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(710, 310, 151, 51));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(830, 230, 161, 31));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(700, 500, 251, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Swis721 BdCnOul BT")});
        font1.setPointSize(22);
        label_4->setFont(font1);
        countnumber = new QLabel(Widget);
        countnumber->setObjectName(QString::fromUtf8("countnumber"));
        countnumber->setGeometry(QRect(940, 510, 31, 31));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(890, 420, 91, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("VeriBest BC")});
        font2.setPointSize(24);
        lineEdit->setFont(font2);
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(700, 420, 181, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Technic")});
        font3.setPointSize(22);
        label_5->setFont(font3);
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(700, 470, 171, 51));
        label_6->setFont(font1);
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(840, 560, 221, 51));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Stylus BT")});
        font4.setPointSize(18);
        label_7->setFont(font4);
        help = new QPushButton(Widget);
        help->setObjectName(QString::fromUtf8("help"));
        help->setGeometry(QRect(760, 10, 161, 61));
        help->setFont(font);
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(700, 370, 181, 51));
        label_8->setFont(font3);
        name = new QLineEdit(Widget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(890, 370, 91, 41));
        name->setFont(font2);
        scorelabel = new QLabel(Widget);
        scorelabel->setObjectName(QString::fromUtf8("scorelabel"));
        scorelabel->setGeometry(QRect(467, 340, 181, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        resetbot->setText(QString());
        label_2->setText(QString());
        startbot->setText(QString());
        label->setText(QString());
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("Widget", "Regenerative Time :", nullptr));
        countnumber->setText(QString());
        lineEdit->setText(QString());
        label_5->setText(QCoreApplication::translate("Widget", "Target Score", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "Minus Food", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "Made by. Kim", nullptr));
        help->setText(QString());
        label_8->setText(QCoreApplication::translate("Widget", "User name :", nullptr));
        name->setText(QString());
        scorelabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
