#ifndef PICTURELABELS_H
#define PICTURELABELS_H
#include <QLabel>
#include <QKeyEvent>


class pictureLabels : public QLabel{
    Q_OBJECT
public:
    pictureLabels(QWidget *parent = 0);

protected:

public slots:
    void slotClicked();

signals:
    void mousePressEvent(QMouseEvent* event);


};


#endif // PICTURELABELS_H
