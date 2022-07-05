#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "imovel.h"
//Declaracao da classe aoartamento
//Herda publicamente da classe Imovel
class Apartamento : public Imovel
{   
    int andar;
    float taxa_condominio;
    bool elevador, sacada;

public:
    Apartamento(int =0, int =0, int =0, int =0, float= 0.0, string ="", string ="", string ="", 
                string ="", int = 0, float = 0.0, bool = false, bool = false);
    virtual ~Apartamento();
    int getAndar();
    void setAndar(int);
    float getTaxaCondominio();
    void setTaxaCondominio(float);
    bool getElevador();
    void setElevador(bool);
    bool getSacada();
    void setSacada(bool);
    virtual void saida(ostream&) const;
    friend ostream& operator<<(ostream&, const Apartamento&);
};

#endif