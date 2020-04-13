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

#include <QApplication>
#include"inputdialog.h"
#include"GraphicalCharts/charts_representation.h"
#include<QString>
#include<QDebug>
void MainWindow::SetComboBox()
{
    ui->tabWidget->setTabText(0,"operations");
    ui->tabWidget->setTabText(1,"Gantt Chart");
    ui->comboBox->insertItem(FCFS,"FCFS");
    ui->comboBox->insertItem(SJF_PRIMITVE,"SJF Premitive");
    ui->comboBox->insertItem(SJF_NON_PRIMITVE,"SJF Non Premitive");
    ui->comboBox->insertItem(PRIORTY_PRIMITVE,"Priorty Primtive");
    ui->comboBox->insertItem(PRIORTY_NON_PRIMITVE,"Priorty Non Primtive");
    ui->tabWidget->setCurrentIndex(0);

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
/*



*/
    ui->setupUi(this);
    inputdialog = new  InputDialog();
    SetComboBox();

    chart = new Charts_Representation();
    chart->SetChart_Title();
    chart->addProcess("p1",0,1,1);
    chart->addProcess("P2",3,2,2);
    chart->addProcess("p3",4,7,3);

    chart->Chartsettings();

// x does not name type mean it's not know how many bytes will be allocate

}

MainWindow::~MainWindow()
{
    delete chart;
    delete ui;
}

 void MainWindow:: add()
{
    ui->listWidget->addItem("Process "+QString::number(ui->listWidget->count()));
}

void MainWindow::on_AddProcess_clicked()
{
  //  bool ok;
    // ui->listWidget->addItem("Process "+QString::number(ui->listWidget->count()));
 /*      l.push("Process",
              QInputDialog::getInt(this,"Burst time"+QString::number(ui->listWidget->count()),
                                   "time",0,0,1000,1,&ok));*/
 if(inputdialog->exec() == QDialog::Accepted)
{
    ui->listWidget->addItem("Process Name: "+QString::fromStdString(inputdialog->Process_name())+'\t'+
        "Arrival Time: "+QString::fromStdString(inputdialog->ArrivalTime())+'\t'+'\t'+
            "Burst Time: "+QString::fromStdString(inputdialog->BurstTime()));

}
          /* else
               inputdialog->exec();
           qDebug() << QString::fromStdString(inputdialog->Process_name())
                    << QString::fromStdString(inputdialog->ArrivalTime())
                    << QString::fromStdString(inputdialog->BurstTime());*/
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
         ui->verticalLayout_3->addWidget(chart->ViewChart());
        break;
    case 1 :
        ui->lcdNumber->display(66);
        break;
    default:
        break;
    }

}

