#ifndef CASA_H
#define CASA_H

#include "imovel.h"
//Declaracao da classe Casa
//Herda publicamente os atributos da classe Imovel
class Casa : public Imovel
{    
    int andares;
    bool sala_jantar;

public:
    Casa(int =0, int =0, int =0, int =0, float= 0.0, string ="", string ="", string ="", string ="",
        int = 0, bool = false); //construtor pra bool é false?
    virtual ~Casa();
    int getAndares();
    void setAndares(int);
    bool getSalaJantar();
    void setSalaJantar(bool);
    virtual void saida(ostream&) const;
    friend ostream& operator<<(ostream&, const Casa&);
};

#endif