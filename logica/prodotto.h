#ifndef PRODOTTO_H
#define PRODOTTO_H
#include<string>
#include<vector>
using std::string;
using std::vector;

class Prodotto{
private:
    string nome;
    string uso;
    string durata;
    string prezzo;
public:
    Prodotto(string n, string u, string d, string p);
    string getNome() const;
    string getUso() const;
    string getDurata() const;
    string getPrezzo() const;
};

#endif // PRODOTTO_H
