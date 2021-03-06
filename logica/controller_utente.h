#ifndef CONTROLLER_UTENTE_H
#define CONTROLLER_UTENTE_H
#include<vector>
#include<string>
#include"utente.h"
#include"database.h"
using std::vector;
using std::string;

class ControllerUtente{
public:
    Utente* u;
    DatabaseProdotti* datap;

    ControllerUtente(LoginPw*);
    ~ControllerUtente();
    vector<vector<string> > ricercaProd(const string&);
};

#endif // CONTROLLER_UTENTE_H
