#include "MyTextEdit.h"

void MyTextEdit::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Return){

    }else{
        QTextEdit::keyPressEvent(event);
    }
}
