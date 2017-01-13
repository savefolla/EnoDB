#include"prodotto.h"

Prodotto::Prodotto(string n, string u, double d, double p): nome(n), uso(u), durata(d), prezzo(p){}

string Prodotto::getNome() const{
    return nome;
}

string Prodotto::getUso() const{
    return uso;
}

double Prodotto::getDurata() const{
    return durata;
}

double Prodotto::getPrezzo() const{
    return prezzo;
}
