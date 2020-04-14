#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTabWidget>
#include<QListWidget>
#include<QString>
#include<QtDebug>
#include<QLCDNumber>
#include<QStringList>
#include<QInputDialog>
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
    ui->comboBox->insertItem(ROUND_ROBEB,"Round Roben");
    ui->tabWidget->setCurrentIndex(0);

}
float roundAllNumbers(float var)
{
    float value = (int)(var*10+.5);
    return (float)value/10;
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inputdialog = new  InputDialog();
    chart = new Charts_Representation();
    SetComboBox();
    chart->SetChart_Title();
    /*chart->addProcess("p1",0,1,1);
    chart->addProcess("P2",3,4,1);
    chart->addProcess("p3",6,7,1);
    chart->addProcess("p3",9,10,1);
    chart->Chartsettings();
    ui->verticalLayout_3->addWidget(chart->ViewChart());*/
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
int ret = inputdialog->exec();
if(ret == QDialog::Accepted)
{
ui->listWidget->addItem("Process Name: "+QString::fromStdString(inputdialog->Process_name())+'\t'+
    "Arrival Time: "+QString::fromStdString(inputdialog->ArrivalTime())+'\t'+'\t'+
        "Burst Time: "+QString::fromStdString(inputdialog->BurstTime()));
}
 if( ui->comboBox->currentIndex() == PRIORTY_PRIMITVE ||
           ui->comboBox->currentIndex() == PRIORTY_NON_PRIMITVE)
   {
        QInputDialog::getInt(this,"Time","Priority number",1,1,100,1);
   }
 switch (ui->comboBox->currentIndex()) {
 case FCFS:
     break;
 case  SJF_PRIMITVE:
     ui->lcdNumber->display(66);
     break;
 case  SJF_NON_PRIMITVE:
     ui->lcdNumber->display(66);
     break;
 case  PRIORTY_PRIMITVE:
     ui->lcdNumber->display(66);
     break;
 case  PRIORTY_NON_PRIMITVE:
     ui->lcdNumber->display(66);
     break;
 case ROUND_ROBEB:
     roundrobin.add_Process(inputdialog->Process_name(),atoi(inputdialog->ArrivalTime().c_str()),atoi(inputdialog->BurstTime().c_str()));
     break;
 default:
     break;

 }
}

void MainWindow::on_RemoveProcess_clicked()
{
     ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void MainWindow::on_Run_clicked()
{

    switch (ui->comboBox->currentIndex()) {
    case FCFS:
        break;
    case  SJF_PRIMITVE:
        ui->lcdNumber->display(66);
        break;
    case  SJF_NON_PRIMITVE:
        ui->lcdNumber->display(66);
        break;
    case  PRIORTY_PRIMITVE:
        ui->lcdNumber->display(66);
        break;
    case  PRIORTY_NON_PRIMITVE:
        ui->lcdNumber->display(66);
        break;
    case ROUND_ROBEB:
        roundrobin.set_QuantumTime(QInputDialog::getInt(this,"Time","Quantum Time",1,1,100,1));
        roundrobin.arrayofProcess_Processing();
        ui->lcdNumber->display(QString::number(roundAllNumbers(roundrobin.avg_Waitting_Time())));
        for (unsigned int i = 0;i < roundrobin.size();i++) {
            chart->drawProcesses(roundrobin.process_start_end(i),i);
        }
        chart->Chartsettings();
        ui->verticalLayout_3->addWidget(chart->ViewChart());
        break;
    default:
        break;
    }

}

