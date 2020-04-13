#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = nullptr);
    ~InputDialog();
std::string Process_name();
std::string BurstTime();
std::string ArrivalTime();
private slots:

    void on_Submit_clicked();

    void on_Cancle_clicked();

private:
    std::string processname;
    std::string burrsttime;
    std::string arrivaltime;

    Ui::InputDialog *ui;
};

#endif // INPUTDIALOG_H
