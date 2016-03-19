#include "mainscene.h"

MainScene::MainScene(QOpenGLWindow *window)
    : AbstractGLScene(window)
{
    m_texture = 0;
    m_initialized = false;
}

MainScene::~MainScene()
{
    delete m_texture;
}

void MainScene::setTexture(QImage tex)
{
    m_tex = tex;

    if (m_initialized)
        initializeTexture();
}

void MainScene::initialize()
{
    AbstractGLScene::initialize();
    m_initialized = true;
    if (!m_tex.isNull()) initializeTexture();
    glClearColor(1, 1, 1, 0);
    glShadeModel(GL_SMOOTH);
    initializeCudeData();
}

void MainScene::paint()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, window()->width(), window()->height());
    glLoadIdentity();

    glRotatef(45, 1.0, 0.0, 0.0);
    glRotatef(45, 0.0, 1.0, 0.0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    paintCube();
}

void MainScene::initializeTexture()
{
    m_texture = new QOpenGLTexture(m_tex.mirrored());
    m_texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    m_texture->setMagnificationFilter(QOpenGLTexture::Linear);
}

void MainScene::initializeCudeData()
{
    m_data = {
        //  Font Face
        {{-0.5, -0.5,  0.5}, {0, 0}},
        {{ 0.5, -0.5,  0.5}, {1, 0}},
        {{ 0.5,  0.5,  0.5}, {1, 1}},
        {{-0.5,  0.5,  0.5}, {0, 1}},

        // Top Face
        {{-0.5,  0.5,  0.5}, {0, 0}},
        {{ 0.5,  0.5,  0.5}, {1, 0}},
        {{ 0.5,  0.5, -0.5}, {1, 1}},
        {{-0.5,  0.5, -0.5}, {0, 1}},

        // Back Face
        {{-0.5,  0.5, -0.5}, {0, 0}},
        {{ 0.5,  0.5, -0.5}, {1, 0}},
        {{ 0.5, -0.5, -0.5}, {1, 1}},
        {{-0.5, -0.5, -0.5}, {0, 1}},

        // Bottom Face
        {{-0.5, -0.5, -0.5}, {0, 0}},
        {{ 0.5, -0.5, -0.5}, {1, 0}},
        {{ 0.5, -0.5,  0.5}, {1, 1}},
        {{-0.5, -0.5,  0.5}, {0, 1}},

        // Left Face
        {{-0.5, -0.5, -0.5}, {0, 0}},
        {{-0.5, -0.5,  0.5}, {1, 0}},
        {{-0.5,  0.5,  0.5}, {1, 1}},
        {{-0.5,  0.5, -0.5}, {0, 1}},

        // Right Face
        {{ 0.5, -0.5,  0.5}, {0, 0}},
        {{ 0.5, -0.5, -0.5}, {1, 0}},
        {{ 0.5,  0.5, -0.5}, {1, 1}},
        {{ 0.5,  0.5,  0.5}, {0, 1}}
    };
}

void MainScene::paintCube()
{
   if (m_texture)
       m_texture->bind();

   glEnable(GL_TEXTURE_2D);
   glBegin(GL_QUADS);

   for (int i = 0; i < m_data.size(); ++i) {
       const TexturedPoint &pt = m_data.at(i);
       glTexCoord2d(pt.uv.x(), pt.uv.y());
       glVertex3f(pt.coord.x(), pt.coord.y(), pt.coord.z());
   }

   glEnd();
   glDisable(GL_TEXTURE_2D);
}
