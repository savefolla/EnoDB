#ifndef DATABASE_H
#define DATABASE_H
#include<vector>
#include<iostream>
#include<fstream>
#include<math.h>
#include "prodotto.h"
#include "utente.h"
using namespace std;

class DatabaseProdotti{
    friend class UtenteCasuale;
    friend class UtenteUtilizzatore;
    friend class UtenteRivenditore;
private:
    vector<Prodotto*> dbp;
public:
    void load(); //carica da file
    void save() const; //salva su file
    void insert(Prodotto*);
    void remove(const string&);
    vector<Prodotto*> find(const string&);
};

class DatabaseUtenti{
private:
    vector<Utente*> dbu;
public:
    void load(); //carica da file
    void save() const; //salva su file
    void insert(Utente*);
    void remove(const string&);
    vector<Utente*> find(const string&);
    Utente* autenticazione(LoginPw*) const;
};

#endif // DATABASE_H
