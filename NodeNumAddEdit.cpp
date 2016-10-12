#include "nodeNumAddEdit.h"

NodeNumAddEdit::NodeNumAddEdit(QWidget *parent) :QTextEdit(parent){
}

void NodeNumAddEdit::keyPressEvent(QKeyEvent *e){
    if(e->key()== Qt::Key_Return){
         emit hitAddEnter();
    }else{
        QTextEdit::keyPressEvent(e);
    }
}
