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
