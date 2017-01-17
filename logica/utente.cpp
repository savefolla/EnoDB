#include"utente.h"
#include"database.h"
#include"prodotto.h"

LoginPw::LoginPw(string l, string pw): login(l), password(pw){}

string LoginPw::getLogin() const{
    return login;
}

string LoginPw::getPassword() const{
    return password;
}

bool LoginPw::operator==(const LoginPw& x) const{
    return login==x.login && password==x.password;
}

Info::Info(string n, string c, string m, string t, string cod): nome(n), cognome(c), mail(m), telefono(t), cf(cod){}

string Info::getNome() const{
    return nome;
}

string Info::getCognome() const{
    return cognome;
}

string Info::getMail() const{
    return mail;
}

string Info::getTelefono() const{
    return telefono;
}

string Info::getCf() const{
    return cf;
}

Utente::Funtore::Funtore(int i): tipo(i){}

void Utente::Funtore::operator ()(const Prodotto& p, vector<string>& v) const{
    switch (tipo) {
    case 1:
    {
        v.push_back(p.getNome());
        v.push_back(p.getUso());
    }
        break;
    case 2:
    {
        v.push_back(p.getNome());
        v.push_back(p.getUso());
        v.push_back(p.getDurata());
    }
        break;
    case 3:
    {
        v.push_back(p.getNome());
        v.push_back(p.getUso());
        v.push_back(p.getDurata());
        v.push_back(p.getPrezzo());
    }
        break;
    }
}

Utente::Utente(LoginPw lp, Info inf): l(lp), i(inf){}

Utente::~Utente(){}

LoginPw Utente::getLoginPw() const{
    return l;
}

Info Utente::getInfo() const{
    return i;
}

string Utente::getNome() const{
    return i.getNome();
}

string Utente::getLogin() const{
    return l.getLogin();
}

string Utente::getPassword() const{
    return l.getPassword();
}

UtenteCasuale::UtenteCasuale(LoginPw lp, Info inf): Utente(lp,inf){}

string UtenteCasuale::getTipo() const{
    return "Casuale";
}

vector<string> UtenteCasuale::ricerca(const DatabaseProdotti& db, const string& s){
    vector<string> res;
    bool trovato=false;
    for(unsigned int i=0;i<db.dbp.size() && !trovato;++i)
        if(db.dbp[i]->getNome()==s){
            trovato=true;
            Funtore r(1);
            r(*(db.dbp[i]),res);
        }
    return res;
}

UtenteUtilizzatore::UtenteUtilizzatore(LoginPw lp, Info inf): Utente(lp,inf){}

string UtenteUtilizzatore::getTipo() const{
    return "Utilizzatore";
}

vector<string> UtenteUtilizzatore::ricerca(const DatabaseProdotti& db, const string& s){
    vector<string> res;
    bool trovato=false;
    for(unsigned int i=0;i<db.dbp.size() && !trovato;++i)
        if(db.dbp[i]->getNome()==s){
            trovato=true;
            Funtore r(2);
            r(*(db.dbp[i]),res);
        }
    return res;
}

UtenteRivenditore::UtenteRivenditore(LoginPw lp, Info inf): Utente(lp,inf){}

string UtenteRivenditore::getTipo() const{
    return "Rivenditore";
}

vector<string> UtenteRivenditore::ricerca(const DatabaseProdotti& db, const string& s){
    vector<string> res;
    bool trovato=false;
    for(unsigned int i=0;i<db.dbp.size() && !trovato;++i)
        if(db.dbp[i]->getNome()==s){
            trovato=true;
            Funtore r(3);
            r(*(db.dbp[i]),res);
        }
    return res;
}
