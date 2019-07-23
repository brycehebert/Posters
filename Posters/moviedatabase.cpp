#include "moviedatabase.h"

const QString MovieDatabase::apiKey = "b8d78f0e544e12bd0d4253aeade71eda";

MovieDatabase::MovieDatabase(QObject *parent)
	: QObject(parent)
{
	manager = new QNetworkAccessManager();

}

MovieDatabase::~MovieDatabase()
{
}

QString MovieDatabase::getBaseUrl() {
	return baseUrl;
}