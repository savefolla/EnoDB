#include"pannello_admin.h"

pannelloAdmin::pannelloAdmin(){
    this->setAttribute(Qt::WA_DeleteOnClose);
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
    pannelloAdminProd* p=new pannelloAdminProd;
    this->close();
    p->show();
}

void pannelloAdmin::slotUser(){
    pannelloAdminUser* p=new pannelloAdminUser;
    this->close();
    p->show();
}

void pannelloAdmin::slotLogout(){
    MainWindow* p=new MainWindow;
    this->close();
    p->show();
}

pannelloAdmin::~pannelloAdmin(){
    delete buttonLogout;
    delete buttonProd;
    delete buttonUser;
}
