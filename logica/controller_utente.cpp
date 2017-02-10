#include"controller_utente.h"

ControllerUtente::ControllerUtente(LoginPw* lp){
    datap=new DatabaseProdotti();
    datap->load();
    DatabaseUtenti* datau=new DatabaseUtenti();
    datau->load();
    u=datau->autenticazione(lp);
}

vector< vector<string> > ControllerUtente::ricercaProd(const string& s){
    vector< vector<string> > res=u->ricerca(*datap,s);
    return res;
}
