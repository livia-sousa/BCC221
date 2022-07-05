#include <iostream>
#include <string>
#include "apartamento.h"

using namespace std;


//Construtor da classe apartamento
Apartamento :: Apartamento(int id, int numero, int quartos, int banheiros,
                            float valor, string proprietario, string rua, string bairro, 
                            string cidade, int andar, float taxa_condominio, bool elevador, bool sacada): 
    
    Imovel(id, numero, quartos, banheiros, valor, proprietario, rua, bairro, cidade),
    andar(andar), taxa_condominio(taxa_condominio), elevador(elevador), sacada(sacada){}

Apartamento :: ~Apartamento(){}
//GETTERS E SETTERS
int Apartamento::getAndar(){
    return andar;
}

void Apartamento::setAndar(int andar){
    this->andar = andar;
}

float Apartamento::getTaxaCondominio(){
    return taxa_condominio;
}

void Apartamento::setTaxaCondominio(float taxa_condominio){
    this->taxa_condominio = taxa_condominio;
}

bool Apartamento::getElevador(){
    return elevador;
}

void Apartamento::setElevador(bool elevador){
    this->elevador = elevador;
}

bool Apartamento::getSacada(){
    return sacada;
}
void Apartamento::setSacada(bool b){
    sacada = b;
}
//SOBRECARGA DO OPERADOR <<
void Apartamento::saida(ostream& out) const{
    Imovel::saida(out);
    out << "Elevador: " << elevador << "\n-----\n";
}

//sobrecarga aqui
ostream& operator<<(ostream& out, const Apartamento& obj){
    obj.saida(out);
    return out;
}