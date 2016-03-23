#include "scene_shader.h"

SceneShader::SceneShader(SceneGLWindow *window)
    : AbstractGLScene(window)
{
    initializeObjectData();
}

void SceneShader::initialize()
{
    AbstractGLScene::initialize();
    glClearColor(0, 0, 0, 0);

    m_shader.addShaderFromSourceCode(QOpenGLShader::Vertex, fileContent("phong.vert"));
    m_shader.addShaderFromSourceCode(QOpenGLShader::Fragment, fileContent("phong.frag"));
    m_shader.link();

    m_shader.bind();
    m_shader.setAttributeArray("Vertex", GL_FLOAT, m_data.constData(), 3, sizeof(ScenePoint));
    m_shader.enableAttributeArray("Vertex");
    m_shader.setAttributeArray("Normal", GL_FLOAT, &m_data[0].normal, 3, sizeof(ScenePoint));
    m_shader.enableAttributeArray("Normal");
    m_shader.setUniformValue("mat.ka", QVector3D(0.1, 0.0, 0.0));
    m_shader.setUniformValue("mat.kd", QVector3D(0.7, 0.0, 0.0));
    m_shader.setUniformValue("mat.ks", QVector3D(1.0, 1.0, 1.0));
    m_shader.setUniformValue("mat.shininess", 128.0f);
    m_shader.setUniformValue("light.position", QVector3D(2, 1, 1));
    m_shader.setUniformValue("light.intensity", QVector3D(1, 1, 1));

}

void SceneShader::paint()
{
    m_projectionMatrix.setToIdentity();
    qreal ratio = qreal(window()->width()) / qreal(window()->height());
    m_projectionMatrix.perspective(90, ratio, 0.5, 40);
    m_viewMatrix.setToIdentity();
    QVector3D eye = QVector3D(0, 0, 2);
    QVector3D center = QVector3D(0, 0, 0);
    QVector3D up = QVector3D(0, 1, 0);
    m_viewMatrix.lookAt(eye, center, up);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, window()->width(), window()->height());
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    m_modelMatrix.setToIdentity();
    m_modelMatrix.rotate(m_angle, 1, 1, 1);
    QMatrix4x4 modelViewMatrix = m_viewMatrix * m_modelMatrix;
    paintObject(modelViewMatrix);
}

void SceneShader::setAngle(float angle)
{
    m_angle = angle;
    window()->update();
}

void SceneShader::initializeObjectData()
{
    m_data = {
        //  Font Face
        {{-0.5, -0.5,  0.5}, { 0,  0,  1}},
        {{ 0.5, -0.5,  0.5}, { 0,  0,  1}},
        {{-0.5,  0.5,  0.5}, { 0,  0,  1}},

        {{-0.5,  0.5,  0.5}, { 0,  0,  1}},
        {{ 0.5, -0.5,  0.5}, { 0,  0,  1}},
        {{ 0.5,  0.5,  0.5}, { 0,  0,  1}},

        // Top Face
        {{-0.5,  0.5,  0.5}, { 0, -1,  0}},
        {{ 0.5,  0.5,  0.5}, { 0, -1,  0}},
        {{-0.5,  0.5, -0.5}, { 0, -1,  0}},

        {{-0.5,  0.5, -0.5}, { 0, -1,  0}},
        {{ 0.5,  0.5,  0.5}, { 0, -1,  0}},
        {{ 0.5,  0.5, -0.5}, { 0, -1,  0}},

        // Back Face
        {{ 0.5, -0.5, -0.5}, { 0,  0, -1}},
        {{-0.5, -0.5, -0.5}, { 0,  0, -1}},
        {{ 0.5,  0.5, -0.5}, { 0,  0, -1}},

        {{ 0.5,  0.5, -0.5}, { 0,  0, -1}},
        {{-0.5, -0.5, -0.5}, { 0,  0, -1}},
        {{-0.5,  0.5, -0.5}, { 0,  0, -1}},

        // Bottom Face
        {{-0.5, -0.5, -0.5}, { 0, 1,  0}},
        {{ 0.5, -0.5, -0.5}, { 0, 1,  0}},
        {{-0.5, -0.5,  0.5}, { 0, 1,  0}},

        {{-0.5, -0.5,  0.5}, { 0, 1,  0}},
        {{ 0.5, -0.5, -0.5}, { 0, 1,  0}},
        {{ 0.5, -0.5,  0.5}, { 0, 1,  0}},

        // Left Face
        {{-0.5, -0.5,  0.5}, {-1,  0,  0}},
        {{-0.5,  0.5,  0.5}, {-1,  0,  0}},
        {{-0.5, -0.5, -0.5}, {-1,  0,  0}},

        {{-0.5, -0.5, -0.5}, {-1,  0,  0}},
        {{-0.5,  0.5,  0.5}, {-1,  0,  0}},
        {{-0.5,  0.5, -0.5}, {-1,  0,  0}},

        // Right Face
        {{ 0.5, -0.5,  0.5}, { 1,  0,  0}},
        {{ 0.5, -0.5, -0.5}, { 1,  0,  0}},
        {{ 0.5,  0.5,  0.5}, { 1,  0,  0}},

        {{ 0.5,  0.5,  0.5}, { 1,  0,  0}},
        {{ 0.5, -0.5, -0.5}, { 1,  0,  0}},
        {{ 0.5,  0.5, -0.5}, { 1,  0,  0}},
    };
}

QString SceneShader::fileContent(QString filename)
{
    QFile file(":/" + filename);
    file.open(QIODevice::ReadOnly);

    return QString(file.readAll());
}

void SceneShader::paintObject(const QMatrix4x4 &mvMatrix)
{
    m_shader.bind();
    m_shader.setUniformValue("projectionMatrix", m_projectionMatrix);
    m_shader.setUniformValue("modelViewMatrix", mvMatrix);
    m_shader.setUniformValue("mvpMatrix", m_projectionMatrix*mvMatrix);
    m_shader.setUniformValue("normalMatrix", mvMatrix.normalMatrix());
    const int pointCount = m_data.size();
    glDrawArrays(GL_TRIANGLES, 0, pointCount);
}
