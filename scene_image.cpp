#include "scene_image.h"

SceneImage::SceneImage(SceneGLWindow *window)
    : AbstractGLScene(window)
{
    initializeImage();
    m_tex = QImage(":/images/crate.jpg");
    m_texture = nullptr;
}

void SceneImage::initialize()
{
    AbstractGLScene::initialize();
    m_texture = new QOpenGLTexture(m_tex.mirrored());
    glClearColor(0, 0, 0, 0);

    if (!m_shader.addShaderFromSourceCode(QOpenGLShader::Vertex, fileContent("image.vert")))
        qDebug() << "Failed to load vertex shader";

    if (!m_shader.addShaderFromSourceCode(QOpenGLShader::Fragment, fileContent("image.frag")))
        qDebug() << "Failed to load fragmanet shader";

    m_shader.link();

    m_shader.bind();
    m_shader.setAttributeArray("qt_Vertex", GL_FLOAT, m_data.constData(), 3, sizeof(TexturedPoint));
    m_shader.enableAttributeArray("qt_Vertex");
    m_shader.setAttributeArray("qt_MultiTexCoord0", GL_FLOAT, &m_data[0].uv, 2, sizeof(TexturedPoint));
    m_shader.enableAttributeArray("qt_MultiTexCoord0");
}

void SceneImage::paint()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, window()->width(), window()->height());
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    m_shader.bind();

    m_texture->bind();
    const int pointCount = m_data.size();
    glDrawArrays(GL_TRIANGLES, 0, pointCount);
}

void SceneImage::initializeImage()
{
    m_data = {
        {{-1, -1, 0}, {0, 0}}, // 1
        {{ 1, -1, 0}, {1, 0}}, // 2
        {{-1,  1, 0}, {0, 1}}, // 3

        {{-1,  1, 0}, {0, 1}}, // 3
        {{ 1, -1, 0}, {1, 0}}, // 2
        {{ 1,  1, 0}, {1, 1}}  // 4
    };
}

QString SceneImage::fileContent(QString filename)
{
    QFile file(":/" + filename);
    file.open(QIODevice::ReadOnly);

    return QString(file.readAll());
}
