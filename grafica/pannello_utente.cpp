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
    this->setGeometry(200,100,800,500);
    this->setWindowTitle("Pannello Utente - Database");
    setLayout(layout);

    connect(buttonCerca,SIGNAL(clicked(bool)),this,SLOT(slotCerca()));
}

void pannelloUtente::slotCerca(){
    vector<vector<string>> prods=controller->ricercaProd(barraRicerca->text().toStdString());
    QTableWidgetItem* header0=new QTableWidgetItem();
    QTableWidgetItem* header1=new QTableWidgetItem();
    QTableWidgetItem* header2=new QTableWidgetItem();
    QTableWidgetItem* header3=new QTableWidgetItem();
    header0->setText("Nome");
    header1->setText("Uso");
    header2->setText("Durata");
    header3->setText("Prezzo");
    tableOutput->setColumnCount(4);
    tableOutput->setHorizontalHeaderItem(0,header0);
    tableOutput->setHorizontalHeaderItem(1,header1);
    tableOutput->setHorizontalHeaderItem(2,header2);
    tableOutput->setHorizontalHeaderItem(3,header3);

    for(unsigned int i=0;i<prods.size();++i){
        for(unsigned int j=0;j<prods[i].size();++j){
            QTableWidgetItem* x=new QTableWidgetItem(QString::fromStdString((prods[i])[j]));
            tableOutput->setItem(tableOutput->rowCount(),j,x);
        }
    }
}
