#include <iostream>
#include <string>
#include "chacara.h"

using namespace std;
//Construtor de Chacara
Chacara :: Chacara(int id, int numero, int quartos, int banheiros,
             float valor, string proprietario, string rua, string bairro, 
             string cidade, bool salao_festa, bool salao_jogos, bool campo_futebol, bool churrasqueira, bool piscina) : 
    
    Imovel(id, numero, quartos, banheiros, valor, proprietario, rua, bairro, cidade),
    salao_festa(salao_festa), salao_jogos(salao_jogos), campo_futebol(campo_futebol), 
    churrasqueira(churrasqueira),piscina(piscina){}

Chacara :: ~Chacara(){}
//GETTERS E SETTERS DE CHACARA
bool Chacara::getSalaoFesta(){
    return salao_festa;
}

void Chacara::setSalaoFesta(bool salao_festa){
    this->salao_festa = salao_festa;
}

bool Chacara::getSalaoJogos(){
    return salao_jogos;
}

void Chacara::setSalaoJogos(bool salao_jogos){
    this->salao_jogos = salao_jogos;
}

bool Chacara::getCampoFutebol(){
    return campo_futebol;
}

void Chacara::setCampoFutebol(bool campo_futebol){
    this->campo_futebol = campo_futebol;
}

bool Chacara::getChurrasqueira(){
    return churrasqueira;
}

void Chacara::setChurrasqueira(bool churrasqueira){
    this->churrasqueira = churrasqueira;
}

bool Chacara::getPiscina(){
    return piscina;
}

void Chacara::setPiscina(bool piscina){
    this->piscina = piscina;
}
//SOBRECARGA DO OPERADOR <<
void Chacara::saida(ostream& out) const{
    Imovel::saida(out);
    out << "Piscina: " << true << "\n-----\n";
}

ostream& operator<<(ostream& out, const Chacara& obj){
    obj.saida(out);
    return out;
}