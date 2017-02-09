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

void ControllerAdmin::removeU(const string& u){
    datau->remove(u);
}

void ControllerAdmin::removeP(const string& s){
    datap->remove(s);
}

void ControllerAdmin::save() const{
    datap->save();
    datau->save();
}
