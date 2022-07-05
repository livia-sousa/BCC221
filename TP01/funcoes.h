#ifndef FUNCOES_H
#define FUNCOES_H
#include <vector>
#include "imovel.h"
#include "casa.h"
#include "apartamento.h"
#include "chacara.h"

void lerArquivo(vector <Imovel*>&);
void printMenu();
void ImprimeContainer(vector <Imovel*>, bool);
bool buscaProprietario(vector <Imovel*> v);
vector <Imovel*> buscaPorValor(vector <Imovel*> v);
vector <Imovel*> buscaPorQuartos(vector <Imovel*> v);
vector <Imovel*> buscarTipoOrdenado(vector <Imovel*> v);
vector <Imovel*> buscarCidade(vector <Imovel*> v);
vector <vector <Imovel*> :: iterator > buscarImovelPorProprietario(vector <Imovel*> v);
#endif