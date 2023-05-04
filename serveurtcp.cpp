#include "serveurtcp.h"

ServeurTCP::ServeurTCP(QObject *parent) : QObject(parent)
{

}


ServeurTCP::ServeurTCP(int port)
{
    socketEcoutePassive=new QTcpServer;
    socketEcoutePassive->listen(QHostAddress :: Any, port);
    socketEcoutePassive->setMaxPendingConnections(10);
    connect(socketEcoutePassive,SIGNAL(newConnection()),this, SLOT(AttenteAceptation()));
}

ServeurTCP::~ServeurTCP()
{
    socketEcoutePassive -> close();
    delete socketEcoutePassive;
}

void ServeurTCP::AttenteAceptation()
{
    socketActive =socketEcoutePassive->nextPendingConnection();
   nouveauClient =new ClientTcp(socketActive);
    connect(nouveauClient, SIGNAL(emettreMessage(QByteArray)),this,SIGNAL(emettreMessage(QByteArray)));
    qDebug() <<"-- Connexion D'un Client";

}
void ServeurTCP::Connexion()
{
    socketEcoutePassive->close();
    socketEcoutePassive->listen();
    socketEcoutePassive->setMaxPendingConnections(10);
}
