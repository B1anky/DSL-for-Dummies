#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QApplication>
#include "LinkedList.h"
#include "NodeNumAddEdit.h"
#include "NodeNumDeleteEdit.h"
#include <time.h>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QTextStream>
#include <QHBoxLayout>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setUpCodePictures();
    void updateAdd();
    void updateInsert(int index);
    void updateDelete();


private slots:

    void on_pushButtonAddNode_clicked();

    void on_pushButtonDeleteNode_clicked();

    void on_deleteMultipleRadioButton_clicked();

private:
    Ui::MainWindow *ui;
    LinkedList list;
    bool deleteAll = false;
};

#endif // MAINWINDOW_H
