#ifndef OPENGLPLOT_H
#define OPENGLPLOT_H
#include <QtWidgets/QMainWindow>
#include <QtWidgets/qopenglwidget.h>
#include <QtOpenGL>
#include <liblas/liblas.hpp>
#include <fstream>  // std::ifstream
#include <iostream>
#include <QList>
#include <QDebug>
#include "laserpoint.h"

class OpenGLplot : public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT

public:
	OpenGLplot::OpenGLplot(QWidget *parent, QString filenameIn);
	OpenGLplot(QWidget *parent);
	~OpenGLplot();

// public slots:
// 	void openFile(QString filename);
// 	void enableDrag();
// 	void enableZoom();
// 	void setHeightColor();
// 	void setClassColor();

protected:
	virtual void initializeGL();
	virtual void paintEvent(QPaintEvent *e);
	virtual void resizeGL(int w, int h);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

private:
	QString filename;
	QList<LaserPoint*> pointList;
	GLdouble xMin = 1.0, xMax = 1.0, xLength = 2.0, yMin = 1.0, yMax = 1.0, yLength = 2.0, zMin = 1.0, zMax = 1.0, ratioMap = 1.0;
	GLdouble xMinInit = 1.0, xMaxInit = 1.0, xLengthInit = 2.0, yMinInit = 1.0, yMaxInit = 1.0, yLengthInit = 2.0;
	GLdouble mapCenter[2];
	int initX, initY;

	void setColor(liblas::Classification const &pointClass);
	void zoomGlortho(GLdouble zoomCenter[], GLdouble *percent);
};



#endif
