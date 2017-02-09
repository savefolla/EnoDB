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
    tableOutput=new QTableWidget;
    QGridLayout* layout=new QGridLayout;

    buttonCerca->setText("Cerca");
    buttonElimina->setText("Elimina");
    buttonSalva->setText("Salva");
    buttonIndietro->setText("Indietro");
    labelLogin->setText("Login");
    labelLogin->setAlignment(Qt::AlignCenter);
    labelPassword->setText("Password");
    labelPassword->setAlignment(Qt::AlignCenter);
    labelNome->setText("Nome");
    labelNome->setAlignment(Qt::AlignCenter);
    labelCognome->setText("Cognome");
    labelCognome->setAlignment(Qt::AlignCenter);
    labelMail->setText("Mail");
    labelMail->setAlignment(Qt::AlignCenter);
    labelTelefono->setText("Telefono");
    labelTelefono->setAlignment(Qt::AlignCenter);
    labelCF->setText("Codice Fiscale");
    labelCF->setAlignment(Qt::AlignCenter);
    comboTipo->addItem("Casuale");
    comboTipo->addItem("Utilizzatore");
    comboTipo->addItem("Rivenditore");
    labelTipo->setText("Tipo di utente");
    labelTipo->setAlignment(Qt::AlignCenter);

    layout->addWidget(lineCerca,0,0,1,6);
    layout->addWidget(buttonCerca,0,6,1,1);
    layout->addWidget(tableOutput,1,0,8,4);
    layout->addWidget(labelLogin,1,4,1,1);
    layout->addWidget(lineLogin,1,5,1,2);
    layout->addWidget(labelPassword,2,4,1,1);
    layout->addWidget(linePassword,2,5,1,2);
    layout->addWidget(labelTipo,3,4,1,1);
    layout->addWidget(comboTipo,3,5,1,2);
    layout->addWidget(labelNome,4,4,1,1);
    layout->addWidget(lineNome,4,5,1,2);
    layout->addWidget(labelCognome,5,4,1,1);
    layout->addWidget(lineCognome,5,5,1,2);
    layout->addWidget(labelMail,6,4,1,1);
    layout->addWidget(lineMail,6,5,1,2);
    layout->addWidget(labelTelefono,7,4,1,1);
    layout->addWidget(lineTelefono,7,5,1,2);
    layout->addWidget(labelCF,8,4,1,1);
    layout->addWidget(lineCF,8,5,1,2);
    layout->addWidget(buttonIndietro,9,4,1,1);
    layout->addWidget(buttonSalva,9,5,1,1);
    layout->addWidget(buttonElimina,9,6,1,1);
    layout->addWidget(labelSaved,9,3,1,1);
    this->setGeometry(200,100,800,500);
    this->setWindowTitle("Gestione Utenti - Database");
    setLayout(layout);

    connect(buttonCerca,SIGNAL(clicked(bool)),this,SLOT(slotCerca()));
    connect(tableOutput,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(slotElemento(QTableWidgetItem*)));
    connect(buttonSalva,SIGNAL(clicked(bool)),this,SLOT(slotSalva()));
    connect(buttonElimina,SIGNAL(clicked(bool)),this,SLOT(slotElimina()));
    connect(buttonIndietro,SIGNAL(clicked(bool)),this,SLOT(slotIndietro()));
}

void pannelloAdminUser::slotCerca(){
    vector<Utente*> ute=controller->datau->find(lineCerca->text().toStdString());
    lineLogin->setText("");
    linePassword->setText("");
    lineNome->setText("");
    lineCognome->setText("");
    lineMail->setText("");
    lineTelefono->setText("");
    lineCF->setText("");
    labelSaved->setText("");
    comboTipo->setCurrentIndex(0);
    QTableWidgetItem* header0=new QTableWidgetItem();
    QTableWidgetItem* header1=new QTableWidgetItem();
    QTableWidgetItem* header2=new QTableWidgetItem();
    QTableWidgetItem* header3=new QTableWidgetItem();
    QTableWidgetItem* header4=new QTableWidgetItem();
    QTableWidgetItem* header5=new QTableWidgetItem();
    QTableWidgetItem* header6=new QTableWidgetItem();
    QTableWidgetItem* header7=new QTableWidgetItem();
    header0->setText("Login");
    header1->setText("Password");
    header2->setText("Nome");
    header3->setText("Cognome");
    header4->setText("Mail");
    header5->setText("Telefono");
    header6->setText("CF");
    header7->setText("Tipo");
    tableOutput->setColumnCount(8);
    tableOutput->setRowCount(0);
    tableOutput->setHorizontalHeaderItem(0,header0);
    tableOutput->setHorizontalHeaderItem(1,header1);
    tableOutput->setHorizontalHeaderItem(2,header2);
    tableOutput->setHorizontalHeaderItem(3,header3);
    tableOutput->setHorizontalHeaderItem(4,header4);
    tableOutput->setHorizontalHeaderItem(5,header5);
    tableOutput->setHorizontalHeaderItem(6,header6);
    tableOutput->setHorizontalHeaderItem(7,header7);

    for(unsigned int i=0;i<ute.size();++i){
        tableOutput->setRowCount(tableOutput->rowCount()+1);
        tableOutput->setItem(i,0,new QTableWidgetItem(QString::fromStdString(ute[i]->getLogin())));
        tableOutput->setItem(i,1,new QTableWidgetItem(QString::fromStdString(ute[i]->getPassword())));
        tableOutput->setItem(i,2,new QTableWidgetItem(QString::fromStdString(ute[i]->getInfo().getNome())));
        tableOutput->setItem(i,3,new QTableWidgetItem(QString::fromStdString(ute[i]->getInfo().getCognome())));
        tableOutput->setItem(i,4,new QTableWidgetItem(QString::fromStdString(ute[i]->getInfo().getMail())));
        tableOutput->setItem(i,5,new QTableWidgetItem(QString::fromStdString(ute[i]->getInfo().getTelefono())));
        tableOutput->setItem(i,6,new QTableWidgetItem(QString::fromStdString(ute[i]->getInfo().getCf())));
        tableOutput->setItem(i,7,new QTableWidgetItem(QString::fromStdString(ute[i]->getTipo())));
    }

}

void pannelloAdminUser::slotElemento(QTableWidgetItem *q){

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
