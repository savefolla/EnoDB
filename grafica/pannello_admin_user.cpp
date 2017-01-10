#include"pannello_admin_user.h"

pannelloAdminUser::pannelloAdminUser(){
    controller=new ControllerAdmin;
    lineCerca=new QLineEdit;
    buttonCerca=new QPushButton;
    buttonElimina=new QPushButton;
    labelLogin=new QLabel;
    labelPassword=new QLabel;
    labelNome=new QLabel;
    labelCognome=new QLabel;
    labelMail=new QLabel;
    labelTelefono=new QLabel;
    labelCF=new QLabel;
    lineLogin=new QLineEdit;
    linePassword=new QLineEdit;
    lineNome=new QLineEdit;
    lineCognome=new QLineEdit;
    lineMail=new QLineEdit;
    lineTelefono=new QLineEdit;
    lineCF=new QLineEdit;
    buttonSalva=new QPushButton;
    buttonIndietro=new QPushButton;
    labelSaved=new QLabel;
    QGridLayout* layout=new QGridLayout;

    buttonCerca->setText("Cerca");
    buttonElimina->setText("Elimina");
    buttonSalva->setText("Salva");
    buttonIndietro->setText("Indietro");
    labelLogin->setText("Login");
    labelPassword->setText("Password");
    labelNome->setText("Nome");
    labelCognome->setText("Cognome");
    labelMail->setText("Mail");
    labelTelefono->setText("Telefono");
    labelCF->setText("Codice Fiscale");
    layout->addWidget(lineCerca,0,0,1,2);
    layout->addWidget(buttonCerca,0,2,1,1);
    layout->addWidget(labelLogin,1,0);
    layout->addWidget(lineLogin,1,1);
    layout->addWidget(buttonElimina,1,2);
    layout->addWidget(labelPassword,2,0);
    layout->addWidget(linePassword,2,1);
    layout->addWidget(labelNome,3,0);
    layout->addWidget(lineNome,3,1);
    layout->addWidget(labelCognome,4,0);
    layout->addWidget(lineCognome,4,1);
    layout->addWidget(labelMail,5,0);
    layout->addWidget(lineMail,5,1);
    layout->addWidget(labelTelefono,6,0);
    layout->addWidget(lineTelefono,6,1);
    layout->addWidget(labelCF,7,0);
    layout->addWidget(lineCF,7,1);
    layout->addWidget(buttonIndietro,8,0);
    layout->addWidget(buttonSalva,8,1);
    layout->addWidget(labelSaved,8,2);
    this->setGeometry(200,100,800,500);
    this->setWindowTitle("Gestione Utenti - Database");
    setLayout(layout);

    connect(buttonCerca,SIGNAL(clicked(bool)),this,SLOT(slotCerca()));
    connect(buttonSalva,SIGNAL(clicked(bool)),this,SLOT(slotSalva()));
    connect(buttonElimina,SIGNAL(clicked(bool)),this,SLOT(slotElimina()));
    connect(buttonIndietro,SIGNAL(clicked(bool)),this,SLOT(slotIndietro()));
}

void pannelloAdminUser::slotCerca(){

}

void pannelloAdminUser::slotSalva(){

}

void pannelloAdminUser::slotElimina(){

}

void pannelloAdminUser::slotIndietro(){
    this->hide();
    pannelloAdmin* p=new pannelloAdmin;
    p->show();
}
