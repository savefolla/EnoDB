#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QFormLayout>
#include<QLabel>
#include"logica/controller_utente.h"
#include"logica/utente.h"
#include"pannello_utente.h"
#include"pannello_admin.h"

class MainWindow : public QWidget{
    Q_OBJECT
private:
    QPushButton* logAdmin;
    QPushButton* logUser;
    QPushButton* buttonClose;
    QLineEdit* username;
    QLineEdit* pass;
    QLabel* passErr;
public slots:
    void loginAdmin();
    void loginUser();
public:
    MainWindow(QWidget* parent=0);
};

#endif // MAINWINDOW_H
