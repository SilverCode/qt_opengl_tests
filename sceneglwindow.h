#ifndef SCENEGLWINDOW_H
#define SCENEGLWINDOW_H

#include "abstractglscene.h"
#include <QOpenGLFunctions>

class SceneGLWindow : public QOpenGLWindow
{
public:
    SceneGLWindow();
    void initializeGL();
    void paintGL();

    AbstractGLScene* scene() { return m_abstractGLScene; }
    void setScene(AbstractGLScene *scene) { m_abstractGLScene = scene; }

private:
    AbstractGLScene *m_abstractGLScene;
};

#endif // SCENEGLWINDOW_H
