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
    ui->comboBox->insertItem(FCFS_,"FCFS");
    ui->comboBox->insertItem(SJF_PRIMITVE_,"SJF Premitive");
    ui->comboBox->insertItem(SJF_NON_PRIMITVE_,"SJF Non Premitive");
    ui->comboBox->insertItem(PRIORTY_PRIMITVE_,"Priorty Primtive");
    ui->comboBox->insertItem(PRIORTY_NON_PRIMITVE_,"Priorty Non Primtive");
    ui->comboBox->insertItem(ROUND_ROBEB_,"Round Roben");
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
// if( ui->comboBox->currentIndex() == PRIORTY_PRIMITVE_ ||
//           ui->comboBox->currentIndex() == PRIORTY_NON_PRIMITVE_)
//   {
//        QInputDialog::getInt(this,"Time","Process Priority number",1,1,100,1);
//   }
 switch (ui->comboBox->currentIndex()) {
 case FCFS_:
     fcfs.set_new_process(inputdialog->Process_name(),atoi(inputdialog->BurstTime().c_str()),atoi(inputdialog->ArrivalTime().c_str()));
     break;
 case  SJF_PRIMITVE_:
sjf.set_new_process(inputdialog->Process_name(),atoi(inputdialog->BurstTime().c_str()),atoi(inputdialog->ArrivalTime().c_str()));
     break;
 case  SJF_NON_PRIMITVE_:
     sjf.set_new_process(inputdialog->Process_name(),atoi(inputdialog->BurstTime().c_str()),atoi(inputdialog->ArrivalTime().c_str()));
     break;
 case  PRIORTY_PRIMITVE_:
priorty.set_new_process(inputdialog->Process_name(),
                        atoi(inputdialog->BurstTime().c_str()),
                        atoi(inputdialog->ArrivalTime().c_str()),
                        QInputDialog::getInt(this,"Time","Process Priority number",1,1,100,1));
     break;
 case  PRIORTY_NON_PRIMITVE_:
     priorty.set_new_process(inputdialog->Process_name(),
                             atoi(inputdialog->BurstTime().c_str()),
                             atoi(inputdialog->ArrivalTime().c_str()),
                             QInputDialog::getInt(this,"Time","Process Priority number",1,1,100,1));
     break;
 case ROUND_ROBEB_:
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
    case FCFS_:
       fcfs.first_come_first_serve();
       ui->lcdNumber->display(QString::number(roundAllNumbers(fcfs.average_waiting_time())));
       for(auto& a:fcfs.return_ready_queue())
        {
      chart->addProcess(a.name,a.starting_time,a.end_time,a.index);
         }
      chart->Chartsettings();
      ui->verticalLayout_3->addWidget(chart->ViewChart());
        break;

    case  SJF_PRIMITVE_:
    sjf.shorted_job_first_preemptive();
    ui->lcdNumber->display(QString::number(roundAllNumbers(sjf.average_waiting_time())));
    for(auto& a:sjf.return_ready_queue())
    {
      chart->addProcess(a.name,a.starting_time,a.end_time,a.index);
    }
    chart->Chartsettings();
    ui->verticalLayout_3->addWidget(chart->ViewChart());
        break;

    case  SJF_NON_PRIMITVE_:
        sjf.shorted_job_first_non_preemptive();
        ui->lcdNumber->display(QString::number(roundAllNumbers(sjf.average_waiting_time())));
       for(auto& a:sjf.return_ready_queue())
        {
      chart->addProcess(a.name,a.starting_time,a.end_time,a.index);
         }
        chart->Chartsettings();
        ui->verticalLayout_3->addWidget(chart->ViewChart());
       break;

    case  PRIORTY_PRIMITVE_:
    priorty.preemptive();
    ui->lcdNumber->display(QString::number(roundAllNumbers(priorty.average_waiting_time())));
    for(auto& a:priorty.return_ready_queue())
     {
   chart->addProcess(a.name,a.starting_time,a.end_time,a.index);
      }
    chart->Chartsettings();
    ui->verticalLayout_3->addWidget(chart->ViewChart());

        break;

    case  PRIORTY_NON_PRIMITVE_:
        priorty.non_preemptive();
        ui->lcdNumber->display(QString::number(roundAllNumbers(priorty.average_waiting_time())));
        for(auto& a:priorty.return_ready_queue())
         {
       chart->addProcess(a.name,a.starting_time,a.end_time,a.index);
          }
        chart->Chartsettings();
        ui->verticalLayout_3->addWidget(chart->ViewChart());
        break;

    case ROUND_ROBEB_:
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
