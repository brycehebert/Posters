#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Posters.h"
#include "moviedatabase.h"


class Posters : public QMainWindow
{
	Q_OBJECT

public:
	Posters(QWidget *parent = Q_NULLPTR);

private:
	Ui::PostersClass ui;

private slots:
	void on_searchButton_clicked();
};
