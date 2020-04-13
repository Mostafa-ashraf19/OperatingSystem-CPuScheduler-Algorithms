#include "inputdialog.h"
#include "ui_inputdialog.h"
#include<QMessageBox>
InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent,Qt::WindowSystemMenuHint|Qt::WindowTitleHint),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
}

InputDialog::~InputDialog()
{
    delete ui;
}

std::string InputDialog::Process_name()
{
    return  processname;
}

std::string InputDialog::BurstTime()
{
    return  burrsttime;
}

std::string InputDialog::ArrivalTime()
{
    return arrivaltime;
}

void InputDialog::on_Submit_clicked()
{
    std::string name = ui->processname->text().toStdString();
    std::string arrvtime = ui->Arrivaltime->text().toStdString();
    std::string burtime= ui->Bursttime->text().toStdString();
    if( name.empty() || arrvtime.empty() || burtime.empty())
       {
        if(QMessageBox::Ok ==
               QMessageBox::critical(this,"Empty Fields","Please Fill All Inputs"))
        {
            reject();
        }
      }
    else
    {
        processname=name;
        arrivaltime=arrvtime;
        burrsttime=burtime;

        ui->Arrivaltime->clear();
        ui->Bursttime->clear();
         ui->processname->clear();
         accept();
    }

}

void InputDialog::on_Cancle_clicked()
{
    reject();
}
