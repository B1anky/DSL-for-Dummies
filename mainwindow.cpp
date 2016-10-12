#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    /*
    QHBoxLayout *top = new QHBoxLayout;
    QHBoxLayout *bottom = new QHBoxLayout;
    addNumberText = new MyTextEdit();
    addNumberText->setGeometry(500, 200, 200, 200);
    top->addWidget(addNumberText);
    bottom->addWidget(ui->dataLabel);
    bottom->addWidget(ui->pushButton);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(top);
    mainLayout->addLayout(bottom);
    this->centralWidget()->setLayout(mainLayout);
    ui->dataLabel->setText(QString::fromStdString(list.printAll()));
    */
    QObject::connect(ui->addNumberText, SIGNAL(hitAddEnter()), this, SLOT(on_pushButtonAddNode_clicked()));
    QObject::connect(ui->deleteNumberText, SIGNAL(hitDeleteEnter()), this, SLOT(on_pushButtonDeleteNode_clicked()));
    ui->indexMessageLabel->setText("Specify index to insert at.\n(0 = head, up to size of\n list length = tail");
    setUpCodePictures();
    ui->dataLabel->setText(QString::fromStdString(list.printAll()));

}

void MainWindow::setUpCodePictures(){
    QPixmap linkedListHeaderCodePix(":/pictures/linkedListHeaderCodePic.png");
    ui->linkedListHeaderCodeLabel->setPixmap(linkedListHeaderCodePix);
    ui->linkedListHeaderCodeLabel->setTextFormat(Qt::RichText);
    ui->linkedListHeaderCodeLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->linkedListHeaderCodeLabel->setOpenExternalLinks(true);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::updateAdd(){
    list.addNode(ui->addNumberText->toPlainText().toInt());
    ui->indexSpinBox->setMaximum(list.getLength());
    ui->dataLabel->setText(QString::fromStdString(list.printAll()));
}

void MainWindow::updateInsert(int index){
    list.addNode(ui->addNumberText->toPlainText().toInt(), index);
    ui->indexSpinBox->setMaximum(list.getLength());
    ui->dataLabel->setText(QString::fromStdString(list.printAll()));
}

void MainWindow::updateDelete(){
    list.remove(ui->deleteNumberText->toPlainText().toInt(), deleteAll);
    ui->indexSpinBox->setMaximum(list.getLength());
    ui->dataLabel->setText(QString::fromStdString(list.printAll()));
}

void MainWindow::on_pushButtonAddNode_clicked(){
    if(ui->indexSpinBox->value() >= 0){
        updateInsert(ui->indexSpinBox->value());
    }else{
        updateAdd();
    }
}

void MainWindow::on_pushButtonDeleteNode_clicked(){
    updateDelete();
}

void MainWindow::on_deleteMultipleRadioButton_clicked(){
    if(deleteAll){
        deleteAll = false;
        ui->deleteMultipleRadioButton->setText("Remove first match");
    }else{
        deleteAll = true;
        ui->deleteMultipleRadioButton->setText("Remove all matches");
    }
}
