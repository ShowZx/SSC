#include "sgbd.h"

SGBD::SGBD()
{
DatabaseConnect();
//DatabaseRecord(8);
//DatabaseSelectR();
}
///-----------------------------------------------------------------
SGBD::~SGBD()
{

}
///-----------------------------------------------------------------
//void SGBD::Connecter(){

   // db = QSqlDatabase::addDatabase("QMYSQL");
    //db.setHostName("127.0.0.1");
   // db.setUserName("pi");
  //  db.setPassword("raspberry");
    //db.setDatabaseName("StationSismique");

    //if (db.open())
    //{
      //  qDebug()<<"Vous êtes maintenant connecté ";
        //void Enregistrer(QByteArray data);
   // }

    //else
    //{
        //qDebug()<<"Connexion sgbd echouée";
    //}
//}
///-----------------------------------------------------------------
void SGBD::DatabaseConnect()
{
 //Vérification de la présence du Driver SQLite
 if(QSqlDatabase::isDriverAvailable("QSQLITE"))
 {//Création de la base de données et paramétrage(A approfondire sur les paramètres)
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/mnt/supervisionMWB-V2_Lilian.sqlite");
    //Overture de la base
   if(!db.open())  qWarning()<<"MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();

 }
 else
 {
  qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << "QSQLITE" << " available";
 }
}
///-----------------------------------------------------------------
void SGBD::DatabaseConnect(QSqlDatabase &db_)
{
 //Vérification de la présence du Driver SQLite
 if(QSqlDatabase::isDriverAvailable("QSQLITE"))
 {//Création de la base de données et paramétrage(A approfondire sur les paramètres)
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/mnt/supervisionMWB-V2_Lilian.sqlite");
    //Overture de la base
   if(!db.open())  qWarning()<<"MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
   db_ = db;

 }
 else
 {
  qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << "QSQLITE" << " available";
 }
}
///-----------------------------------------------------------------
void SGBD::DatabaseSelectS()
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM station ");
    //query.addBindValue(mInputText->text().toInt());

    if(!query.exec())
      qWarning() << "ERROR: " << query.lastError().text();
    /* A utiliser si il n'y a qu'une valeur a trouver.
     if(query.first())
      ui->textEdit->setText(query.value(0).toString());*/

    while(query.next())
    {
       // ui->textEdit->append(query.value(i).toString());
        qDebug()<< query.value("longitude") << " " << query.value("latitude") << " "<< query.value("tauxechantillonage") << " " << query.value("nom")<< query.value("idStation");
    }

}
///-----------------------------------------------------------------
void SGBD::DatabaseRecord(int value){
    QString time_format = "MM-dd-yyyy  HH:mm:ss.sss";
    QString _datetime=QDateTime::currentDateTime().toString(time_format);
      QSqlQuery query(db);
    query.prepare("INSERT INTO releve(data,datetime,Station_idStation) VALUES( ? , ? , ?)");
    query.bindValue(0,value);
    query.bindValue(1,_datetime);
    query.bindValue(2,idStation_);
    qDebug()<<query.exec();
}
///-----------------------------------------------------------------
void SGBD::DatabaseSelectR(){
    QSqlQuery query(db);
    query.prepare("SELECT * FROM releve ");
    //query.addBindValue(mInputText->text().toInt());

    if(!query.exec())
      qWarning() << "ERROR: " << query.lastError().text();
    /* A utiliser si il n'y a qu'une valeur a trouver.
     if(query.first())
      ui->textEdit->setText(query.value(0).toString());*/

    while(query.next())
    {
      qDebug()<< query.value("idReleve") << " " << query.value("data") << " "<< query.value("datetime") << " " << query.value("Station_idStation");
    }
}
///-----------------------------------------------------------------

void SGBD::DatabaseDeconnecter(){
    qDebug()<<"Base déconnecté";
              db.close();
}
