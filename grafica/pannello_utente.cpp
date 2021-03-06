#include"pannello_utente.h"

pannelloUtente::pannelloUtente(ControllerUtente* x):controller(x){
    this->setAttribute(Qt::WA_DeleteOnClose);
    barraRicerca=new QLineEdit;
    buttonCerca=new QPushButton;
    buttonLogout=new QPushButton;
    tableOutput=new QTableWidget;
    QGridLayout* layout=new QGridLayout;
    QHeaderView *HorzHdr=tableOutput->horizontalHeader();
    HorzHdr->setSectionResizeMode(QHeaderView::Stretch);
    buttonCerca->setText("Cerca");
    buttonLogout->setText("Logout");

    layout->addWidget(barraRicerca,0,0);
    layout->addWidget(buttonCerca,0,1);
    layout->addWidget(tableOutput,1,0,1,3);
    layout->addWidget(buttonLogout,0,2);
    tableOutput->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setGeometry(200,100,800,500);
    this->setWindowTitle("Pannello Utente - Database");
    setLayout(layout);

    connect(buttonCerca,SIGNAL(clicked(bool)),this,SLOT(slotCerca()));
    connect(buttonLogout,SIGNAL(clicked(bool)),this,SLOT(slotLogout()));
}

void pannelloUtente::slotCerca(){
    vector<vector<string> > prods=controller->ricercaProd(barraRicerca->text().toStdString());
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
        for(unsigned int j=0;j<prods[i].size();++j){
            QTableWidgetItem* x=new QTableWidgetItem();
            x->setText(QString::fromStdString((prods[i])[j]));
            tableOutput->setItem(i,j,x);
        }
    }
}

void pannelloUtente::slotLogout(){
    MainWindow* p=new MainWindow;
    this->close();
    p->show();
}

pannelloUtente::~pannelloUtente(){
    delete barraRicerca;
    delete buttonCerca;
    delete buttonLogout;
    delete tableOutput;
    delete controller;
}
