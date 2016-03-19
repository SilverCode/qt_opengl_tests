#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "abstractglscene.h"
#include <QOpenGLTexture>
#include <QImage>
#include <QVector>
#include <QVector2D>
#include <QVector3D>

struct TexturedPoint {
    QVector3D coord;
    QVector2D uv;
    TexturedPoint(const QVector3D& pcoord, const QVector2D& puv) {
        coord = pcoord; uv = puv;
    }
};

class MainScene : public AbstractGLScene
{
public:
    MainScene(QOpenGLWindow *window = 0);
    ~MainScene();
    void setTexture(QImage tex);
    void initialize();
    void paint();

protected:
    void initializeTexture();
    void initializeCudeData();
    void paintCube();

private:
    QImage m_tex;
    QOpenGLTexture *m_texture;
    bool m_initialized;
    QVector<TexturedPoint> m_data;
};

#endif // MAINSCENE_H
