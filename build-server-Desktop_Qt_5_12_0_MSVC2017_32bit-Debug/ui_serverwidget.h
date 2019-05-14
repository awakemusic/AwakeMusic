/********************************************************************************
** Form generated from reading UI file 'serverwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWIDGET_H
#define UI_SERVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *ServerWidget)
    {
        if (ServerWidget->objectName().isEmpty())
            ServerWidget->setObjectName(QString::fromUtf8("ServerWidget"));
        ServerWidget->resize(400, 300);
        label = new QLabel(ServerWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 0, 81, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(ServerWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 71, 54, 21));
        label_3 = new QLabel(ServerWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 90, 281, 41));
        label_3->setFont(font);

        retranslateUi(ServerWidget);

        QMetaObject::connectSlotsByName(ServerWidget);
    } // setupUi

    void retranslateUi(QWidget *ServerWidget)
    {
        ServerWidget->setWindowTitle(QApplication::translate("ServerWidget", "ServerWidget", nullptr));
        label->setText(QApplication::translate("ServerWidget", "\346\234\215\345\212\241\347\253\257", nullptr));
        label_2->setText(QApplication::translate("ServerWidget", "\350\277\236\346\216\245\344\277\241\346\201\257", nullptr));
        label_3->setText(QApplication::translate("ServerWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWidget: public Ui_ServerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWIDGET_H
