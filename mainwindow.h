#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include"schedulerAlgorithms.h"
#include"GraphicalCharts/charts_representation.h"
#include"Macros_Definitions.h"
#include"inputdialog.h"
#include"SchedulerAlgorithms/Round_Robin.h"
#include"SchedulerAlgorithms/FCFS.h"
#include"SchedulerAlgorithms/SJF_Twice.h"
#include"SchedulerAlgorithms/Priorty_Twice.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Charts_Representation;
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    void SetComboBox();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void  add();
    void on_AddProcess_clicked();
    void on_RemoveProcess_clicked();
    void on_Run_clicked();
protected:
    Charts_Representation *chart;
    Ui::MainWindow *ui;
    RoundRobin roundrobin;
    FCFS fcfs;
    PriortyTwice::Priorty_Twice priorty;
    SJF_TWICE::SJF_Twice sjf;
    InputDialog *inputdialog;
};
#endif // MAINWINDOW_H
