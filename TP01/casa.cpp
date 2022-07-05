#include <iostream>
#include <string>
#include "casa.h"

using namespace std; 

//Construtor de Casa
Casa :: Casa(int id, int numero, int quartos, int banheiros,
             float valor, string proprietario, string rua, string bairro, string cidade, 
             int andares, bool sala_jantar) : 
    
    Imovel(id, numero, quartos, banheiros, valor, proprietario, rua, bairro, cidade),
    andares(andares), sala_jantar(sala_jantar){}

Casa :: ~Casa(){}
//GETTERS E SETTER DE CASA
int Casa::getAndares(){
    return andares;
}

void Casa::setAndares(int andares){
    this->andares = andares;
}

bool Casa::getSalaJantar(){
    return sala_jantar;
}

void Casa::setSalaJantar(bool sala_jantar){
    this->sala_jantar = sala_jantar;
}
//SOBRECARGA DO OPERADOR <<
void Casa::saida(ostream& out) const{
    Imovel::saida(out);
    out << "Andares: " << andares <<  "\n-----\n";
}
ostream& operator<<(ostream& out, const Casa& obj){
    obj.saida(out);
    return out;
}