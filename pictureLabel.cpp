#include "pictureLabel.h"

pictureLabel::pictureLabel(QWidget *parent) : QLabel(parent){

}

void pictureLabel::mousePressEvent(QMouseEvent *e){
    QDesktopServices::openUrl(QUrl("http://stackoverflow.com/questions/8427446/making-qlabel-behave-like-a-hyperlink"));
}
