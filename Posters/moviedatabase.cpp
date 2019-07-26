#include "moviedatabase.h"
#include "qjsondocument.h"

const QString MovieDatabase::apiKey = "b8d78f0e544e12bd0d4253aeade71eda";

MovieDatabase::MovieDatabase(QObject *parent)
	: QObject(parent) {
	manager = new QNetworkAccessManager();

	QObject::connect(manager, &QNetworkAccessManager::finished, this, [&] (QNetworkReply* reply) {

		if (!reply->error()) {
			json = QJsonDocument::fromJson(reply->readAll());

			qDebug() << json;
			emit signalReady();
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
	QNetworkReply* reply = manager->get(request);
}



