#pragma once

#include <QWidget>
#include <QResizeEvent>
#include <memory>
#include "Drawables/Drawables.h"

class Canvas : public QWidget {
    Q_OBJECT
public:
    Canvas(QWidget *parent = nullptr);
    ~Canvas();
    void setCurrentDrawableType(int type);
    void setCurrentDrawablePixelSize(int pixel_size);
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private slots:
    void onPaintingFinished();
private:
    Drawable *m_drawable;
    std::vector<Drawable*> m_drawables;
    int m_drawable_type = 0;
    int m_pixel_size = 1;
};