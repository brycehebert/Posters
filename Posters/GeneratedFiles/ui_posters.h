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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PostersClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *searchEdit;
    QPushButton *searchButton;
    QLabel *errorLabel;
    QLabel *posterLabel;

    void setupUi(QMainWindow *PostersClass)
    {
        if (PostersClass->objectName().isEmpty())
            PostersClass->setObjectName(QStringLiteral("PostersClass"));
        PostersClass->resize(440, 694);
        centralWidget = new QWidget(PostersClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        searchEdit = new QLineEdit(centralWidget);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));

        gridLayout->addWidget(searchEdit, 1, 0, 1, 2);

        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        gridLayout->addWidget(searchButton, 2, 1, 1, 1);

        errorLabel = new QLabel(centralWidget);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setWordWrap(true);

        gridLayout->addWidget(errorLabel, 3, 0, 1, 2);

        posterLabel = new QLabel(centralWidget);
        posterLabel->setObjectName(QStringLiteral("posterLabel"));
        posterLabel->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(posterLabel->sizePolicy().hasHeightForWidth());
        posterLabel->setSizePolicy(sizePolicy);
        posterLabel->setScaledContents(false);
        posterLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(posterLabel, 0, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        PostersClass->setCentralWidget(centralWidget);

        retranslateUi(PostersClass);
        QObject::connect(searchEdit, SIGNAL(returnPressed()), searchButton, SLOT(click()));

        QMetaObject::connectSlotsByName(PostersClass);
    } // setupUi

    void retranslateUi(QMainWindow *PostersClass)
    {
        PostersClass->setWindowTitle(QApplication::translate("PostersClass", "Posters", nullptr));
        searchButton->setText(QApplication::translate("PostersClass", "Search", nullptr));
        errorLabel->setText(QString());
        posterLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PostersClass: public Ui_PostersClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTERS_H
