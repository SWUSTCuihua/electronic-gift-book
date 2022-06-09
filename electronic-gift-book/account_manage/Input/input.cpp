#include "input.h"
#include "ui_input.h"
#include "QMessageBox"
#include "QSqlDatabase"
#include "QSqlQueryModel"
#include "QSqlTableModel"
#include "QTableView"
#include "QSqlQuery"
#include "QTime"
#include "QDebug"
#include "QTimer"
#include "QSqlRecord"


Input::Input(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Input)
{
     ui->setupUi(this);

     //创建定时器，每1S更新一次时间
     QTimer *timer = new QTimer;
     timer->start(1000);
     connect(timer,SIGNAL(timeout()),this,SLOT(Timer_Handle()));
     m_time = new QTime;

    //测试当前电脑含有的数据库
    //提前建立好数据库,如果有，则直接连接，如果没有，则重新创建
     qDebug()<< QStringLiteral("正在连接数据库...");
     qDebug()<<QStringLiteral("正在创建表...");
     //注意，这里使用默认连接，没有命名。因为要用到qt自带的sqltable库，只能用默认连接才能正常显示。
     db = QSqlDatabase::addDatabase("QSQLITE","M_DATA");
     //这里输入你的数据库名
     db.setHostName("OU");
     db.setDatabaseName("mydata.db");
     if (!db.open())
     {
         qDebug()<<(now_time + "    " + QStringLiteral(" 无法打开数据库 "));
         QMessageBox::critical(this, QStringLiteral("无法打开数据库"),
         "无法创建数据库连接！ ", QMessageBox::Cancel);
     }
     QSqlQuery query(db);
     // 创建表
     query.exec("create table person (id int primary key, name varchar(20), type varchar(10) ,num int , date varchar(15))");

     qDebug()<<QStringLiteral( "创建完成！");

}

/*
*功能：析构函数
*
*/
Input::~Input()
{
    delete ui;
}


void Input::Timer_Handle()
{
    now_time = m_time->currentTime().toString();
}

/*
*功能：删除实例化对象
*
*/
void Input::on_cancel_clicked()
{
   emit Delate_Win("input");
}


void Input::Clear_Text()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();

}
bool Input::Pretre_Handle(int Type)
{
    //判别送出还是收入
   int Dir;
   if(Type==ADD||Type==Update)
   {
       if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty())
       {
          QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("输入内容不能为空，请重新输入！"),QMessageBox::Ok);
          return false;
       }
   }
   Select_Type = ui->comboBox->currentText();
   if(Select_Type=="送出"||Select_Type=="送出（代）")
       Dir = -1 ;
   else
       Dir = 1 ;
   //输入的姓名缓冲
    m_name = ui->lineEdit->text();
   //输入的金额缓冲
   Str = ui->lineEdit_2->text();
   m_num =  Str.toInt();
   m_num = Dir*m_num;
   //输入的日期缓冲
   m_Date = ui->dateEdit->text();

   return true;
}
/*
*功能：数据库进行封装处理：确认添加按钮函数
*补充：后期需添加多个用户时，需要指定对应的数据库连接
*/
void Input::on_btn_in_clicked()
{

   if(Pretre_Handle(ADD)&&M_Sql_Add(db,m_name,m_num,m_Date))
    {
       emit Text_Message(now_time + " " +  Select_Type +" " +m_name +"-"+ Str+"-"+m_Date +" "+ QStringLiteral("已入库"));
       QMessageBox::information(this,QStringLiteral("提示"),
                               QStringLiteral("添加数据成功!"),QMessageBox::Ok);
   }
       else
    {
       emit Text_Message(now_time + " " + QStringLiteral(" 添加数据失败，请重新输入 "));
   }
}

