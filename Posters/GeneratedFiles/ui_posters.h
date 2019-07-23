/********************************************************************************
** Form generated from reading UI file 'posters.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSTERS_H
#define UI_POSTERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PostersClass
{
public:
    QWidget *centralWidget;
    QGraphicsView *posterView;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *searchEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *searchButton;
    QLabel *errorLabel;

    void setupUi(QMainWindow *PostersClass)
    {
        if (PostersClass->objectName().isEmpty())
            PostersClass->setObjectName(QStringLiteral("PostersClass"));
        PostersClass->resize(324, 494);
        centralWidget = new QWidget(PostersClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        posterView = new QGraphicsView(centralWidget);
        posterView->setObjectName(QStringLiteral("posterView"));
        posterView->setGeometry(QRect(30, 10, 273, 390));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 410, 271, 81));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        searchEdit = new QLineEdit(widget);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));

        gridLayout->addWidget(searchEdit, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        searchButton = new QPushButton(widget);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        gridLayout->addWidget(searchButton, 1, 1, 1, 1);

        errorLabel = new QLabel(widget);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));

        gridLayout->addWidget(errorLabel, 2, 0, 1, 2);

        PostersClass->setCentralWidget(centralWidget);

        retranslateUi(PostersClass);

        QMetaObject::connectSlotsByName(PostersClass);
    } // setupUi

    void retranslateUi(QMainWindow *PostersClass)
    {
        PostersClass->setWindowTitle(QApplication::translate("PostersClass", "Posters", nullptr));
        searchButton->setText(QApplication::translate("PostersClass", "Search", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PostersClass: public Ui_PostersClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTERS_H
