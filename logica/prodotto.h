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
    double durata;
    double prezzo;
public:
    Prodotto(string n, string u, double d, double p);
    string getNome() const;
    string getUso() const;
    double getDurata() const;
    double getPrezzo() const;
};

#endif // PRODOTTO_H
