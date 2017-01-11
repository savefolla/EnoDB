#ifndef DATABASE_H
#define DATABASE_H
#include<vector>
#include "prodotto.h"
#include "utente.h"
using std::vector;

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
    Prodotto* find(const string&) const;
};

class DatabaseUtenti{
private:
    vector<Utente*> dbu;
public:
    void load(); //carica da file
    void save() const; //salva su file
    void insert(Utente*);
    void remove(Utente*);
    Utente* find(string) const;
    Utente* autenticazione(LoginPw*) const;
    void cambiaTipo(const string&, string);
};

#endif // DATABASE_H
