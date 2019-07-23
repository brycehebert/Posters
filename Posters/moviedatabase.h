#pragma once

#include <QObject>
#include <QNetworkAccessManager>

class MovieDatabase : public QObject
{
	Q_OBJECT

public:
	MovieDatabase(QObject *parent);
	~MovieDatabase();
	QString getBaseUrl();

private:
	static const QString apiKey;

	QNetworkAccessManager* manager;

	const QString baseUrl = "https://api.themoviedb.org/3/search/movie?api_key=b8d78f0e544e12bd0d4253aeade71eda&language=en-US&page=1&include_adult=false&query=";

};
