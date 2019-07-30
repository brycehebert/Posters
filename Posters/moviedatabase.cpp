#include "moviedatabase.h"

const QString MovieDatabase::apiKey = "b8d78f0e544e12bd0d4253aeade71eda";
const QString MovieDatabase::apiPreface = "?api_key=";

MovieDatabase::MovieDatabase(QObject *parent)
	: QObject(parent) {
	manager = new QNetworkAccessManager();

	QObject::connect(manager, &QNetworkAccessManager::finished, this, [&] (QNetworkReply* reply) {

		if (!reply->error()) {

			downloadedData = reply->readAll();
			emit signalDataReady();

		}
		else {
			emit signalError(reply->errorString());
		}
		
		reply->deleteLater();
	});
}

MovieDatabase::~MovieDatabase(){
	delete manager;
}

QString MovieDatabase::getBaseUrl() {
	return baseUrl;
}

void MovieDatabase::query(QString searchString) {
	request.setUrl(QUrl(baseUrl + searchString));
	manager->get(request);
}

QByteArray MovieDatabase::getData()
{
	return downloadedData;
}

void MovieDatabase::getPoster(QString posterPath) {
	request.setUrl(QUrl(basePosterUrl + posterPath + apiPreface + apiKey));
	manager->get(request);
}



