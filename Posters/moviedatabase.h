#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

class MovieDatabase : public QObject
{
	Q_OBJECT

public:
	MovieDatabase(QObject *parent);
	~MovieDatabase();
	QString getBaseUrl();
	void query(QString searchString);
	void getPoster(QString posterPath);
	QByteArray getData();

private:
	static const QString apiKey;
	static const QString apiPreface;

	QNetworkAccessManager* manager;
	QNetworkRequest request;

	const QString baseUrl = "https://api.themoviedb.org/3/search/movie?api_key=" + apiKey + "&language=en-US&page=1&include_adult=false&query=";
	const QString basePosterUrl = "https://image.tmdb.org/t/p/w500";

	QByteArray downloadedData;

signals:
	void signalDataReady();
	void signalError(QString error);
};
