#include"database.h"

void DatabaseProdotti::load(){
    //popolazione database
    dbp.push_back(new Prodotto("meta","enologia",22,35.2));
    dbp.push_back(new Prodotto("acido","enologia",10,27.62));
    dbp.push_back(new Prodotto("tappi","enologia",7,29.6));
    dbp.push_back(new Prodotto("gesu","religione",6,45.6));
}

void DatabaseProdotti::save() const{

}

void DatabaseProdotti::insert(Prodotto* p){
    dbp.push_back(p);
}

void DatabaseProdotti::remove(const string& s){
    bool trovato(false);
    for(vector<Prodotto*>::const_iterator cit=dbp.begin();cit!=dbp.end() && !trovato;++cit)
        if(s==(*cit)->getNome()){
            trovato=true;
            delete *cit;
            cit=dbp.erase(cit);
        }
}

Prodotto* DatabaseProdotti::find(const string& s) const{
    for(vector<Prodotto*>::const_iterator cit=dbp.begin();cit!=dbp.end();++cit)
        if(s==(*cit)->getNome())
            return *cit;
    return 0;
}

void DatabaseUtenti::load(){
    //popolazione database
    dbu.push_back(new UtenteCasuale(*new LoginPw("saveCas","p"),*new Info("d","d","d","d","d")));
    dbu.push_back(new UtenteUtilizzatore(*new LoginPw("saveUti","p"),*new Info("s","s","s","s","s")));
    dbu.push_back(new UtenteRivenditore(*new LoginPw("saveProva","p"),*new Info("r","r","r","r","r")));
}

void DatabaseUtenti::save() const{

}

void DatabaseUtenti::insert(Utente* u){
    dbu.push_back(u);
}

void DatabaseUtenti::remove(const string& u){
    bool trovato(false);
    for(vector<Utente*>::const_iterator cit=dbu.begin();cit!=dbu.end() && !trovato;++cit)
        if(u==(*cit)->getLogin()){
            trovato=true;
            delete *cit;
            cit=dbu.erase(cit);
        }
}

Utente* DatabaseUtenti::find(string s) const{
    for(vector<Utente*>::const_iterator cit=dbu.begin();cit!=dbu.end();++cit)
        if(s==(*cit)->getLogin())
            return *cit;
    return 0;
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

void DatabaseUtenti::cambiaTipo(const string& s, string x){
    bool trovato=false;
    for(vector<Utente*>::iterator it=dbu.begin();it!=dbu.end() && !trovato;++it)
        if((*it)->getLogin()==s){
            LoginPw lp=(*it)->getLoginPw();
            Info i=(*it)->getInfo();
            delete *it;
            if(x=="1")
                *it=new UtenteCasuale(lp,i);
            if(x=="2")
                *it=new UtenteUtilizzatore(lp,i);
            if(x=="3")
                *it=new UtenteRivenditore(lp,i);
        }
}
