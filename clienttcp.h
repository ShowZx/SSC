#ifndef CLIENTTCP_H
#define CLIENTTCP_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include "sgbd.h"
#include "ads1115.h"

class ClientTcp : public QObject
{
    Q_OBJECT



private:
    QTcpSocket *socket_;
    QByteArray Message;
    QTimer *timer;
    QString strame;

    SGBD sgbd;
    QSqlDatabase db_;
    int idStaion_;
    int tauxEchant_;

    Ads1115 ads;
    int data;
    QString datas;
    QString _datetime;



public:
    explicit ClientTcp(QObject *parent = nullptr);
     ClientTcp(QTcpSocket *socket);
    void affichage(QByteArray Message);
    ~ClientTcp();




public slots:
    void lire_Message();
    void Ecrire_Message();
    void Ecrire_Message(QString Message);
    void Ecrire_Message(QByteArray Message);
    void Connexion(QString ip, int port);
    void ConnexionOk();
    void Deconnexion();
    void Acquerir();


signals:
    void emettreMessage(QByteArray Message);
    void emettreData(int data);
    void emettreDate(QString _datetime);

};

#endif // CLIENTTCP_H
