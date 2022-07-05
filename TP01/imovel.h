#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>

using namespace std;
//Declaracao da classe Imovel
class Imovel
{
    int id, numero, quartos, banheiros;
    float valor;
    string proprietario, rua, bairro, cidade;
public:
    Imovel(int =0, int =0, int =0, int =0, float= 0.0, string ="", string ="", string ="", string ="");
    ~Imovel();
    int getId();
    void setId(int);
    int getNumero();
    void setNumero(int);
    int getQuartos();
    void setQuartos(int);
    int getBanheiros();
    void setBanheiros(int);
    float getValor();
    void setValor(float);
    string getProprietario();
    void setProprietario(string);
    string getRua();
    void setRua(string);
    string getBairro();
    void setBairro(string);
    string getCidade();
    void setCidade(string);
    virtual void saida(ostream&) const;
    friend ostream& operator<<(ostream&, const Imovel&);
};
#endif