/*
*功能：数据库进行封装处理：添加名额
*返回：1：添加成功  0：添加失败
*/
bool Input::M_Sql_Add(QSqlDatabase &m_db,QString m_name,int m_num, QString date)
{

    QSqlQuery query(m_db);
    bool same_name;
    int select;
    int temp_id;
    temp_id = M_Sql_Id(m_db);
    same_name = Check_Same(m_db,m_name,Select_Type,date);
    if(same_name)
    {
        select = QMessageBox::warning(this,QStringLiteral("提示"),
                            QStringLiteral("输入名字以及对应日期已存在，如果想修改，请选择修改按钮；"
                            "如果同名同姓，请在名字后添加备注"),QMessageBox::Cancel);
        return false;
    }
    else
    {
        query.exec(QString ("insert into person(id,name,type,num,date) values('%1','%2','%3','%4','%5')").arg(temp_id+1).arg(m_name).arg(Select_Type).arg(m_num).arg(date));
        Clear_Text();
        return true;
    }

}

/*
*功能：数据库进行封装处理：检查数据库中是否有相同的输入项
*返回：1：有同名同姓  0：无同名同姓
*/
bool Input::Check_Same(QSqlDatabase &m_db,QString m_name, QString m_type, QString m_date)
{

    QSqlQuery query(m_db);
    query.exec(QString("select * from person"));
    QSqlRecord rec = query.record();
    //移动到查询结果的下一条记录
    while(query.next())
    {
        //数据库读取的名字需要去掉空格
        int t_name = rec.indexOf("name");
        int t_date = rec.indexOf("date");
        int num = rec.indexOf("num");
        int t_type = rec.indexOf("type");
        int temp_num = query.value(num).toInt();
        QString temp_type = query.value(t_type).toString();
        QString temp_name = query.value(t_name).toString();
        QString temp_date = query.value(t_date).toString();
        qDebug()<<"name:"<<temp_name<<" date: "<<temp_date;
        if(temp_name==m_name&&temp_date==m_date&&m_type==temp_type)
        {
          emit Text_Message(now_time + " " + QStringLiteral("已存在添加记录: ")+ m_name +" "+
                       temp_type+ " " + QString::number(temp_num)+" "+temp_date);
          return true;
        }
    }
    return false;
}

/*
*功能：数据库进行封装处理：返回数据库的最大id值，用于
*返回：1：修改成功 0：修改失败
*/
int Input::M_Sql_Id(QSqlDatabase &m_db)
{
    QSqlQuery query(m_db);
    query.exec(QString("select id from person"));
    QSqlRecord rec = query.record();
    //移动到查询结果的下一条记录
    if(query.last())
    {
       int t_ID = rec.indexOf("id");
       return query.value(t_ID).toInt();
    }
    else
       return false;
}

/*
*功能：数据库进行封装处理：检查数据库中是否有相同的输入项,有则修改，无则退出
*返回：1：修改成功 0：修改失败
*/
bool Input::M_Sql_Update(QSqlDatabase &m_db,QString m_name, QString m_type,int m_num, QString m_date)
{
    QSqlQuery query(m_db);
    query.exec(QString("select * from person"));
    QSqlRecord rec = query.record();
    emit Text_Message(QStringLiteral("查询到此人记录如下："));
    //移动到查询结果的下一条记录
    while(query.next())
    {
        //数据库读取的名字需要去掉空格
        int t_name = rec.indexOf("name");
        int t_date = rec.indexOf("date");
        int t_ID = rec.indexOf("id");
        int t_num = rec.indexOf("num");
        int t_type = rec.indexOf("type");
        QString temp_type = query.value(t_type).toString();
        int temp_id = query.value(t_ID).toInt();
        int temp_num = query.value(t_num).toInt();
        QString temp_name = query.value(t_name).toString();
        QString temp_date = query.value(t_date).toString();
        qDebug()<<"name:"<<temp_name<<" date: "<<temp_date;
        if(temp_name==m_name)
        {
            Text_Message(QString::number(temp_id)+" "+temp_name
                         +" "+QString::number(temp_num)+" "+temp_date);
           if(temp_date==m_date&&temp_type==m_type)
           {
              int Box = QMessageBox::information(this,QStringLiteral("提示"),
                                           QStringLiteral("是否确认修改？"),QMessageBox::Ok|QMessageBox::Cancel);
              if(Box==QMessageBox::Ok)
              {
                query.exec(QString("update person set type = %1 where id = %2").arg(m_type).arg(t_ID));
                query.exec(QString("update person set  num = %1 where id = %2").arg(m_num).arg(t_ID));
                return true;
              }
              else
                return false;

           }
        }
    }
    return false;
}

