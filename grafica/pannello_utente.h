#ifndef PANNELLO_UTENTE_H
#define PANNELLO_UTENTE_H
#include<QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QHeaderView>
#include<QTableWidget>
#include<QGridLayout>
#include"logica/controller_utente.h"
#include"mainwindow.h"

class pannelloUtente: public QWidget{
    Q_OBJECT
private:
    QLineEdit* barraRicerca;
    QPushButton* buttonCerca;
    QPushButton* buttonLogout;
    QTableWidget* tableOutput;
    ControllerUtente* controller;
public slots:
    void slotCerca();
    void slotLogout();
public:
    pannelloUtente(ControllerUtente*);
    ~pannelloUtente();
};

#endif // PANNELLO_UTENTE_H
