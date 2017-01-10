#ifndef PANNELLO_ADMIN_H
#define PANNELLO_ADMIN_H
#include<QPushButton>
#include<QFormLayout>
#include"pannello_admin_prod.h"
#include"pannello_admin_user.h"

class pannelloAdmin: public QWidget{
    Q_OBJECT
private:
    QPushButton* buttonProd;
    QPushButton* buttonUser;
public slots:
    void slotProd();
    void slotUser();
public:
    pannelloAdmin();
};

#endif // PANNELLO_ADMIN_H
