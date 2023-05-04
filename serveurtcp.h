#ifndef SERVEURTCP_H
#define SERVEURTCP_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include "clienttcp.h"
#include <sgbd.h>

class ServeurTCP : public QObject
{
    Q_OBJECT


private:
    QTcpServer *socketEcoutePassive;
    QTcpSocket *socketActive;
    ClientTcp *nouveauClient;



public:
    explicit ServeurTCP(QObject *parent = nullptr);
    ServeurTCP(int port);
    ~ServeurTCP();

public slots:
    void AttenteAceptation();
    void Connexion();

signals:
    void  emettreMessage(QByteArray);

};

#endif // SERVEURTCP_H
