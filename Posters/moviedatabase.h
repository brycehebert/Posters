#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

class MovieDatabase : public QObject
{
	Q_OBJECT

public:
	MovieDatabase(QObject *parent);
	~MovieDatabase();
	QString getBaseUrl();
	void query(QString searchString);

private:
	static const QString apiKey;

	QNetworkAccessManager* manager;
	QNetworkRequest request;
	QJsonDocument json;

	const QString baseUrl = "https://api.themoviedb.org/3/search/movie?api_key=" + apiKey + "&language=en-US&page=1&include_adult=false&query=";

signals:
	void signalReady();
	void signalError(QString error);
};
