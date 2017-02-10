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
    tableOutput->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setGeometry(200,100,800,500);
    this->setWindowTitle("Pannello Utente - Database");
    setLayout(layout);

    connect(buttonCerca,SIGNAL(clicked(bool)),this,SLOT(slotCerca()));
}

void pannelloUtente::slotCerca(){
    vector<Prodotto*> prods=controller->datap->find(barraRicerca->text().toStdString());
    QTableWidgetItem* header0=new QTableWidgetItem();
    QTableWidgetItem* header1=new QTableWidgetItem();
    QTableWidgetItem* header2=new QTableWidgetItem();
    QTableWidgetItem* header3=new QTableWidgetItem();
    header0->setText("Nome");
    header1->setText("Uso");
    header2->setText("Durata");
    header3->setText("Prezzo");
    tableOutput->setColumnCount(4);
    tableOutput->setRowCount(0);
    tableOutput->setHorizontalHeaderItem(0,header0);
    tableOutput->setHorizontalHeaderItem(1,header1);
    tableOutput->setHorizontalHeaderItem(2,header2);
    tableOutput->setHorizontalHeaderItem(3,header3);

    for(unsigned int i=0;i<prods.size();++i){
        tableOutput->setRowCount(tableOutput->rowCount()+1);
        tableOutput->setItem(i,0,new QTableWidgetItem(QString::fromStdString(prods[i]->getNome())));
        tableOutput->setItem(i,1,new QTableWidgetItem(QString::fromStdString(prods[i]->getUso())));
        tableOutput->setItem(i,2,new QTableWidgetItem(QString::fromStdString(prods[i]->getDurata())));
        tableOutput->setItem(i,3,new QTableWidgetItem(QString::fromStdString(prods[i]->getPrezzo())));
    }
}
