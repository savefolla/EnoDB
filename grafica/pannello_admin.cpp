#include"pannello_admin.h"

pannelloAdmin::pannelloAdmin(){
    buttonProd=new QPushButton;
    buttonUser=new QPushButton;
    buttonLogout=new QPushButton;
    QFormLayout* layout=new QFormLayout;

    buttonProd->setText("Gestione Prodotti");
    buttonUser->setText("Gestione Utenti");
    buttonLogout->setText("Logout");

    this->setWindowTitle("Pannello Admin - Database");
    this->setGeometry(200,100,800,500);
    layout->addWidget(buttonProd);
    layout->addWidget(buttonUser);
    layout->addWidget(buttonLogout);
    setLayout(layout);

    connect(buttonProd,SIGNAL(clicked(bool)),this,SLOT(slotProd()));
    connect(buttonUser,SIGNAL(clicked(bool)),this,SLOT(slotUser()));
    connect(buttonLogout,SIGNAL(clicked(bool)),this,SLOT(slotLogout()));
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

void pannelloAdmin::slotLogout(){
    this->hide();
    MainWindow* p=new MainWindow;
    p->show();
}
