#include "Grafika.h"

Grafika::Grafika(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.scrollArea->setWidget(&this->widgetNaKreslenie);
	ui.scrollArea->setBackgroundRole(QPalette::Dark);

	widgetNaKreslenie.newImage(700,400); 
}

void Grafika::on_actionSave_triggered()
{
	widgetNaKreslenie.SaveImg("GrafikaKreslenieCiary.png");
}
void Grafika::vykresli()
{
	widgetNaKreslenie.osi(ui.scrollArea->width() , ui.scrollArea->height(),ui.dx->value(),ui.funkcia->currentIndex(),ui.bodovy->isChecked(),ui.spojity->isChecked(),ui.stlpcovy->isChecked(),ui.interval->value());
}

void Grafika::vymaz()
{
	widgetNaKreslenie.newImage(700, 400);
	widgetNaKreslenie.premazanie(ui.scrollArea->width(), ui.scrollArea->height(), ui.dx->value());
}
