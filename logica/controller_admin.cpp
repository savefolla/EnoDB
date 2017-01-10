#include"controller_admin.h"

ControllerAdmin::ControllerAdmin(){
    datap=new DatabaseProdotti;
    datap->load();
    datau=new DatabaseUtenti;
    datau->load();
}

void ControllerAdmin::insertU(Utente* u){
    datau->insert(u);
}

void ControllerAdmin::insertP(Prodotto* p){
    datap->insert(p);
}

void ControllerAdmin::removeU(const string& s){
    datau->remove(s);
}

void ControllerAdmin::removeP(const string& s){
    datap->remove(s);
}

void ControllerAdmin::cambiaTipo(const string& s, string x){
    datau->cambiaTipo(s,x);
}

