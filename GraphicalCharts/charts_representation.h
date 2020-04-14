#ifndef CHARTS_REPRESENTATION_H
#define CHARTS_REPRESENTATION_H

#include"mainwindow.h"

// Manages the applications main settings like
// widget initialization
#include <QApplication>
// The main window to which you add toolbars,
// menubars, widgets and status bar
#include <QtWidgets/QMainWindow>
// Widget used to display charts
#include <QtCharts/QChartView>
// Used to draw bars representing data provided
// grouped into categories
#include <QtCharts/QBarSeries>
// Represents 1 set of bars in a bar chart
#include <QtCharts/QBarSet>
// Displays the color used to represent each
// QBarSet
#include <QtCharts/QLegend>
// Used to create a line chart
#include <QtCharts/QLineSeries>
// Used to change names on axis
#include <QtCharts/QCategoryAxis>
#include<QtCharts/QAbstractBarSeries>
#include<QtCharts/QAbstractAxis>
// Define the scope for your variables and functions
QT_CHARTS_USE_NAMESPACE

#include<vector>

class Charts_Representation
{

    std::vector<QLineSeries *>  Series;
    QChart *chart;
    int current;
    QChartView* chartview;
    void ChartView_settings();
    QAbstractAxis* axis;
public:
    explicit Charts_Representation();
    ~Charts_Representation();
    void addProcess(std::string Process_name,
                    qreal From_X_Position,
                     qreal To_X_Position,
                    qreal _Process_index);
     void Chartsettings();
     QChartView* ViewChart();
    void SetChart_Title();
    void drawProcesses(std::pair<std::vector<int>,std::vector<int>> Process,int index);

};

#endif // CHARTS_REPRESENTATION_H
