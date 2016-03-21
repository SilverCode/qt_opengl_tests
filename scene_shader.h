#ifndef SCENESHADER_H
#define SCENESHADER_H

#include "abstractglscene.h"
#include "sceneglwindow.h"

#include <QOpenGLShaderProgram>
#include <QFile>
#include <QUrl>

class SceneShader : public QObject, public AbstractGLScene
{
    Q_OBJECT

public:
    SceneShader(SceneGLWindow *window);
    void initialize();
    void paint();

protected:
    void initializeObjectData();

    struct ScenePoint {
        QVector3D coords;
        QVector3D normal;

        ScenePoint(const QVector3D &c = QVector3D(), const QVector3D &n = QVector3D()) { coords = c; normal=n; }
    };

private:
    QOpenGLShaderProgram m_shader;
    QMatrix4x4 m_modelMatrix;
    QMatrix4x4 m_viewMatrix;
    QMatrix4x4 m_projectionMatrix;
    QVector<ScenePoint> m_data;

    QString fileContent(QString filename);
    void paintObject(const QMatrix4x4& mvMatrix);
};

#endif // SCENESHADER_H
