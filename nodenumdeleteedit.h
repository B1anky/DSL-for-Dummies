#ifndef NODENUMDELETEEDIT_H
#define NODENUMDELETEEDIT_H

#include <QTextEdit>
#include <QKeyEvent>
#include "iostream"

using namespace std;

class NodeNumDeleteEdit : public QTextEdit{
    Q_OBJECT
public:
    NodeNumDeleteEdit(QWidget *parent = 0);

protected:
    virtual void keyPressEvent(QKeyEvent *e);

public slots:

signals:
    void hitDeleteEnter();

};

#endif

