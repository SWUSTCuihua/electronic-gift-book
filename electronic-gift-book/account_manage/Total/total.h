#ifndef TOTAL_H
#define TOTAL_H

#include <QWidget>
#include "QSqlDatabase"
namespace Ui {
class Total;
}

class Total : public QWidget
{
    Q_OBJECT

public:
    explicit Total(QWidget *parent = nullptr);
    ~Total();
    void Init();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

     void Timer_Handle();
private:
    Ui::Total *ui;
    //获取当地时间
    QString now_time;
    QTime *m_time;
    QSqlDatabase db;
signals:
    void Delate_Win(QString win);
    void Text_Message(QString text);
};

#endif // TOTAL_H
