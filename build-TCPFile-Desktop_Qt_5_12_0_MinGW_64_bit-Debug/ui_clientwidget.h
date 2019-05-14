/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditPort;
    QLineEdit *lineEditIP;
    QLabel *label_2;
    QPushButton *buttonConnect;
    QProgressBar *progressBar;
    QTextEdit *textEdit;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QString::fromUtf8("ClientWidget"));
        ClientWidget->resize(400, 300);
        gridLayout_2 = new QGridLayout(ClientWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_2 = new QWidget(ClientWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(125, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(24);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(125, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addWidget(widget_2, 0, 0, 1, 1);

        widget = new QWidget(ClientWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditPort = new QLineEdit(widget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 2, 1, 1, 1);

        lineEditIP = new QLineEdit(widget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));

        gridLayout->addWidget(lineEditIP, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 2, 1);

        buttonConnect = new QPushButton(widget);
        buttonConnect->setObjectName(QString::fromUtf8("buttonConnect"));

        gridLayout->addWidget(buttonConnect, 0, 2, 3, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        progressBar = new QProgressBar(ClientWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout_2->addWidget(progressBar, 2, 0, 1, 1);

        textEdit = new QTextEdit(ClientWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout_2->addWidget(textEdit, 3, 0, 1, 1);


        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QApplication::translate("ClientWidget", "Form", nullptr));
        label_3->setText(QApplication::translate("ClientWidget", "\345\256\242\346\210\267\347\253\257", nullptr));
        label->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250\347\232\204IP:", nullptr));
        lineEditPort->setText(QApplication::translate("ClientWidget", "8888", nullptr));
        lineEditIP->setText(QApplication::translate("ClientWidget", "127.0.0.1", nullptr));
        label_2->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250\347\232\204\347\253\257\345\217\243:", nullptr));
        buttonConnect->setText(QApplication::translate("ClientWidget", "connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
