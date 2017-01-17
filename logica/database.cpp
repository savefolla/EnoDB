#include"database.h"

void DatabaseProdotti::load(){
    //popolazione database
    /*dbp.push_back(new Prodotto("meta","enologia",22,35.2));
    dbp.push_back(new Prodotto("acido","enologia",10,27.62));
    dbp.push_back(new Prodotto("tappi","enologia",7,29.6));
    dbp.push_back(new Prodotto("gesu","religione",6.1,45.6));*/
    ifstream file;
    string nome, uso, durata, prezzo;
    file.open("database.txt");
    while(getline(file,nome)){
        getline(file,uso);
        getline(file,durata);
        getline(file,prezzo);
        dbp.push_back(new Prodotto(nome,uso,durata,prezzo));
    }

}

void DatabaseProdotti::save() const{
    ofstream file;
    file.open("database.txt");
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
