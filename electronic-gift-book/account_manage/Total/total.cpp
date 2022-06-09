#include "total.h"
#include "ui_total.h"
#include "QSqlDatabase"
#include "QDebug"
#include "QTime"
#include "QTimer"
#include "QMessageBox"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QSqlTableModel"
#include "QTableView"

Total::Total(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Total)
{
    ui->setupUi(this);

    m_time = new QTime;
    //设置定时器，1S更新一次时间。
    QTimer *timer1 = new QTimer;
    timer1->start(1000);
    connect(timer1,SIGNAL(timeout()),this,SLOT(Timer_Handle()));

    Init();
}

Total::~Total()
{
    delete ui;
}
void Total::Timer_Handle()
{

    now_time = m_time->currentTime().toString();

}
/*
*功能：初始化数据库，并建立连接。此处已经建立数据库连接。
*
*/
void Total::Init()
{
    int num=0, Out_Max=0,In_Max=0,Output_num=0,Input_num=0;
    QString OM_name,IM_name,OM_date,IM_date;
    db = QSqlDatabase::database("M_DATA");
    QSqlQuery query(db);
    query.exec("select * from person ");
    while(query.next())
    {
       num = query.value(3).toInt();
       if(num>0)
        {
           Input_num += num;
           if(num>In_Max)
           {
               In_Max = num;
               IM_name = query.value(1).toString();
               IM_date = query.value(4).toString();
           }
       }
       else
       {
           Output_num += -num;
           if(num<Out_Max)
           {
               Out_Max = num;
               OM_name = query.value(1).toString();
               OM_date = query.value(4).toString();
           }
       }
    }
    //显示汇总数
    ui->label_3->setNum(Output_num);
    ui->label_4->setNum(Input_num);
    //显示送出最多人
    ui->label_9->setText(OM_name);
    ui->label_7->setNum(-Out_Max);
    ui->label_11->setText(OM_date);
    //显示收入最多人
    ui->label_10->setText(IM_name);
    ui->label_8->setNum(In_Max);
    ui->label_12->setText(IM_date);
}

/*
*功能：查看全部信息。
*
*/
void Total::on_pushButton_clicked()
{

    QSqlTableModel *model = new QSqlTableModel(NULL,db);
    model->setTable("person");
    model->select();

    QTableView * view = new QTableView();
    view->setModel(model);
    view->show();
}


/*
*功能：关闭窗口按钮。
*
*/
void Total::on_pushButton_2_clicked()
{
     emit Delate_Win("total");
}

/*
*功能：手动刷新数据按钮。
*
*/
void Total::on_pushButton_3_clicked()
{
    Init();
    emit Text_Message(now_time+" "+QStringLiteral("已刷新！"));
}