/*
*功能：修改数据库按钮,人机交互反馈
*返回：无
*/
void Input::on_btn_in_2_clicked()
{
   if(Pretre_Handle(Update)&&M_Sql_Update(db,m_name, Select_Type,m_num,m_Date))
    {
       emit Text_Message(now_time + " " +  Select_Type +" " +m_name +"-"+ Str+"-"+m_Date +" "+ QStringLiteral("已修改"));
       QMessageBox::information(this,QStringLiteral("提示"),
                               QStringLiteral("修改数据成功!"),QMessageBox::Ok);
   }
    else
   {
       emit Text_Message(now_time + " " + QStringLiteral(" 修改数据失败，请重新输入 "));
       QMessageBox::warning(this,QStringLiteral("提示"),
                               QStringLiteral("修改数据失败，请重新输入!"),QMessageBox::Ok);
   }
}

/*
*功能：判断查找所勾选的选项
*返回：uchar
*/
unsigned char Input::Search_Check()
{
    unsigned char i=0, temp =0;
    temp =0;
    for(i=0;i<4;i++)
    {
        switch(i)
        {
            //时间选择
            case 0:
             if(ui->checkBox->checkState())
                   temp|=0x01;
            break;
            //类型选择
            case 1:
               if(ui->checkBox_2->checkState())
                    temp|=0x02;
            break;
            //金额选择
            case 2:
               if(ui->checkBox_3->checkState())
               {
                   if(ui->lineEdit_2->text().isEmpty())
                   {
                       QMessageBox::warning(this,QStringLiteral("提示"),
                                               QStringLiteral("已勾选金额选项，不能为空!"),QMessageBox::Ok);
                       return 0xff;
                   }
                    else
                       temp|=0x04;
               }
            break;
            //姓名选择
            case 3:
               if(ui->checkBox_4->checkState())
                   {
                      if(ui->lineEdit->text().isEmpty())
                      {
                          QMessageBox::warning(this,QStringLiteral("提示"),
                                                  QStringLiteral("已勾选姓名选项，不能为空!"),QMessageBox::Ok);
                          return 0xff;
                      }
                      else
                         temp|=0x08;
                    }
            break;
           default:
            break;
        }
    }
    return temp;
}

/*
*功能：查询按钮
*返回：
*/
void Input::on_btn_in_3_clicked()
{
    uchar temp = Search_Check();
    if(temp==0xff)
        return ;
    qDebug()<<"temp:"<<temp;
    if(Pretre_Handle(Search)&&Search_Show(db,temp))
        emit  Text_Message(now_time+" "+QStringLiteral("查询完成！"));
    else
        emit  Text_Message(now_time+" "+QStringLiteral("无记录！"));
}

