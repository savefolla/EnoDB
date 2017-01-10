#include"pannello_admin_prod.h"

pannelloAdminProd::pannelloAdminProd(){
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
    QGridLayout* layout=new QGridLayout;

    buttonCerca->setText("Cerca");
    buttonElimina->setText("Elimina");
    labelNome->setText("Nome");
    labelUso->setText("Uso");
    labelDurata->setText("Durata");
    labelPrezzo->setText("Prezzo");
    labelSaved->setText("");
    buttonSalva->setText("Salva");
    buttonIndietro->setText("Indietro");
    layout->addWidget(lineCerca,0,0,1,2);
    layout->addWidget(buttonCerca,0,2,1,1);
    layout->addWidget(labelNome,1,0);
    layout->addWidget(lineNome,1,1);
    layout->addWidget(buttonElimina,1,2);
    layout->addWidget(labelUso,2,0);
    layout->addWidget(lineUso,2,1);
    layout->addWidget(labelDurata,3,0);
    layout->addWidget(lineDurata,3,1);
    layout->addWidget(labelPrezzo,4,0);
    layout->addWidget(linePrezzo,4,1);
    layout->addWidget(buttonIndietro,5,0);
    layout->addWidget(buttonSalva,5,1);
    layout->addWidget(labelSaved,5,2);
    this->setGeometry(200,100,800,500);
    this->setWindowTitle("Gestione Prodotti - Database");
    setLayout(layout);

    connect(buttonCerca,SIGNAL(clicked(bool)),this,SLOT(slotCerca()));
    connect(buttonSalva,SIGNAL(clicked(bool)),this,SLOT(slotSalva()));
    connect(buttonElimina,SIGNAL(clicked(bool)),this,SLOT(slotElimina()));
    connect(buttonIndietro,SIGNAL(clicked(bool)),this,SLOT(slotIndietro()));
}

void pannelloAdminProd::slotCerca(){
    lineNome->setText("");
    lineUso->setText("");
    lineDurata->setText("");
    linePrezzo->setText("");
    labelSaved->setText("");
    Prodotto* prod=controller->datap->find(lineCerca->text().toStdString());
    if(prod){
        lineNome->setText(QString::fromStdString(prod->getNome()));
        lineUso->setText(QString::fromStdString(prod->getUso()));
        lineDurata->setText(QString::number(prod->getDurata()));
        linePrezzo->setText(QString::number(prod->getPrezzo()));
    }
}

void pannelloAdminProd::slotSalva(){
    controller->insertP(new Prodotto(lineNome->text().toStdString(),lineUso->text().toStdString(),lineDurata->text().toInt(),linePrezzo->text().toDouble()));
    labelSaved->setText("Salvato!");
}

void pannelloAdminProd::slotElimina(){
    controller->removeP(lineNome->text().toStdString());
    lineNome->setText("");
    lineUso->setText("");
    lineDurata->setText("");
    linePrezzo->setText("");
    labelSaved->setText("");
    labelSaved->setText("Eliminato!");
}

void pannelloAdminProd::slotIndietro(){
    this->hide();
    pannelloAdmin* p=new pannelloAdmin;
    p->show();
}
