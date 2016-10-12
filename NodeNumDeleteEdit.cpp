#include "nodeNumDeleteEdit.h"

NodeNumDeleteEdit::NodeNumDeleteEdit(QWidget *parent) :QTextEdit(parent){
}

void NodeNumDeleteEdit::keyPressEvent(QKeyEvent *e){
    if(e->key()== Qt::Key_Return){
         emit hitDeleteEnter();
    }else{
        QTextEdit::keyPressEvent(e);
    }
}
