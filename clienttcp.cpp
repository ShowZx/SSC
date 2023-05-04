#include "clienttcp.h"

//Constructeurs
ClientTcp::ClientTcp(QObject *parent) : QObject(parent)
{
    socket_ = new QTcpSocket();
    connect(socket_, SIGNAL(readyRead()),this, SLOT(lire_Message()));
    //connect(socket_, SIGNAL(disconnected()),this, SLOT(Deconnexion()));

}

ClientTcp::ClientTcp(QTcpSocket *socket)
{


    socket_=socket;
    connect(socket_, SIGNAL(readyRead()),this, SLOT(lire_Message()));
    //connect(socket_, SIGNAL(disconnected()),this, SLOT(Deconnexion()));
    //connect(socket_, SIGNAL(connected()),this, SLOT(Connexion()));

     sgbd.DatabaseConnect();
     tauxEchant_=100;  //sgbd.getTauxEchantillonage();
     idStaion_  =sgbd.getIdStaion();
/*
     SQl

     query.prepare("INSERT INTO releve(data,datetime,Station_idStation) VALUES( ? , ? , ?)");
     query.bindValue(0,value);
     query.bindValue(1,_datetime);
     query.bindValue(2,_idStation);
     qDebug()<<query.exec();

*/
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Acquerir()));
    timer-> start(tauxEchant_);

}
/*
ClientTcp::ClientTcp(QTcpSocket *socket)
{
    socket_=socket;
    connect(socket_, SIGNAL(readyRead()),this, SLOT(lire_Message()));
    connect(socket_, SIGNAL(disconnected()),this, SLOT(Deconnexion()));
    connect(socket_, SIGNAL(connected()),this, SLOT(Connexion()));

}
*/


//Destructeur

ClientTcp::~ClientTcp()
{
    socket_->close();
    sgbd.DatabaseDeconnecter();
    delete socket_;
    delete timer;
    //delete ads;
    qDebug()<<"-- Destructeur mort d'une instance";

}



//Functions

void ClientTcp::lire_Message()
{

     Message=socket_ ->readAll();
     timer->stop();
    //socket_ ->write(Message);
    //emit emettreMessage(Message);
     timer->stop();
     qDebug() << Message;
     Deconnexion();


}

void ClientTcp::Ecrire_Message() {
    socket_ ->write(Message);
}

void ClientTcp::Ecrire_Message(QString Message){
    socket_ ->write(Message.toStdString().c_str());

}

void ClientTcp::Ecrire_Message(QByteArray Message){
    socket_ ->write(Message.toStdString().c_str());
}

void ClientTcp::Connexion(QString ip, int port) {
    socket_->connectToHost(ip,port);
    qDebug() <<"-- ClientTcp connexion";
}

void ClientTcp::ConnexionOk() {
    qDebug() <<"-- Successssssss";
}

void ClientTcp::Deconnexion() {
    qDebug() <<"-- ClientTcp S'est Déconnecté";
    //socket_->disconnectFromHost();
    //timer->stop();
    delete this;
}

void ClientTcp::Acquerir()
{
ads.ADS1115_ReadDataReg(data);
sgbd.DatabaseRecord(data);

datas= QString::number(data);
_datetime= "MM-dd-yyyy HH:mm:ss.sss";
_datetime=QDateTime::currentDateTime().toString(_datetime);
strame.clear();
strame = _datetime + "+" + datas;

socket_ ->write(strame.toStdString().c_str());
//emettreMessage(QByteArray(std::strame);
}




