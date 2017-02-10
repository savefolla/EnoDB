#include"database.h"

void DatabaseProdotti::load(){
    ifstream file;
    string nome, uso, durata, prezzo;
    file.open("databaseProdotti.txt");
    while(getline(file,nome)){
        getline(file,uso);
        getline(file,durata);
        getline(file,prezzo);
        dbp.push_back(new Prodotto(nome,uso,durata,prezzo));
    }
    file.close();
}

void DatabaseProdotti::save() const{
    ofstream file;
    file.open("databaseProdotti.txt");
    for(unsigned int i=0;i<dbp.size();++i){
        file<<dbp[i]->getNome()<<endl;
        file<<dbp[i]->getUso()<<endl;
        file<<dbp[i]->getDurata()<<endl;
        file<<dbp[i]->getPrezzo()<<endl;
    }
    file.close();
}

void DatabaseProdotti::insert(Prodotto* p){
    dbp.push_back(p);
    this->save();
}

void DatabaseProdotti::remove(const string& s){
    bool trovato(false);
    for(vector<Prodotto*>::const_iterator cit=dbp.begin();cit!=dbp.end() && !trovato;++cit)
    //for(vector<Prodotto*>::iterator cit=dbp.begin();cit!=dbp.end() && !trovato;++cit)
        if(s==(*cit)->getNome()){
            trovato=true;
            delete *cit;
            cit=dbp.erase(cit);
        }
    this->save();
}

vector<Prodotto*> DatabaseProdotti::find(const string& s){
    vector<Prodotto*> res;
    for(vector<Prodotto*>::const_iterator cit=dbp.begin();cit!=dbp.end();++cit){
    //for(vector<Prodotto*>::iterator cit=dbp.begin();cit!=dbp.end();++cit){
        string n=(*cit)->getNome();
        string u=(*cit)->getUso();
        if(n.find(s)!=std::string::npos || u.find(s)!=std::string::npos)
            res.push_back(*cit);
    }
    return res;
}

void DatabaseUtenti::load(){
    ifstream file;
    string login, password, nome, cognome, mail, telefono, CF, tipo;
    file.open("databaseUtenti.txt");
    while(getline(file,login)){
        getline(file,password);
        getline(file,nome);
        getline(file,cognome);
        getline(file,mail);
        getline(file,telefono);
        getline(file,CF);
        getline(file,tipo);
        if(tipo=="Casuale")
            dbu.push_back(new UtenteCasuale(*new LoginPw(login,password),*new Info(nome,cognome,mail,telefono,CF)));
        if(tipo=="Utilizzatore")
            dbu.push_back(new UtenteUtilizzatore(*new LoginPw(login,password),*new Info(nome,cognome,mail,telefono,CF)));
        if(tipo=="Rivenditore")
            dbu.push_back(new UtenteRivenditore(*new LoginPw(login,password),*new Info(nome,cognome,mail,telefono,CF)));
    }
    file.close();
}

void DatabaseUtenti::save() const{
    ofstream file;
    file.open("databaseUtenti.txt");
    for(unsigned int i=0;i<dbu.size();++i){
        file<<dbu[i]->getLoginPw().getLogin()<<endl;
        file<<dbu[i]->getLoginPw().getPassword()<<endl;
        file<<dbu[i]->getInfo().getNome()<<endl;
        file<<dbu[i]->getInfo().getCognome()<<endl;
        file<<dbu[i]->getInfo().getMail()<<endl;
        file<<dbu[i]->getInfo().getTelefono()<<endl;
        file<<dbu[i]->getInfo().getCF()<<endl;
        file<<dbu[i]->getTipo()<<endl;
    }
    file.close();
}

void DatabaseUtenti::insert(Utente* u){
    dbu.push_back(u);
    this->save();
}

void DatabaseUtenti::remove(const string& u){
    bool trovato(false);
    for(vector<Utente*>::const_iterator cit=dbu.begin();cit!=dbu.end() && !trovato;++cit)
    //for(vector<Utente*>::iterator cit=dbu.begin();cit!=dbu.end() && !trovato;++cit)
        if(u==(*cit)->getLogin()){
            trovato=true;
            delete *cit;
            cit=dbu.erase(cit);
        }
    this->save();
}

vector<Utente*> DatabaseUtenti::find(const string& s){
    vector<Utente*> res;
    for(vector<Utente*>::const_iterator cit=dbu.begin();cit!=dbu.end();++cit){
    //for(vector<Utente*>::iterator cit=dbu.begin();cit!=dbu.end();++cit){
        string l=(*cit)->getLogin();
        if(l.find(s)!=std::string::npos)
            res.push_back(*cit);
    }
    return res;
}

Utente* DatabaseUtenti::autenticazione(LoginPw* x) const{
    bool trovato=false;
    for(unsigned int i=0;i<dbu.size() && !trovato;++i)
        if(dbu[i]->getLoginPw()==*x){
            trovato=true;
            return dbu[i];
        }
    return 0;
}
