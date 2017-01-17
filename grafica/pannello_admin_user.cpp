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
    comboTipo=new QComboBox;
    labelTipo=new QLabel;
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
    comboTipo->addItem("Casuale");
    comboTipo->addItem("Utilizzatore");
    comboTipo->addItem("Rivenditore");
    labelTipo->setText("Tipo di utente");
    layout->addWidget(lineCerca,0,0,1,2);
    layout->addWidget(buttonCerca,0,2,1,1);
    layout->addWidget(labelLogin,1,0);
    layout->addWidget(lineLogin,1,1);
    layout->addWidget(buttonElimina,1,2);
    layout->addWidget(labelPassword,2,0);
    layout->addWidget(linePassword,2,1);
    layout->addWidget(labelTipo,3,0);
    layout->addWidget(comboTipo,3,1);
    layout->addWidget(labelNome,4,0);
    layout->addWidget(lineNome,4,1);
    layout->addWidget(labelCognome,5,0);
    layout->addWidget(lineCognome,5,1);
    layout->addWidget(labelMail,6,0);
    layout->addWidget(lineMail,6,1);
    layout->addWidget(labelTelefono,7,0);
    layout->addWidget(lineTelefono,7,1);
    layout->addWidget(labelCF,8,0);
    layout->addWidget(lineCF,8,1);
    layout->addWidget(buttonIndietro,9,0);
    layout->addWidget(buttonSalva,9,1);
    layout->addWidget(labelSaved,9,2);
    this->setGeometry(200,100,800,500);
    this->setWindowTitle("Gestione Utenti - Database");
    setLayout(layout);

    connect(buttonCerca,SIGNAL(clicked(bool)),this,SLOT(slotCerca()));
    connect(buttonSalva,SIGNAL(clicked(bool)),this,SLOT(slotSalva()));
    connect(buttonElimina,SIGNAL(clicked(bool)),this,SLOT(slotElimina()));
    connect(buttonIndietro,SIGNAL(clicked(bool)),this,SLOT(slotIndietro()));
}

void pannelloAdminUser::slotCerca(){
    lineLogin->setText("");
    linePassword->setText("");
    lineNome->setText("");
    lineCognome->setText("");
    lineMail->setText("");
    lineTelefono->setText("");
    lineCF->setText("");
    labelSaved->setText("");
    comboTipo->setCurrentIndex(0);
    Utente* ute=controller->datau->find(lineCerca->text().toStdString());
    if(ute){
        lineLogin->setText(QString::fromStdString(ute->getLogin()));
        linePassword->setText(QString::fromStdString(ute->getPassword()));
        Info i=ute->getInfo();
        lineNome->setText(QString::fromStdString(i.getNome()));
        lineCognome->setText(QString::fromStdString(i.getCognome()));
        lineMail->setText(QString::fromStdString(i.getMail()));
        lineTelefono->setText(QString::fromStdString(i.getTelefono()));
        lineCF->setText(QString::fromStdString(i.getCf()));
        if(ute->getTipo()=="Casuale")
            comboTipo->setCurrentIndex(0);
        if(ute->getTipo()=="Utilizzatore")
            comboTipo->setCurrentIndex(1);
        if(ute->getTipo()=="Rivenditore ")
            comboTipo->setCurrentIndex(2);
    }else{
        labelSaved->setText("Non trovato!");
    }
}

void pannelloAdminUser::slotSalva(){
    if(controller->datau->find(lineLogin->text().toStdString()))
        controller->removeU(lineLogin->text().toStdString());
    Info* i=new Info(lineNome->text().toStdString(),
                     lineCognome->text().toStdString(),
                     lineMail->text().toStdString(),
                     lineTelefono->text().toStdString(),
                     lineCF->text().toStdString());
    LoginPw* lp=new LoginPw(lineLogin->text().toStdString(),linePassword->text().toStdString());
    if(comboTipo->currentText().toStdString()=="Casuale")
        controller->datau->insert(new UtenteCasuale(*lp,*i));
    if(comboTipo->currentText().toStdString()=="Utilizzatore")
        controller->datau->insert(new UtenteUtilizzatore(*lp,*i));
    if(comboTipo->currentText().toStdString()=="Rivenditore")
        controller->datau->insert(new UtenteRivenditore(*lp,*i));
    labelSaved->setText("Salvato!");
}

void pannelloAdminUser::slotElimina(){
    controller->removeU(lineLogin->text().toStdString());
    lineLogin->setText("");
    linePassword->setText("");
    lineNome->setText("");
    lineCognome->setText("");
    lineMail->setText("");
    lineTelefono->setText("");
    lineCF->setText("");
    comboTipo->setCurrentIndex(0);
    labelSaved->setText("Eliminato!");
}

void pannelloAdminUser::slotIndietro(){
    this->hide();
    pannelloAdmin* p=new pannelloAdmin;
    p->show();
}
