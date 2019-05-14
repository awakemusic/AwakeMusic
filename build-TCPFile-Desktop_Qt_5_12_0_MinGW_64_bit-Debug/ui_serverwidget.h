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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit;
    QPushButton *buttonFile;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonSend;

    void setupUi(QWidget *ServerWidget)
    {
        if (ServerWidget->objectName().isEmpty())
            ServerWidget->setObjectName(QString::fromUtf8("ServerWidget"));
        ServerWidget->resize(400, 300);
        gridLayout = new QGridLayout(ServerWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(130, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 2);

        label = new QLabel(ServerWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 2);

        textEdit = new QTextEdit(ServerWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 1, 0, 1, 5);

        buttonFile = new QPushButton(ServerWidget);
        buttonFile->setObjectName(QString::fromUtf8("buttonFile"));

        gridLayout->addWidget(buttonFile, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(217, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 1, 1, 3);

        buttonSend = new QPushButton(ServerWidget);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));

        gridLayout->addWidget(buttonSend, 2, 4, 1, 1);


        retranslateUi(ServerWidget);

        QMetaObject::connectSlotsByName(ServerWidget);
    } // setupUi

    void retranslateUi(QWidget *ServerWidget)
    {
        ServerWidget->setWindowTitle(QApplication::translate("ServerWidget", "ServerWidget", nullptr));
        label->setText(QApplication::translate("ServerWidget", "\346\234\215\345\212\241\345\231\250", nullptr));
        buttonFile->setText(QApplication::translate("ServerWidget", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        buttonSend->setText(QApplication::translate("ServerWidget", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWidget: public Ui_ServerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWIDGET_H
