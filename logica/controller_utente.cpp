#include"controller_utente.h"

ControllerUtente::ControllerUtente(LoginPw* lp){
    datap=new DatabaseProdotti();
    datap->load();
    DatabaseUtenti* datau=new DatabaseUtenti();
    datau->load();
    u=datau->autenticazione(lp);
}

