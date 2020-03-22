#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTabWidget>
#include<QListWidget>
#include<QString>
#include<QtDebug>
#include<QLCDNumber>
#include<QStringList>
#include<QInputDialog>
#include"schedulerAlgorithms.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //QWidget *widget  = new QWidget(this);
//    QListWidget *l = new QListWidget ;
    //l.addItem("hi");
//    connect(ui->pushButton,&QPushButton::clicked,this);
    ui->setupUi(this);
    ui->tabWidget->setTabText(0,"operations");
    ui->tabWidget->setTabText(1,"Gantt Chart");
//ui->lcdNumber->display(4);
//QInputDialog *id = new QInputDialog(this);


//connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(add()));
//connect(ui->AddProcess,&QPushButton::clicked,[=](){
//    ui->listWidget->addItem("Process "+QString::number(ui->listWidget->count()));

//});

  // hello h;
  // h.push("process2",24);
   //ui->lcdNumber->display(h.val(FCFS));
    ui->comboBox->insertItem(FCFS,"FCFS");
     ui->comboBox->insertItem(SJF,"SJF");
//     connect(ui->comboBox,SIGNAL(currentIndex()),this,SLOT(hey()));

//     qDebug () << ui->comboBox->currentIndex();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow :: hey()
{
   qDebug () << ui->comboBox->currentIndex();
}
 void MainWindow:: add()
{
    ui->listWidget->addItem("Process "+QString::number(ui->listWidget->count()));
}




void MainWindow::on_AddProcess_clicked()
{
    bool ok;
     ui->listWidget->addItem("Process "+QString::number(ui->listWidget->count()));
       l.push("Process",
              QInputDialog::getInt(this,"Burst time"+QString::number(ui->listWidget->count()),
                                   "time",0,0,1000,1,&ok));

}

void MainWindow::on_RemoveProcess_clicked()
{
     ui->listWidget->takeItem(ui->listWidget->currentRow());
     l.pop();
}

void MainWindow::on_Run_clicked()
{
    switch (ui->comboBox->currentIndex()) {
    case 0:
         ui->lcdNumber->display(QString::number(l.val(FCFS)));
        break;
    case 1 :
        ui->lcdNumber->display(66);
        break;
    default:
        break;
    }

}

