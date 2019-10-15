//
// Created by hendrik on 15.10.19.
//

#include <QtGui/QPainter>
#include "QOpenGLWindow.h"

QOpenGLWindow::QOpenGLWindow(QWindow *parent)
        : QWindow(parent)
        , m_animating(false)
        , m_context(0)
        , m_device(0)
{
    setSurfaceType(QWindow::OpenGLSurface);
}

QOpenGLWindow::~QOpenGLWindow(){}
void QOpenGLWindow::render(QPainter *painter)
{
    Q_UNUSED(painter);
}

void QOpenGLWindow::initialize()
{
}

void QOpenGLWindow::render()
{
    if (!m_device)
        m_device = new QOpenGLPaintDevice;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    m_device->setSize(size() * devicePixelRatio());
    m_device->setDevicePixelRatio(devicePixelRatio());

    QPainter painter(m_device);
    render(&painter);
}
void QOpenGLWindow::renderLater()
{
    requestUpdate();
}

bool QOpenGLWindow::event(QEvent *event)
{
    switch (event->type()) {
        case QEvent::UpdateRequest:
            renderNow();
            return true;
        default:
            return QWindow::event(event);
    }
}

void QOpenGLWindow::exposeEvent(QExposeEvent *event)
{
    Q_UNUSED(event);

    if (isExposed())
        renderNow();
}

void QOpenGLWindow::renderNow()
{
    if (!isExposed())
        return;

    bool needsInitialize = false;

    if (!m_context) {
        m_context = new QOpenGLContext(this);
        m_context->setFormat(requestedFormat());
        m_context->create();

        needsInitialize = true;
    }

    m_context->makeCurrent(this);

    if (needsInitialize) {
        initializeOpenGLFunctions();
        initialize();
    }

    render();

    m_context->swapBuffers(this);

    if (m_animating)
        renderLater();
}

void QOpenGLWindow::setAnimating(bool animating)
{
    m_animating = animating;

    if (animating)
        renderLater();
}