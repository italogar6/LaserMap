#include "field3dloader.h"

Field3DLoader::Field3DLoader()
	: QThread()
{

}

Field3DLoader::~Field3DLoader()
{

}

void Field3DLoader::run()
{
	GLdouble xMin;
	GLdouble xMax;
	GLdouble yMin;
	GLdouble yMax;
	if (init.getX() > end.getX())
	{
		xMax = init.getX();
		xMin = end.getX();
	}
	else
	{
		xMax = end.getX();
		xMin = init.getX();
	}
	if (init.getY() > end.getY())
	{
		yMax = init.getY();
		yMin = end.getY();
	}
	else
	{
		yMax = end.getY();
		yMin = init.getY();
	}
	QList<LaserPoint> *pointList = laserPointList->getList();
	LaserPointList *laserPointList3D = new LaserPointList();
	for (int i = 0; i < pointList->size(); i++)
	{
		LaserPoint p = pointList->at(i);
		if (p.getX() > xMin &&
			p.getX() < xMax &&
			p.getY() > yMin &&
			p.getY() < yMax)
			laserPointList3D->add(p);
	}
	emit loaded3DList(laserPointList3D);
}


void Field3DLoader::setWorkspace(LaserPoint initIn, LaserPoint endIn, LaserPointList* laserPointListIn)
{
	init = initIn;
	end = endIn;
	laserPointList = laserPointListIn;
}