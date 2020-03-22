#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"schedulerAlgorithms.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void  add();

    void on_AddProcess_clicked();

    void on_RemoveProcess_clicked();

    void on_Run_clicked();
void hey();


private:
    Ui::MainWindow *ui;
    Algorithms l;
};
#endif // MAINWINDOW_H
