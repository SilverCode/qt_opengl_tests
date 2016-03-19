#include "sceneglwindow.h"

SceneGLWindow::SceneGLWindow()
{

}

void SceneGLWindow::initializeGL()
{
    if (scene())
        scene()->initialize();
}

void SceneGLWindow::paintGL()
{
    if (scene())
        scene()->paint();
}
