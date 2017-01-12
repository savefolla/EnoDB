#include"pannello_admin.h"

pannelloAdmin::pannelloAdmin(){
    buttonProd=new QPushButton;
    buttonUser=new QPushButton;
    QFormLayout* layout=new QFormLayout;

    buttonProd->setText("Gestione Prodotti");
    buttonUser->setText("Gestione Utenti");

    this->setWindowTitle("Pannello Admin - Database");
    this->setGeometry(200,100,800,500);
    layout->addWidget(buttonProd);
    layout->addWidget(buttonUser);
    setLayout(layout);

    connect(buttonProd,SIGNAL(clicked(bool)),this,SLOT(slotProd()));
    connect(buttonUser,SIGNAL(clicked(bool)),this,SLOT(slotUser()));
}

void pannelloAdmin::slotProd(){
    this->hide();
    pannelloAdminProd* p=new pannelloAdminProd;
    p->show();
}

void pannelloAdmin::slotUser(){
    this->hide();
    pannelloAdminUser* p=new pannelloAdminUser;
    p->show();
}