/*
*功能：查询函数
*返回：
*/
bool Input::Search_Show(QSqlDatabase &m_db,uchar Check)
{
    int count=0;
    QSqlQuery query(m_db);
    if((Check&0x08)==0x08)
    {
        if((Check&0x04)==0x04)
        {
            if((Check&0x02)==0x02)
            {
                if((Check&0X01)==0x01)
                {
                   //1，2，3，4
                    query.exec(QString("select * from person where name='%1'and num='%2' and type='%3' and date='%4'").arg(m_name).arg(m_num).arg(Select_Type).arg(m_Date));
                    QSqlRecord rec = query.record();
                    emit  Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message( QString::number(temp_id)+" "+ temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
                else
                {
                   //1，2，3
                    query.exec(QString("select * from person where name='%1'and num='%2' and type='%3'").arg(m_name).arg(m_num).arg(Select_Type));
                    QSqlRecord rec = query.record();
                    emit Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message(QString::number(temp_id)+" "+  temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
            }
            else
            {
                if(Check&0X01)
                {
                  //1，2，4
                    query.exec(QString("select * from person where name='%1'and num='%2' and date='%3'").arg(m_name).arg(m_num).arg(m_Date));
                    QSqlRecord rec = query.record();
                    emit Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message(QString::number(temp_id)+" "+  temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
                else
                {
                  //1，2
                    query.exec(QString("select * from person where name='%1'and num='%2'").arg(m_name).arg(m_num));
                    QSqlRecord rec = query.record();
                    emit Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message(QString::number(temp_id)+" "+  temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
            }
        }
        //不要2
        else
        {
            if(Check&0x02)
            {
                if(Check&0X01)
                {
                   //1，3，4
                    query.exec(QString("select * from person where name='%1'and type='%2' and date='%3'").arg(m_name).arg(Select_Type).arg(m_Date));
                    QSqlRecord rec = query.record();
                    emit  Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message(QString::number(temp_id)+" "+  temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
                else
                {
                   //1，3
                    query.exec(QString("select * from person where name='%1'and type='%2'").arg(m_name).arg(Select_Type));
                    QSqlRecord rec = query.record();
                    emit  Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message(QString::number(temp_id)+" "+  temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
            }
            else
            {
                if(Check&0X01)
                {
                   //1，4
                    query.exec(QString("select * from person where name='%1'and date='%2'").arg(m_name).arg(m_Date));
                    QSqlRecord rec = query.record();
                    emit  Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message(QString::number(temp_id)+" "+  temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
                else
                {
                   //1
                    query.exec(QString("select * from person where name='%1'").arg(m_name));
                    QSqlRecord rec = query.record();
                    emit  Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message(QString::number(temp_id)+" "+  temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
            }
        }
    }
    else
    {
        if(Check&0x04)
        {
            if(Check&0x02)
            {
                if(Check&0X01)
                {
                   //2，3，4
                    query.exec(QString("select * from person where num='%1' and type='%2' and date='%3'").arg(m_num).arg(Select_Type).arg(m_Date));
                    QSqlRecord rec = query.record();
                    emit  Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message( QString::number(temp_id)+" "+ temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
                else
                {
                   //2，3，
                    query.exec(QString("select * from person where num='%1' and type='%2'").arg(m_num).arg(Select_Type));
                    QSqlRecord rec = query.record();
                    emit  Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message( QString::number(temp_id)+" "+ temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
            }
            else
            {
                if(Check&0X01)
                {
                   //2，4
                    query.exec(QString("select * from person where num='%1' and date='%2'").arg(m_num).arg(m_Date));
                    QSqlRecord rec = query.record();
                    emit  Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message( QString::number(temp_id)+" "+ temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
                else
                {
                   //2，
                    query.exec(QString("select * from person where num='%1'").arg(m_num));
                    QSqlRecord rec = query.record();
                    emit  Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message( QString::number(temp_id)+" "+ temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
            }
        }
        //不要2
        else
        {
            if(Check&0x02)
            {
                if(Check&0X01)
                {
                   //3，4
                    query.exec(QString("select * from person where type='%1' and date='%2'").arg(Select_Type).arg(m_Date));
                    QSqlRecord rec = query.record();
                    emit  Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message( QString::number(temp_id)+" "+ temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
                else
                {
                   //3，
                    query.exec(QString("select * from person where type='%1'").arg(Select_Type));
                    QSqlRecord rec = query.record();
                    emit  Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message( QString::number(temp_id)+" "+ temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
            }
            else
            {
                if(Check&0X01)
                {
                   //4
                    query.exec(QString("select * from person where date='%2'").arg(m_Date));
                    QSqlRecord rec = query.record();
                    emit  Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message( QString::number(temp_id)+" "+ temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
                else
                {
                   //0
                    query.exec(QString("select * from person"));
                    QSqlRecord rec = query.record();
                    emit  Text_Message(QStringLiteral("查询到此人记录如下："));
                    //移动到查询结果的下一条记录
                    while(query.next())
                    {
                        count++;
                        //数据库读取的名字需要去掉空格
                        int t_name = rec.indexOf("name");
                        int t_date = rec.indexOf("date");
                        int t_ID = rec.indexOf("id");
                        int t_num = rec.indexOf("num");
                        int t_type = rec.indexOf("type");
                        QString temp_type = query.value(t_type).toString();
                        int temp_id = query.value(t_ID).toInt();
                        int temp_num = query.value(t_num).toInt();
                        QString temp_name = query.value(t_name).toString();
                        QString temp_date = query.value(t_date).toString();
                        emit Text_Message( QString::number(temp_id)+" "+ temp_name +" "+temp_type+ " " + QString::number(temp_num)+" "+temp_date);
                    }
                    return count;
                }
            }
        }
    }
}
