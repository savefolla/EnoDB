#include"pannello_admin_prod.h"

pannelloAdminProd::pannelloAdminProd(){
    this->setAttribute(Qt::WA_DeleteOnClose);
    controller=new ControllerAdmin;
    lineCerca=new QLineEdit;
    buttonCerca=new QPushButton;
    buttonElimina=new QPushButton;
    labelNome=new QLabel;
    labelUso=new QLabel;
    labelDurata=new QLabel;
    labelPrezzo=new QLabel;
    lineNome=new QLineEdit;
    lineUso=new QLineEdit;
    lineDurata=new QLineEdit;
    linePrezzo=new QLineEdit;
    buttonSalva=new QPushButton;
    buttonIndietro=new QPushButton;
    labelSaved=new QLabel;
    tableOutput=new QTableWidget;
    QHeaderView *HorzHdr=tableOutput->horizontalHeader();
    HorzHdr->setSectionResizeMode(QHeaderView::Stretch);
    current=0;
    QGridLayout* layout=new QGridLayout;

    buttonCerca->setText("Cerca");
    buttonElimina->setText("Elimina");
    labelNome->setText("Nome");
    labelNome->setAlignment(Qt::AlignCenter);
    labelUso->setText("Uso");
    labelUso->setAlignment(Qt::AlignCenter);
    labelDurata->setText("Durata");
    labelDurata->setAlignment(Qt::AlignCenter);
    labelPrezzo->setText("Prezzo");
    labelPrezzo->setAlignment(Qt::AlignCenter);
    labelSaved->setText("");
    labelSaved->setAlignment(Qt::AlignCenter);
    buttonSalva->setText("Salva");
    buttonIndietro->setText("Indietro");
    layout->addWidget(lineCerca,0,0,1,6);
    layout->addWidget(buttonCerca,0,6,1,1);
    layout->addWidget(tableOutput,1,0,4,4);
    layout->addWidget(labelNome,1,4,1,1);
    layout->addWidget(lineNome,1,5,1,2);
    layout->addWidget(labelUso,2,4,1,1);
    layout->addWidget(lineUso,2,5,1,2);
    layout->addWidget(labelDurata,3,4,1,1);
    layout->addWidget(lineDurata,3,5,1,2);
    layout->addWidget(labelPrezzo,4,4,1,1);
    layout->addWidget(linePrezzo,4,5,1,2);
    layout->addWidget(labelSaved,5,3,1,1);
    layout->addWidget(buttonIndietro,5,4,1,1);
    layout->addWidget(buttonSalva,5,5,1,1);
    layout->addWidget(buttonElimina,5,6,1,1);
    tableOutput->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setGeometry(200,100,800,500);
    this->setWindowTitle("Gestione Prodotti - Database");
    setLayout(layout);

    connect(buttonCerca,SIGNAL(clicked(bool)),this,SLOT(slotCerca()));
    connect(tableOutput,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(slotElemento(QTableWidgetItem*)));
    connect(buttonSalva,SIGNAL(clicked(bool)),this,SLOT(slotSalva()));
    connect(buttonElimina,SIGNAL(clicked(bool)),this,SLOT(slotElimina()));
    connect(buttonIndietro,SIGNAL(clicked(bool)),this,SLOT(slotIndietro()));
}

void pannelloAdminProd::clean(){
    lineNome->setText("");
    lineUso->setText("");
    lineDurata->setText("");
    linePrezzo->setText("");
    labelSaved->setText("");
}

void pannelloAdminProd::slotCerca(){
    current=0;
    vector<Prodotto*> prods=controller->datap->find(lineCerca->text().toStdString());
    clean();
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

void pannelloAdminProd::slotElemento(QTableWidgetItem* q){
    if(q->column()==0){
        clean();
        vector<Prodotto*> prod=controller->datap->find(q->text().toStdString());
        for(unsigned int i=0;i<prod.size();++i)
            if((prod[i])->getNome()==q->text().toStdString()){
                lineNome->setText(QString::fromStdString((prod[i])->getNome()));
                lineUso->setText(QString::fromStdString((prod[i])->getUso()));
                lineDurata->setText(QString::fromStdString((prod[i])->getDurata()));
                linePrezzo->setText(QString::fromStdString((prod[i])->getPrezzo()));
                current=prod[i];
                return;
            }
    }
    labelSaved->setText("Casella errata!");
}

void pannelloAdminProd::slotSalva(){
    if(lineNome->text().toStdString()!=""){
        if(current){
            current->setNome(lineNome->text().toStdString());
            current->setUso(lineUso->text().toStdString());
            current->setDurata(lineDurata->text().toStdString());
            current->setPrezzo(linePrezzo->text().toStdString());

        }else{
            controller->insertP(new Prodotto(lineNome->text().toStdString(),
                                             lineUso->text().toStdString(),
                                             lineDurata->text().toStdString(),
                                             linePrezzo->text().toStdString()));
        }
    }else{
        labelSaved->setText("Nome Richiesto!");
        return;
    }
    current=0;
    clean();
    tableOutput->setRowCount(0);
    controller->save();
    labelSaved->setText("Salvato!");
}

void pannelloAdminProd::slotElimina(){
    controller->removeP(lineNome->text().toStdString());
    current=0;
    clean();
    tableOutput->setRowCount(0);
    labelSaved->setText("Eliminato!");
}

void pannelloAdminProd::slotIndietro(){
    this->hide();
    pannelloAdmin* p=new pannelloAdmin;
    p->show();
}
