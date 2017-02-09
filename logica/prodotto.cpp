#include"prodotto.h"

Prodotto::Prodotto(string n, string u, string d, string p): nome(n), uso(u), durata(d), prezzo(p){}

string Prodotto::getNome() const{
    return nome;
}

string Prodotto::getUso() const{
    return uso;
}

string Prodotto::getDurata() const{
    return durata;
}

string Prodotto::getPrezzo() const{
    return prezzo;
}

void Prodotto::setNome(string x){
    nome=x;
}

void Prodotto::setUso(string x){
    uso=x;
}

void Prodotto::setDurata(string x){
    durata=x;
}

void Prodotto::setPrezzo(string x){
    prezzo=x;
}
