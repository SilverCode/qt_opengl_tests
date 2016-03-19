#include "abstractglscene.h"

AbstractGLScene::AbstractGLScene(QOpenGLWindow *window)
{
    m_window = window;
}

void AbstractGLScene::initialize()
{
    initializeOpenGLFunctions();
}
