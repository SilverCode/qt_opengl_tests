#ifndef IMAGESCENE_H
#define IMAGESCENE_H

#include "abstractglscene.h"
#include "sceneglwindow.h"

#include <QVector2D>
#include <QVector3D>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QFile>

struct TexturedPoint {
    QVector3D coord;
    QVector2D uv;
    TexturedPoint(const QVector3D& pcoord = QVector3D(), const QVector2D& puv = QVector2D()) {
        coord = pcoord; uv = puv;
    }
};

class SceneImage : public QObject, public AbstractGLScene
{
    Q_OBJECT

public:
    SceneImage(SceneGLWindow *window);
    void initialize();
    void paint();

private:
    void initializeImage();
    QImage m_tex;
    QOpenGLTexture *m_texture;
    QOpenGLShaderProgram m_shader;
    QVector<TexturedPoint> m_data;

    QString fileContent(QString filename);
};

#endif // IMAGESCENE_H
