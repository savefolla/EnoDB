#include"pannello_utente.h"

pannelloUtente::pannelloUtente(ControllerUtente* x):controller(x){
    barraRicerca=new QLineEdit;
    buttonCerca=new QPushButton;
    tableOutput=new QTableWidget;
    QGridLayout* layout=new QGridLayout;
    buttonCerca->setText("Cerca");

    layout->addWidget(barraRicerca,0,0);
    layout->addWidget(buttonCerca,0,1);
    layout->addWidget(tableOutput,1,0,1,2);
    this->setGeometry(200,100,500,500);
    this->setWindowTitle("Pannello Utente - Database");
    setLayout(layout);

    connect(buttonCerca,SIGNAL(clicked(bool)),this,SLOT(slotCerca()));
}

void pannelloUtente::slotCerca(){
    vector<string> prod=controller->ricercaProd(barraRicerca->text().toStdString());
    QTableWidgetItem* header0=new QTableWidgetItem();
    QTableWidgetItem* header1=new QTableWidgetItem();
    QTableWidgetItem* header2=new QTableWidgetItem();
    QTableWidgetItem* header3=new QTableWidgetItem();
    header0->setText("Nome");
    header1->setText("Uso");
    header2->setText("Durata");
    header3->setText("Prezzo");
    tableOutput->setColumnCount(prod.size());
    tableOutput->setHorizontalHeaderItem(0,header0);
    tableOutput->setHorizontalHeaderItem(1,header1);
    tableOutput->setHorizontalHeaderItem(2,header2);
    tableOutput->setHorizontalHeaderItem(3,header3);
    tableOutput->setRowCount(tableOutput->rowCount()+1);

    for(unsigned int i=0;i<prod.size();++i){
        QTableWidgetItem* x=new QTableWidgetItem(QString::fromStdString(prod[i]));
        tableOutput->setItem(tableOutput->rowCount()-1,i,x);
    }
}
