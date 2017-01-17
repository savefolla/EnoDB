#ifndef UTENTE_H
#define UTENTE_H
#include<string>
#include<vector>
#include"prodotto.h"
using std::string;
using std::vector;

class DatabaseProdotti;

class LoginPw{
private:
    string login;
    string password;
public:
    LoginPw(string l, string pw);
    string getLogin() const;
    string getPassword() const;
    bool operator==(const LoginPw&) const;
};

class Info{
private:
    string nome;
    string cognome;
    string mail;
    string telefono;
    string cf;
public:
    Info(string n, string c, string m, string t, string cod);
    string getNome() const;
    string getCognome() const;
    string getMail() const;
    string getTelefono() const;
    string getCf() const;
};

class Utente{
private:
    LoginPw l;
    Info i;
protected:
    class Funtore{
    public:
        int tipo;
        Funtore(int);
        void operator()(const Prodotto&, vector<string>&) const;
    };
public:
    Utente(LoginPw, Info);
    virtual ~Utente();
    virtual string getTipo() const =0;
    virtual vector<string> ricerca(const DatabaseProdotti&, const string&) =0;
    LoginPw getLoginPw() const;
    Info getInfo() const;
    string getNome() const;
    string getLogin() const;
    string getPassword() const;
};

class UtenteCasuale: public Utente{
public:
    UtenteCasuale(LoginPw, Info);
    virtual string getTipo() const;
    virtual vector<string> ricerca(const DatabaseProdotti&, const string&);
};

class UtenteUtilizzatore: public Utente{
public:
    UtenteUtilizzatore(LoginPw, Info);
    virtual string getTipo() const;
    virtual vector<string> ricerca(const DatabaseProdotti&, const string&);
};

class UtenteRivenditore: public Utente{
public:
    UtenteRivenditore(LoginPw, Info);
    virtual string getTipo() const;
    virtual vector<string> ricerca(const DatabaseProdotti&, const string&);
};

#endif // UTENTE_H
