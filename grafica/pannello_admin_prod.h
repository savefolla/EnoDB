#ifndef PANNELLO_ADMIN_PROD_H
#define PANNELLO_ADMIN_PROD_H
#include<QHeaderView>
#include<QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QFormLayout>
#include<QLabel>
#include<QTableWidget>
#include"pannello_admin.h"
#include"logica/controller_admin.h"

class pannelloAdminProd: public QWidget{
    Q_OBJECT
private:
    QLineEdit* lineCerca;
    QPushButton* buttonCerca;
    QPushButton* buttonElimina;
    QLabel* labelNome;
    QLabel* labelUso;
    QLabel* labelDurata;
    QLabel* labelPrezzo;
    QLineEdit* lineNome;
    QLineEdit* lineUso;
    QLineEdit* lineDurata;
    QLineEdit* linePrezzo;
    QPushButton* buttonSalva;
    QPushButton* buttonIndietro;
    QLabel* labelSaved;
    QTableWidget* tableOutput;
    ControllerAdmin* controller;
    Prodotto* currProd;
public slots:
    void slotCerca();
    void slotElemento(QTableWidgetItem* q);
    void slotSalva();
    void slotElimina();
    void slotIndietro();
public:
    pannelloAdminProd();
};

#endif // PANNELLO_ADMIN_PROD_H
