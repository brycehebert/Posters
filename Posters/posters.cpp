#include "posters.h"

Posters::Posters(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void Posters::on_searchButton_clicked() {
	QString query = ui.searchEdit->text();
	ui.errorLabel->setText(query);
}