#ifndef CHACARA_H
#define CHACARA_H
#include "imovel.h"

//Declaracao da classe Chacara
//Herda publicamente os atributos da classe Imovel
class Chacara : public Imovel
{   
    bool salao_festa, salao_jogos, campo_futebol, churrasqueira, piscina;

public:
    Chacara(int =0, int =0, int =0, int =0, float= 0.0, string ="", string ="", string ="", string ="",
            bool = false, bool = false, bool = false, bool = false, bool = false);
    virtual ~Chacara();
    bool getSalaoFesta();
    void setSalaoFesta(bool);
    bool getSalaoJogos();
    void setSalaoJogos(bool);
    bool getCampoFutebol();
    void setCampoFutebol(bool);
    bool getChurrasqueira();
    void setChurrasqueira(bool);
    bool getPiscina();
    void setPiscina(bool);
    virtual void saida(ostream&) const;
    friend ostream& operator<<(ostream&, const Chacara&);
};

#endif