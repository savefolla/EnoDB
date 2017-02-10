#ifndef PANNELLO_ADMIN_H
#define PANNELLO_ADMIN_H
#include<QPushButton>
#include<QFormLayout>
#include"mainwindow.h"
#include"pannello_admin_prod.h"
#include"pannello_admin_user.h"

class pannelloAdmin: public QWidget{
    Q_OBJECT
private:
    QPushButton* buttonProd;
    QPushButton* buttonUser;
    QPushButton* buttonLogout;
public slots:
    void slotProd();
    void slotUser();
    void slotLogout();
public:
    pannelloAdmin();
    ~pannelloAdmin();
};

#endif // PANNELLO_ADMIN_H
