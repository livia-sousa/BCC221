#include <iostream>
#include <string>
#include "imovel.h"

using namespace std;
//Construtor da classe imovel
Imovel::Imovel(int id, int numero, int quartos, int banheiros, float valor, string proprietario, string rua, string bairro, string cidade): 
    id(id), numero(numero) , quartos(quartos) , banheiros(banheiros), valor(valor), proprietario(proprietario), rua(rua), bairro(bairro), cidade(cidade){}

Imovel:: ~Imovel(){}
//GETTERS E SETTERS
int Imovel::getId(){
    return id;
}

void Imovel::setId(int n){
    id = n;
}

int Imovel::getNumero(){
    return numero;
}

void Imovel::setNumero(int n){
    numero = n;
}

int Imovel::getQuartos(){
    return quartos;
}

void Imovel::setQuartos(int n){
    quartos = n;
}

int Imovel::getBanheiros(){
    return banheiros;
}

void Imovel::setBanheiros(int n){
    banheiros = n;
}

float Imovel::getValor(){
    return valor;
}

void Imovel::setValor(float v){
    valor = v;
}

string Imovel::getProprietario(){
    return proprietario;
}

void Imovel::setProprietario(string n){
    proprietario = n;
}

string Imovel::getRua(){
    return rua;
}

void Imovel::setRua(string n){
    rua = n;
}

string Imovel::getBairro(){
    return bairro;
}

void Imovel::setBairro(string n){
    bairro = n;
}

string Imovel::getCidade(){
    return cidade;
}

void Imovel::setCidade(string n){
    cidade = n;
}
//SOBRECARGA DO OPERADOR <<
void Imovel::saida(ostream& out) const{
    out << "-----\nProprietario: " << proprietario << "\nValor do Imovel: " << valor << "\nNumero de Quartos: " << quartos << "\nRua: "
    << rua << "\nBairro: " << bairro << "\nCidade: " << cidade << "\n";
}

ostream& operator<<(ostream& out, const Imovel& obj){
    obj.saida(out);
    return out;
}
