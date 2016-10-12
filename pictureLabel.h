#ifndef PICTURELABEL_H
#define PICTURELABEL_H

#include <QLabel>
#include <QDesktopServices>
#include <QMouseEvent>

class pictureLabel : public QLabel
{
    Q_OBJECT
public:
    explicit pictureLabel(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *e);
signals:

public slots:
};

#endif // PICTURELABEL_H
