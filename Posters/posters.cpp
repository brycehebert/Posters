#include "posters.h"

Posters::Posters(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	db = new MovieDatabase(this);

	QObject::connect(db, &MovieDatabase::signalReady, this, &Posters::slotDisplayPoster);
	QObject::connect(db, &MovieDatabase::signalError, this, &Posters::slotError);

}

void Posters::on_searchButton_clicked() {

	QString query = ui.searchEdit->text();
	db->query(query);
	
}

void Posters::slotDisplayPoster() {

}

void Posters::slotError(QString error) {
	ui.errorLabel->setText(error);

}