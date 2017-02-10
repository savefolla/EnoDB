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

void LoginPw::setLogin(string s){
    login=s;
}

void LoginPw::setPassword(string s){
    password=s;
}

Info::Info(string n, string c, string m, string t, string cod): nome(n), cognome(c), mail(m), telefono(t), CF(cod){}

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

string Info::getCF() const{
    return CF;
}

void Info::setNome(string s){
    nome=s;
}

void Info::setCognome(string s){
    cognome=s;
}

void Info::setMail(string s){
    mail=s;
}

void Info::setTelefono(string s){
    telefono=s;
}

void Info::setCF(string s){
    CF=s;
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

void Utente::setLogin(string s){
    l.setLogin(s);
}

void Utente::setPassword(string s){
    l.setPassword(s);
}

void Utente::setNome(string s){
    i.setNome(s);
}

void Utente::setCognome(string s){
    i.setCognome(s);
}

void Utente::setMail(string s){
    i.setMail(s);
}

void Utente::setTelefono(string s){
    i.setTelefono(s);
}

void Utente::setCF(string s){
    i.setCF(s);
}

UtenteCasuale::UtenteCasuale(LoginPw lp, Info inf): Utente(lp,inf){}

UtenteCasuale::UtenteCasuale(const Utente& u): UtenteCasuale(u.getLoginPw(),u.getInfo()){}

string UtenteCasuale::getTipo() const{
    return "Casuale";
}

vector<vector<string>> UtenteCasuale::ricerca(const DatabaseProdotti& db, const string& s){
    vector<vector<string>> res;
    for(unsigned int i=0;i<db.dbp.size();++i){
        string n=db.dbp[i]->getNome();
        string u=db.dbp[i]->getUso();
        if(n.find(s)!=std::string::npos || u.find(s)!=std::string::npos){
            Funtore r(1);
            vector<string>* v=new vector<string>;
            r(*(db.dbp[i]),*v);
            res.push_back(*v);
        }
    }
    return res;
}

UtenteUtilizzatore::UtenteUtilizzatore(LoginPw lp, Info inf): Utente(lp,inf){}

UtenteUtilizzatore::UtenteUtilizzatore(const Utente& u): UtenteUtilizzatore(u.getLoginPw(),u.getInfo()){}

string UtenteUtilizzatore::getTipo() const{
    return "Utilizzatore";
}

vector<vector<string>> UtenteUtilizzatore::ricerca(const DatabaseProdotti& db, const string& s){
    vector<vector<string>> res;
    for(unsigned int i=0;i<db.dbp.size();++i){
        string n=db.dbp[i]->getNome();
        string u=db.dbp[i]->getUso();
        string d=db.dbp[i]->getDurata();
        if(n.find(s)!=std::string::npos || u.find(s)!=std::string::npos || d.find(s)!=std::string::npos){
            Funtore r(2);
            vector<string>* v=new vector<string>;
            r(*(db.dbp[i]),*v);
            res.push_back(*v);
        }
    }
    return res;
}

UtenteRivenditore::UtenteRivenditore(LoginPw lp, Info inf): Utente(lp,inf){}

UtenteRivenditore::UtenteRivenditore(const Utente& u): UtenteRivenditore(u.getLoginPw(),u.getInfo()){}

string UtenteRivenditore::getTipo() const{
    return "Rivenditore";
}

vector<vector<string>> UtenteRivenditore::ricerca(const DatabaseProdotti& db, const string& s){
    vector<vector<string>> res;
    for(unsigned int i=0;i<db.dbp.size();++i){
        string n=db.dbp[i]->getNome();
        string u=db.dbp[i]->getUso();
        string d=db.dbp[i]->getDurata();
        string p=db.dbp[i]->getPrezzo();
        if(n.find(s)!=std::string::npos || u.find(s)!=std::string::npos || d.find(s)!=std::string::npos || p.find(s)!=std::string::npos){
            Funtore r(3);
            vector<string>* v=new vector<string>;
            r(*(db.dbp[i]),*v);
            res.push_back(*v);
        }
    }
    return res;
}
