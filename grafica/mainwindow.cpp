#include "grafica/mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QWidget(parent){
    logAdmin=new QPushButton;
    logUser=new QPushButton;
    username=new QLineEdit;
    pass=new QLineEdit;
    passErr=new QLabel;
    QLabel* labelUser=new QLabel;
    QLabel* labelPass=new QLabel;
    QLabel* title=new QLabel;
    QFormLayout* layout=new QFormLayout;

    labelUser->setText("Username");
    labelPass->setText("Password");
    logAdmin->setText("Login Admin");
    logUser->setText("Login User");
    title->setText("Login");
    pass->setEchoMode(QLineEdit::Password);

    this->setWindowTitle("Login - Database");
    layout->addRow(labelUser,username);
    layout->addRow(labelPass,pass);
    layout->addWidget(logAdmin);
    layout->addWidget(logUser);
    layout->addWidget(passErr);
    this->setGeometry(200,100,500,200);
    setLayout(layout);

    connect(logAdmin,SIGNAL(clicked(bool)),this,SLOT(loginAdmin()));
    connect(logUser,SIGNAL(clicked(bool)),this,SLOT(loginUser()));
}

void MainWindow::loginAdmin(){
    if(username->text()=="admin" && pass->text()=="pass"){
        this->hide();
        pannelloAdmin* p=new pannelloAdmin();
        p->show();
    }else{
        passErr->setText("login o password errati");
    }
}

void MainWindow::loginUser(){
    ControllerUtente* controller=new ControllerUtente(new LoginPw(username->text().toStdString(),pass->text().toStdString()));
    if(controller->u){
        this->hide();
        pannelloUtente* p=new pannelloUtente(controller);
        p->show();
    }else{
        passErr->setText("login o password errati");
    }
}
