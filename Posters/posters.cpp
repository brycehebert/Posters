#include "posters.h"

Posters::Posters(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	db = new MovieDatabase(this);
	imageDownload = new MovieDatabase(this);

	QObject::connect(db, &MovieDatabase::signalDataReady, this, &Posters::slotJsonSetup);
	QObject::connect(db, &MovieDatabase::signalError, this, &Posters::slotError);
	QObject::connect(imageDownload, &MovieDatabase::signalDataReady, this, &Posters::slotDisplayPoster);

}
Posters::~Posters() {
	delete db;
	delete imageDownload;
}

void Posters::on_searchButton_clicked() {

	QString query = ui.searchEdit->text();
	ui.errorLabel->clear();
	db->query(query);
	
}

void Posters::slotDisplayPoster() {
	QPixmap pm;
	pm.loadFromData(imageDownload->getData());
	ui.posterLabel->setPixmap(pm.scaled(ui.posterLabel->width(), ui.posterLabel->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Posters::slotError(QString error) {
	ui.errorLabel->setText(error);
}

void Posters::getPoster(QString path) {
	imageDownload->getPoster(path);
}

void Posters::slotJsonSetup() {
	QJsonDocument json = QJsonDocument::fromJson(db->getData());
	if (json["total_results"].toInt() == 0) {
		emit slotError("No results found.");
		return;
	}

	QString path = json["results"][0]["poster_path"].toString();
	getPoster(path);
}