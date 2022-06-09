#ifndef INPUT_H
#define INPUT_H

#include <QWidget>
#include "QSqlDatabase"
#include "QSqlQueryModel"

namespace Ui {
class Input;
}

class Input : public QWidget
{
    Q_OBJECT

public:
    explicit Input(QWidget *parent = nullptr);
    ~Input();
    bool M_Sql_Add(QSqlDatabase &m_db,QString m_name,int m_num, QString date);
    bool M_Sql_Update(QSqlDatabase &m_db,QString m_name, QString m_type, int m_num,QString m_date);
    bool Check_Same(QSqlDatabase &m_db,QString m_name, QString m_type, QString m_date);
    int M_Sql_Id(QSqlDatabase &m_db);
    //建立数据库
    QSqlDatabase db;
   void Clear_Text();
   unsigned char Search_Check();
   bool Search_Show(QSqlDatabase &m_db,uchar Check);
   QTime *m_time;
  QSqlQueryModel *model;
private slots:
    void on_cancel_clicked();

    void on_btn_in_clicked();
    void Timer_Handle();
    void on_btn_in_2_clicked();

    void on_btn_in_3_clicked();

private:
    Ui::Input *ui;

    //获取当地时间
    QString now_time;
    //输入预处理函数
    bool Pretre_Handle(int Type);
    //输入姓名
    QString m_name;
    //输入的字符金额缓冲
    QString Str ;
    //输入缓冲金额
    int m_num ;
    //输入的日期缓冲
    QString m_Date;
    //添加类型
    QString Select_Type;
    //当前ID
    int ID;
    //操作的类型
    enum {
      ADD  = 0  ,
      Update   ,
      Search
    };
signals:
    void Delate_Win(QString win);
    void Text_Message(QString Message);
};

#endif // INPUT_H
