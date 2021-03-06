#pragma once

#include <QWidget>
#include <QImage>
#include <QColor>
#include <QtWidgets>
#include <math.h>
#include <QDebug>
//#include <QPainter> nepotrebujeme, lebo QtWidgets to zahrna
//#include <QRect>

class QtClass : public QWidget
{
	Q_OBJECT

protected:
	
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

	
public:
	QtClass(QWidget *parent = Q_NULLPTR); //sem musim pridat = Q_NULLPTR  aby ten smernik niekam ukazoval
	~QtClass();
	void newImage(int x, int y);
	QImage *obrazok;
	bool zapnutieKreslenia;
	void SaveImg(QString menoSuboru);
	void osi(double x,double y,int pocet,int typ, bool bodovy, bool spojity, bool stlpcovy,double interval);
	void premazanie(double x, double y, int pocet);
};
