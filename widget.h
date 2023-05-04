#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QDateTime>
#include <QVector>

#include "serveurtcp.h"
#include "clienttcp.h"
#include "sgbd.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;



    ServeurTCP *serv;





public slots:
    void RecevoirMessage(QByteArray Message);
    //void connexion();
    //void jesaispas();
};

#endif // WIDGET_H
