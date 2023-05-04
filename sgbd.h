#ifndef SGBD_H
#define SGBD_H

#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>


#include "ads1115.h"


class SGBD : public QObject
{
    Q_OBJECT

private:
      QSqlDatabase db;
      QDateTime * now;
      Ads1115 ads;
      int idStation_;
      int tauxEchant_;


public:
    SGBD();
    ~SGBD();

    int getIdStaion() {return idStation_;}
    int getTauxEchantillonage() { return tauxEchant_;}
    //void Connecter();

public slots:

    void DatabaseConnect();
    void DatabaseConnect(QSqlDatabase &db_);
   // void DatabaseInit();
    //void DatabasePopulate();
    void DatabaseSelectS();
    void DatabaseRecord(int value);
    void DatabaseSelectR();
    void DatabaseDeconnecter();


};

#endif // SGBD_H


