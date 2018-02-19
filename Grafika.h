#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Grafika.h"
#include <QDebug>
#include <math.h>
#include "QtClass.h"

class Grafika : public QMainWindow
{
	Q_OBJECT

public:
	Grafika(QWidget *parent = Q_NULLPTR);
public slots:
	void on_actionSave_triggered();

private:
	Ui::GrafikaClass ui;
	QtClass widgetNaKreslenie;
	public slots:
	void vykresli();
	void vymaz();
};
