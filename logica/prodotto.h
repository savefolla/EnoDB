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
    int durata;
    double prezzo;
public:
    Prodotto(string n, string u, int d, double p);
    string getNome() const;
    string getUso() const;
    int getDurata() const;
    double getPrezzo() const;
};

#endif // PRODOTTO_H
