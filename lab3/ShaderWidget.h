#pragma once

#include <QGLWidget>
#include <QtOpenGL>
#include <QTimer>
#include <qimage.h>
#include <algorithm>
#include <qtopengl>
#include <QOpenGLFunctions_4_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QDebug>
#include <iostream>

#pragma comment (lib, "opengl32.lib")

struct Sphere
{
	QVector3D position;
	float radius;  
	QVector3D color;
	int material_idx;
};

class ShaderWidget : public QOpenGLWidget
{
private:
	QOpenGLShaderProgram m_program;

	GLfloat* vert_data;
	int vert_data_location;
protected:
	void initializeGL() override;
	void resizeGL(int nWight, int nHeight) override;
	void paintGL() override;
public:
	ShaderWidget(QWidget *parent = 0);
	~ShaderWidget();
	int size;
	Sphere all_spheres[1];
};
