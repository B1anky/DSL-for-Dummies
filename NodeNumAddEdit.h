#ifndef NODENUMADDEDIT_H
#define NODENUMADDEDIT_H

#include <QTextEdit>
#include <QKeyEvent>
#include "iostream"

using namespace std;

class NodeNumAddEdit : public QTextEdit{
    Q_OBJECT
public:
    NodeNumAddEdit(QWidget *parent = 0);

protected:
    virtual void keyPressEvent(QKeyEvent *e);

public slots:

signals:
    void hitAddEnter();
};

#endif


