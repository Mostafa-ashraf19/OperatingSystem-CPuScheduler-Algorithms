#include "charts_representation.h"
#include"ui_mainwindow.h"
void Charts_Representation::ChartView_settings()
{
current=0;
chartview->setRenderHint(QPainter::Antialiasing);
axis->setTitleText("Hello thier");
chart->setAxisX(axis);
}

Charts_Representation::Charts_Representation()
{
    chart = new QChart();
    chart->legend()->hide();
    chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    //SetChart_Title();
}

Charts_Representation::~Charts_Representation()
{
   // delete chart;
    //delete chartview;
}

void Charts_Representation::addProcess(std::string Process_name,
                                       qreal From_X_Position,
                                        qreal To_X_Position,
                                       qreal _Process_index)
{
    Series.push_back(new QLineSeries);
    for(static unsigned int i= 0; i <Series.size();i++)
    {
    Series[i]->append(From_X_Position,_Process_index);
    Series[i]->append(To_X_Position,_Process_index);
    }
}

void Charts_Representation::Chartsettings()
{


    for(unsigned int i=0;i< Series.size();i++)
        chart->addSeries(Series[i]);
    chart->createDefaultAxes();

}

QChartView *Charts_Representation::ViewChart()
{
    return  chartview;
}

void Charts_Representation::SetChart_Title()
{
    chart->setTitle("Process Drawing Simulation");
}

void Charts_Representation::drawProcesses(std::pair<std::vector<int>, std::vector<int> > Process, int index)
{
    for(unsigned int k = 0;k < Process.first.size();k++)
    {
        addProcess("m",Process.first[k],Process.second[k],index);
    }
}
