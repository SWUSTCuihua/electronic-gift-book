#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Input/input.h"
#include "Total/total.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Init_All();

private slots:
    void on_pushButton_clicked();
    void Delate_Win(QString m_Win);
    void Message_Show(QString Message);

    void on_pushButton_2_clicked();
    void Time_Handle();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Input *m_input;
    Total *m_total;
    void Copy_File();
};
#endif // MAINWINDOW_H
