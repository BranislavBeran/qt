#include "QtClass.h"

QtClass::QtClass(QWidget *parent)
	: QWidget(parent)
{
	zapnutieKreslenia = 0;
}

QtClass::~QtClass()
{
}

void QtClass::newImage(int x, int y)
{
	obrazok = new QImage(x, y, QImage::Format_RGB32);
	obrazok->fill(Qt::white);

	this->setMinimumSize(obrazok->size());

	update();
}

void QtClass::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QRect area = event->rect();
	painter.drawImage(area, *obrazok, area);
}

void QtClass::SaveImg(QString menoSuboru)
{
	if (obrazok->save(menoSuboru, "png"))
		qDebug() << "ulozene";
	else
		qDebug() << "zlyhalo";
}

void QtClass::osi(double x, double y,int pocet,int typ,bool bodovy,bool spojity,bool stlpcovy,double interval)
{
	QPainter stetec(obrazok);
	QPen cevrene(Qt::red), modre(Qt::blue),zelene(Qt::green);
	double x2 = x / (double)2;
	double y2 = y / (double)2;
	double dx = x2 / (double)pocet;
	double dy = y2 / (double)pocet;
	double dxInterval = M_PI*interval / (double)pocet;

	zelene.setWidth(10);
	cevrene.setWidth(5);
	modre.setWidth(2);

	modre.setCapStyle(Qt::RoundCap);
	cevrene.setCapStyle(Qt::RoundCap);
	zelene.setCapStyle(Qt::RoundCap);

	stetec.drawLine(x2, 0 , x2, y2 * 2);
	stetec.drawLine(0, y2, x2 * 2, y2);

	
	for (int i = 0; i < 2*pocet+1; i++) {
		stetec.drawLine(i*dx,y2+10 ,i*dx, y2-10);
		stetec.drawLine(x2 - 10, i*dy, x2 + 10, i*dy);
	}
	
	if (typ == 0) {//sin
		if (bodovy == true) {
			stetec.setPen(zelene);
			for (int i = 0; i < 2 * pocet + 1; i++) {
				stetec.drawPoint(i*dx, (y2*qSin((i-pocet)*dxInterval)+y2));
			}
		}
		else if (spojity == true) {
			stetec.setPen(cevrene);
			for (int i = 0; i < 2 * pocet ; i++) {
				stetec.drawLine(i*dx, (y2*qSin((i - pocet)*dxInterval) + y2), (i+1)*dx, (y2*qSin((i+1 - pocet)*dxInterval) + y2));
			}
		}
		else if (stlpcovy == true) {
			stetec.setPen(modre);
			for (int i = 0; i < 2 * pocet; i++) {
				if (y2*qSin((i - pocet)*dxInterval)>0) {
					stetec.drawRect(i*dx, y2, dx, y2*qSin((i - pocet)*dxInterval));
				}
				else {
					stetec.drawRect(i*dx, (y2*qSin((i - pocet)*dxInterval) + y2), dx, -y2*qSin((i - pocet)*dxInterval));
				}
			}
		}
	}
	else if (typ == 1) {//cos
		if(bodovy == true) {
			stetec.setPen(zelene);
			for (int i = 0; i < 2 * pocet + 1; i++) {
					stetec.drawPoint(i*dx, (y2*qCos((i - pocet)*dxInterval) + y2));
			}
		}
		else if (spojity == true){ 
			stetec.setPen(cevrene);
			for (int i = 0; i < 2 * pocet; i++) {
				stetec.drawLine(i*dx, (y2*qCos((i - pocet)*dxInterval) + y2), (i + 1)*dx, (y2*qCos((i + 1 - pocet)*dxInterval) + y2));
			}
		}
		else if (stlpcovy == true) {
			stetec.setPen(modre);
			for (int i = 0; i < 2 * pocet; i++) {
				if (y2*qCos((i - pocet)*dxInterval)>0) {
					stetec.drawRect(i*dx, y2, dx, y2*qCos((i - pocet)*dxInterval));
				}
				else {
					stetec.drawRect(i*dx,(y2*qCos((i - pocet)*dxInterval) + y2) ,dx, -y2*qCos((i - pocet)*dxInterval));
				}
			}
		}
	}
	update();
}

void QtClass::premazanie(double x, double y, int pocet)
{
	
	QPainter stetec(obrazok);
	double x2 = x / (double)2;
	double y2 = y / (double)2;
	double dx = x2 / (double)pocet;
	double dy = y2 / (double)pocet;

	stetec.drawLine(x2, 0, x2, y2 * 2);
	stetec.drawLine(0, y2, x2 * 2, y2);

	for (int i = 0; i < 2 * pocet + 1; i++) {
		stetec.drawLine(i*dx, y2 + 10, i*dx, y2 - 10);
		stetec.drawLine(x2 - 10, i*dy, x2 + 10, i*dy);
	}
	update();
}
