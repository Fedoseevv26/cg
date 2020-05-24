#include "ShaderWidget.h"

ShaderWidget::ShaderWidget(QWidget* parent) : QOpenGLWidget(parent)
{
	vert_data = new GLfloat[12];

	vert_data[0] = -1.0f; vert_data[1] = -1.0f; vert_data[2] = 0.0f;
	vert_data[3] =  1.0f; vert_data[4] = -1.0f; vert_data[5] = 0.0f;
	vert_data[6] =  1.0f; vert_data[7] =  1.0f; vert_data[8] = 0.0f;
	vert_data[9] = -1.0f; vert_data[10] = 1.0f; vert_data[11] = 0.0f;

	size = 1;

	all_spheres[0] = { QVector3D(0,0,0),2.0,QVector3D(1,0,1),0 };
}

ShaderWidget::~ShaderWidget()
{
	delete[] vert_data;
}

void ShaderWidget::initializeGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	QOpenGLShader vShader(QOpenGLShader::Vertex);
	vShader.compileSourceFile("raytracing.vert");

	QOpenGLShader fShader(QOpenGLShader::Fragment);
	fShader.compileSourceFile("raytracing.frag");


	m_program.addShader(&vShader);
	m_program.addShader(&fShader);

	if (!m_program.link())
	{
		qWarning("Error link programm shader");
		return;
	}
	vert_data_location = m_program.attributeLocation("vertex");

	qDebug() << QString("Log Programm");
	qDebug() << m_program.log();

	if (!m_program.bind())
		qWarning("Error bind programm shader");
	m_program.setUniformValue("camera.position", QVector3D(0.0, 0.0, -10));
	m_program.setUniformValue("camera.view",	 QVector3D(0.0, 0.0, 1.0));
	m_program.setUniformValue("camera.up",		 QVector3D(0.0, 1.0, 0.0));
	m_program.setUniformValue("camera.side",	 QVector3D(1.0, 0.0, 0.0));

	m_program.setUniformValue("scale", QVector2D(width(), height()));

	QOpenGLFunctions_4_3_Core* functions = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_4_3_Core>();
	GLuint ssbo = 0; functions->glGenBuffers(1, &ssbo);
	functions->glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo);
	functions->glBufferData(GL_SHADER_STORAGE_BUFFER, size * sizeof(Sphere), all_spheres, GL_DYNAMIC_COPY);
	// Now bind the buffer to the zeroth GL_SHADER_STORAGE_BUFFER binding point 
	functions->glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, ssbo);

	m_program.release();
}

void ShaderWidget::resizeGL(int nWight, int nHeight)
{
	glViewport(0, 0, nWight, nHeight);
	if (!m_program.bind())
		qWarning("Error bind programm shader");
	m_program.setUniformValue("scale", QVector2D(width(), height()));
	m_program.release();

}

void ShaderWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (!m_program.bind())
		return;
	m_program.enableAttributeArray(vert_data_location);
	m_program.setAttributeArray(vert_data_location, vert_data, 3);

	glDrawArrays(GL_QUADS, 0, 4);
		
	m_program.disableAttributeArray(vert_data_location);
	m_program.release();
}


