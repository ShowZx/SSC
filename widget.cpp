#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    //serv=new ServeurTCP(6000);
     serv=new ServeurTCP(6000);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::RecevoirMessage(QByteArray Message){
    qDebug()<<Message;
    ui->ok->setText(Message);
}
