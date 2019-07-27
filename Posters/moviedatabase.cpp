#include "moviedatabase.h"

const QString MovieDatabase::apiKey = "b8d78f0e544e12bd0d4253aeade71eda";

MovieDatabase::MovieDatabase(QObject *parent)
	: QObject(parent) {
	manager = new QNetworkAccessManager();

	QObject::connect(manager, &QNetworkAccessManager::finished, this, [&] (QNetworkReply* reply) {

		if (!reply->error()) {

			//TODO: TMDB API will always be a json response. Find better way to determine if request was for poster image or just the movie details.
			if (reply->rawHeaderPairs().at(4).second == "application/json;charset=utf-8") {
				QJsonDocument json = QJsonDocument::fromJson(reply->readAll());
				qDebug() << json["results"][0]["poster_path"].toString();
				QString posterPath = json["results"][0]["poster_path"].toString();
				emit signalPosterFound(posterPath);
			}
			
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

void MovieDatabase::slotGetPoster(QString posterPath) {
	request.setUrl(QUrl(basePosterUrl + posterPath));
	manager->get(request);
}



