#ifndef UTENTE_H
#define UTENTE_H
#include<string>
#include<vector>
#include<list>
#include"prodotto.h"
using std::string;
using std::vector;
using std::list;

class DatabaseProdotti;

class LoginPw{
private:
    string login;
    string password;
public:
    LoginPw(string l, string pw);
    string getLogin() const;
    string getPassword() const;
    void setLogin(string);
    void setPassword(string);
    bool operator==(const LoginPw&) const;
};

class Info{
private:
    string nome;
    string cognome;
    string mail;
    string telefono;
    string CF;
public:
    Info(string n, string c, string m, string t, string cod);
    string getNome() const;
    string getCognome() const;
    string getMail() const;
    string getTelefono() const;
    string getCF() const;
    void setNome(string);
    void setCognome(string);
    void setMail(string);
    void setTelefono(string);
    void setCF(string);
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
    virtual vector<vector<string> > ricerca(const DatabaseProdotti&, const string&) =0;
    LoginPw getLoginPw() const;
    Info getInfo() const;
    string getNome() const;
    string getLogin() const;
    string getPassword() const;
    void setLogin(string);
    void setPassword(string);
    void setNome(string);
    void setCognome(string);
    void setMail(string);
    void setTelefono(string);
    void setCF(string);
};

class UtenteCasuale: public Utente{
public:
    UtenteCasuale(LoginPw, Info);
    UtenteCasuale(const Utente&);
    virtual string getTipo() const;
    virtual vector<vector<string> > ricerca(const DatabaseProdotti&, const string&);
};

class UtenteUtilizzatore: public Utente{
public:
    UtenteUtilizzatore(LoginPw, Info);
    UtenteUtilizzatore(const Utente&);
    virtual string getTipo() const;
    virtual vector<vector<string> > ricerca(const DatabaseProdotti&, const string&);
};

class UtenteRivenditore: public Utente{
public:
    UtenteRivenditore(LoginPw, Info);
    UtenteRivenditore(const Utente&);
    virtual string getTipo() const;
    virtual vector<vector<string> > ricerca(const DatabaseProdotti&, const string&);
};

#endif // UTENTE_H
