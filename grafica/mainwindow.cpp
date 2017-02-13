#include "grafica/mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QWidget(parent){
    logAdmin=new QPushButton;
    logUser=new QPushButton;
    buttonClose=new QPushButton;
    username=new QLineEdit;
    pass=new QLineEdit;
    passErr=new QLabel;
    QLabel* labelUser=new QLabel;
    QLabel* labelPass=new QLabel;
    QFormLayout* layout=new QFormLayout;

    labelUser->setText("Username");
    labelPass->setText("Password");
    buttonClose->setText("Esci");
    logAdmin->setText("Login Admin");
    logUser->setText("Login User");
    pass->setEchoMode(QLineEdit::Password);

    this->setWindowTitle("Login - Database");
    layout->addRow(labelUser,username);
    layout->addRow(labelPass,pass);
    layout->addWidget(logAdmin);
    layout->addWidget(logUser);
    layout->addWidget(passErr);
    layout->addWidget(buttonClose);
    this->setGeometry(200,100,800,500);
    setLayout(layout);

    connect(logAdmin,SIGNAL(clicked(bool)),this,SLOT(loginAdmin()));
    connect(logUser,SIGNAL(clicked(bool)),this,SLOT(loginUser()));
    connect(buttonClose,SIGNAL(clicked(bool)),this,SLOT(close()));
}

void MainWindow::loginAdmin(){
    if(username->text()=="admin" && pass->text()=="admin"){
        pannelloAdmin* p=new pannelloAdmin();
        this->close();
        p->show();

    }else{
        passErr->setText("login o password errati");
    }
}

void MainWindow::loginUser(){
    ControllerUtente* controller=new ControllerUtente(new LoginPw(username->text().toStdString(),pass->text().toStdString()));
    if(controller->u){
        pannelloUtente* p=new pannelloUtente(controller);
        this->close();
        p->show();
    }else{
        passErr->setText("login o password errati");
    }
}

MainWindow::~MainWindow(){
    delete logAdmin;
    delete logUser;
    delete buttonClose;
    delete username;
    delete pass;
    delete passErr;
}
