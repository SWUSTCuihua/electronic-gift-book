#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlDatabase"
#include "QDebug"
#include "QFont"
#include "QTimer"
#include "QTime"
#include "QBitmap"
#include "QMessageBox"
#include "QFile"
#include "QDir"
#include "QDate"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     Init_All();

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
*功能：初始化控件
*
*/
void MainWindow::Init_All()
{
    //界面启动测试当前电脑含有的sql驱动
    ui->textBrowser->append(QStringLiteral("当前电脑包含以下数据库驱动："));
    QStringList drivers = QSqlDatabase::drivers();
    foreach (QString driver, drivers) {
        ui->textBrowser->append(driver);
    }
    Message_Show(QStringLiteral("END"));

    QTimer *timer = new QTimer();
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(Time_Handle()));

}

/*
*功能：定时器函数
*
*/
void MainWindow::Time_Handle()
{
    static int sec=0, min=0;
    sec++;
    if(sec>=60)
    {
        min++;
        if(min>20)
        {
            min=0;
            Copy_File();
        }
    }
}

/*
*功能：文件定时备份处理
*
*/
void MainWindow::Copy_File()
{
    static int count=0;
   //QFile::copy(dir1.path()+"/"+copyfile_name,dir2.path()+"/"+copyfile_name))
    QString time = QDate::currentDate().toString();
    QString path =QDir::currentPath(); //  获取当前工程目录
    qDebug()<<path+"/"+"mydata.db";
    qDebug()<<path+"/"+"BackUp"+"/"+time+"_Backup.db";
    QFile::copy(path+"/"+"mydata.db",path+"/"+"BackUp"+"/"+time.simplified()+QString::number(count)+"_Backup.db");
    count++;
}
/*
*功能：关闭窗口功能。根据槽函数返回类型判别关闭哪个窗口，同时使能按钮
*
*
*/
void MainWindow::on_pushButton_clicked()
{
   m_input = new Input;
  //添加窗口
  ui->horizontalLayout_2->addWidget(m_input);
  //信号和槽的建立一定先有实例化对象后才能建立

   connect(m_input,SIGNAL(Delate_Win(QString)),this,SLOT(Delate_Win(QString)));
   connect(m_input,SIGNAL(Text_Message(QString)),this,SLOT(Message_Show(QString)));

   ui->pushButton->setEnabled(false);
   Message_Show(QStringLiteral("打开“账目输入窗口”！"));
}

/*
*功能：用于窗口信息的打印，通过槽函数实现
*
*
*/
void MainWindow::Message_Show(QString Message)
{
    ui->textBrowser->append(Message);
}

/*
*功能：关闭窗口功能。根据槽函数返回类型判别关闭哪个窗口，同时使能按钮
*
*
*/
void MainWindow::Delate_Win(QString m_Win)
{
   if(m_Win=="input")
   {

     ui->pushButton->setEnabled(true);
     delete  m_input;
     Message_Show(QStringLiteral("关闭“账目输入”窗口！"));
   }
   else if(m_Win=="total")
   {
     ui->pushButton_2->setEnabled(true);
     delete m_total;
     Message_Show(QStringLiteral("关闭“总账查询”窗口！"));
   }
}

/*
*功能：新建总账查询窗口
*
*/
void MainWindow::on_pushButton_2_clicked()
{
    //新建窗口前，需要检查是否已经连接数据库。
    QSqlDatabase db = QSqlDatabase::database("M_DATA");
    Message_Show(QStringLiteral("正在连接数据库..."));
    if(!db.open())
    {
         QMessageBox::information(this, QStringLiteral("提示"),
          "请先点击“账目输入”按钮！ ", QMessageBox::Cancel);
         Message_Show(QStringLiteral("连接数据库失败！"));
         return;
    }
    Message_Show(QStringLiteral("连接数据库成功！"));
    m_total = new Total();
    //添加窗口
    ui->horizontalLayout_2->addWidget(m_total);

    connect(m_total,SIGNAL(Delate_Win(QString)),this,SLOT(Delate_Win(QString)));
    connect(m_total,SIGNAL(Text_Message(QString)),this,SLOT(Message_Show(QString)));
    ui->pushButton_2->setEnabled(false);
    Message_Show(QStringLiteral("打开“总账查询”窗口！"));
}

void MainWindow::on_pushButton_3_clicked()
{
    Copy_File();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textBrowser->clear();
}
