//
// Created by hendrik on 15.10.19.
//

#ifndef RTS_QOPENGLWINDOW_H
#define RTS_QOPENGLWINDOW_H


#include <QtGui/QWindow>
#include <QtGui/QOpenGLFunctions>
#include <QtGui/QOpenGLPaintDevice>

class QOpenGLWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit QOpenGLWindow(QWindow *parent = 0);
    ~QOpenGLWindow();

    virtual void render(QPainter *painter);
    virtual void render();

    virtual void initialize();

    void setAnimating(bool animating);

public slots:
            void renderLater();
    void renderNow();

protected:
    bool event(QEvent *event) override;

    void exposeEvent(QExposeEvent *event) override;

private:
    bool m_animating;

    QOpenGLContext *m_context;
    QOpenGLPaintDevice *m_device;
};

#endif //RTS_QOPENGLWINDOW_H
