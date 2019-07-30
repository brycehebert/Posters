#pragma once

#include <QtWidgets/QMainWindow>
#include <QJsonDocument>
#include "ui_Posters.h"
#include "moviedatabase.h"

class Posters : public QMainWindow
{
	Q_OBJECT

public:
	Posters(QWidget *parent = Q_NULLPTR);
	~Posters();

private:
	Ui::PostersClass ui;
	MovieDatabase* db;
	MovieDatabase* imageDownload;

	void getPoster(QString path);

signals:
	void signalPathReady(QString path);

private slots:
	void on_searchButton_clicked();
	void slotDisplayPoster();
	void slotError(QString error);
	
	void slotJsonSetup();

};
