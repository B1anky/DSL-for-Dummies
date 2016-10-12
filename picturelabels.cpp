#include "pictureLabels.h"

pictureLabels: public ( const QString & text, QWidget * parent )
:QLabel(parent){
    connect(this, SIGNAL(clicked()), this, SLOT(slotClicked()));
}

void pictureLabels::mousePressEvent(QMouseEvent* event){
    emit clicked();
}

void pictureLabels::slotClicked(){
    qDebug()<<"Clicked";
}
