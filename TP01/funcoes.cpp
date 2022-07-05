#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#include "imovel.h"
#include "apartamento.h"
#include "casa.h"
#include "chacara.h"
using namespace std;

//Funcao que le o arquivo
void lerArquivo(vector <Imovel*> &v){
    ifstream dados;
	dados.open("database_imoveis.txt");
	if(!dados.good()){
		cout << " ⚠️  ERRO NA ABERTURA DO ARQUIVO ⚠️ " << endl;
		exit(EXIT_FAILURE);
	}
	v.clear();
	string aux;
	vector<string> arm;
	arm.clear();
	int i = 1;
	//Loop que le os dados do arquivo
	while(getline(dados, aux)){
		istringstream iss(aux);
		string token;
		//Loop que separa as entradas de cada variavel da classe
		while (getline(iss, token, ';')){
			arm.push_back(token);
		}
		//Caso seja um apartamento
		if(arm[0] == "apartamento"){
			Apartamento *objeto = new Apartamento;
			objeto->setId(i);
			objeto->setValor(stof(arm[1]));
			objeto->setProprietario(arm[2]);
			objeto->setRua(arm[3]);
			objeto->setBairro(arm[4]);
			objeto->setCidade(arm[5]);
			objeto->setNumero(stoi(arm[6]));
			objeto->setQuartos(stoi(arm[7]));
			objeto->setBanheiros(stoi(arm[8]));
			objeto->setAndar(stoi(arm[9]));
			objeto->setTaxaCondominio(stof(arm[10]));
			objeto->setElevador(stoi(arm[11]));
			objeto->setSacada(stoi(arm[12]));
			v.push_back(objeto);
		}
		//Caso seja uma Casa
		if(arm[0] == "casa"){
			Casa *objeto = new Casa;
			objeto->setId(i);
			objeto->setValor(stof(arm[1]));
			objeto->setProprietario(arm[2]);
			objeto->setRua(arm[3]);
			objeto->setBairro(arm[4]);
			objeto->setCidade(arm[5]);
			objeto->setNumero(stoi(arm[6]));
			objeto->setQuartos(stoi(arm[7]));
			objeto->setBanheiros(stoi(arm[8]));
			objeto->setAndares(stoi(arm[9]));
			objeto->setSalaJantar(stoi(arm[10]));
			v.push_back(objeto);
		}
		//Caso seja uma chacara
		if(arm[0] == "chacara"){
			Chacara *objeto = new Chacara;
			objeto->setId(i);
			objeto->setValor(stof(arm[1]));
			objeto->setProprietario(arm[2]);
			objeto->setRua(arm[3]);
			objeto->setBairro(arm[4]);
			objeto->setCidade(arm[5]);
			objeto->setNumero(stoi(arm[6]));
			objeto->setQuartos(stoi(arm[7]));
			objeto->setBanheiros(stoi(arm[8]));
			objeto->setSalaoFesta(stoi(arm[9]));
			objeto->setSalaoJogos(stoi(arm[10]));
			objeto->setCampoFutebol(stoi(arm[11]));
			objeto->setChurrasqueira(stoi(arm[12]));
			objeto->setPiscina(stoi(arm[13]));
			v.push_back(objeto);
		}
		arm.clear();
		i++;
	}
}
//Funcao que imprime o menu de opcoes
void printMenu(){
	cout << "\t\u250F\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2513\n";
	cout << "\t\u2503\033[1mMENU DE OPCOES\033[0m\u2503\n";
	cout << "\t\u2517\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u251B" << endl;
	cout << "🗒️  Tem-se as seguintes opcoes 🗒️ \n" << endl;
    cout << "1 - Mostrar lista de imoveis disponiveis (Digite '1 -s' para salvar em um arquivo externo)" << endl;
	cout << "2 - Verificar proprietario de imovel" << endl;
    cout << "3 - Ver imoveis abaixo de um valor" << endl;
    cout << "4 - Ver imoveis por numeros de quartos" << endl;
    cout << "5 - Ver imoveis por tipo e ordenados por um valor" << endl;
    cout << "6 - Ver imoveis localizados em uma cidade" << endl;
    cout << "7 - Ver imoveis por proprietario" << endl;
    cout << "0 - Finalizar programa\n" << endl;
    cout << "▶️  Digite a opcao desejada: ";
}
//Funcao que imprime o conteudo do container vector
void ImprimeContainer(vector <Imovel*> v, bool arquivo){
	//Variavel booleana que fala se deve-se imprimir em um arquivo externo
    if(!arquivo){
        for(vector<Imovel*>:: iterator itr = v.begin(); itr != v.end(); ++itr){
			Chacara *ch;
			//downcasting
			ch = dynamic_cast <Chacara*>(*itr);
			if(ch != nullptr){
				cout << *ch << endl;
			}
			else{
				//downcasting
				Casa *ca;
				ca = dynamic_cast <Casa*>(*itr);
				if(ca != nullptr){
					cout << *ca << endl;
				}
				else{
					//downcasting
					Apartamento *auxiliar = dynamic_cast <Apartamento*>(*itr);
					cout << *auxiliar  << endl;
				}
			}		
		}
    }
    else{
		//abertura do arquivo externo
		ofstream saida;
		saida.open("saida.txt");
		for(vector<Imovel*>:: iterator itr = v.begin(); itr != v.end(); ++itr){
			//downcasting
			Chacara *ch;
			ch = dynamic_cast <Chacara*>(*itr);
			if(ch != nullptr){
				saida << *ch << endl;
			}
			else{
				//downcasting
				Casa *ca;
				ca = dynamic_cast <Casa*>(*itr);
				if(ca != nullptr){
					saida << *ca << endl;
				}
				else{
					//downcasting
					Apartamento *auxiliar = dynamic_cast <Apartamento*>(*itr);
					saida << *auxiliar  << endl;
				}
			}		
		}
	}
}
//Funcao que busca se um proprietario eh dono de um dos imoveis
bool buscaProprietario(vector <Imovel*> v){
	cout << "Digite o nome do proprietario a ser buscado: ";
	string nome;
	getline(cin, nome);
	//Loop que percorre o container
	for(vector<Imovel*>:: iterator itr = v.begin(); itr != v.end(); ++itr){
		//Pegar o proprietario por meio de um getter
		string prop = (*itr)->getProprietario();
		if(nome == prop)
			return true;
	}
	return false;
}
//Funcao que retorna um vector contendo os imoveis menor que um valor passado
vector <Imovel*> buscaPorValor(vector <Imovel*> v){
	cout << "Digite o valor maximo a ser pesquisado: ";
	float valorPesquisa;
	cin >> valorPesquisa;
	getchar();
	cout << endl;
	vector <Imovel*> r;
	//Loop que percorre o vector
	for(vector<Imovel*>:: iterator itr = v.begin(); itr != v.end(); ++itr){
		//Pegar o valor do imovel por meio de um getter
		float valorImovel = (*itr)->getValor();
		//Caso o valor do imovel seja menor que o valor passado para pesquisa
		//coloca-se o imovel no vector que sera retornado
		if(valorPesquisa >= valorImovel)
			r.push_back(*itr);
	}
	
	return r;
}
//Funcao que retorna um vector contendo os imoveis com um numero minimo de quartos
vector <Imovel*> buscaPorQuartos(vector <Imovel*> v){
	cout << "Digite o numero de quartos minimo a ser pesquisado: ";
	int valorPesquisa;
	cin >> valorPesquisa;
	getchar();
	cout << endl;
	vector <Imovel*> r;
	//Loop que percorre o vector
	for(vector<Imovel*>:: iterator itr = v.begin(); itr != v.end(); ++itr){
		//Pegar o numero de quartos dos imoveis por meio de um getter
		int valorImovel = (*itr)->getQuartos();
		//Caso o numero de quartos do imovel seja maior ou igual ao valor passado para pesquisa
		//coloca-se o imovel no vector que sera retornado
		if(valorPesquisa <= valorImovel)
			r.push_back(*itr);
	}

	return r;
}
//Funcao que retorna um vector de um tipo de imovel ordenado de acordo com o valor
vector <Imovel*> buscarTipoOrdenado(vector <Imovel*> v){
	cout << "Digite o tipo de imovel a ser pesquisado: ";
	string valorPesquisa;
	getline(cin, valorPesquisa);
	//Tratar a string
	for_each(valorPesquisa.begin(), valorPesquisa.end(), [](char &c){c = ::toupper(c);});
	vector <Imovel*> r;
	//Loop que percorre o vector
	for(vector<Imovel*>:: iterator itr = v.begin(); itr != v.end(); ++itr){
		//Caso a pesquisa seja por apartamentos
		if(valorPesquisa == "APARTAMENTO"){
			Apartamento *auxiliar = dynamic_cast <Apartamento*>(*itr);
			if(auxiliar != nullptr)
				r.push_back(*itr);
		}
		//Caso a pesquisa seja por casas
		else if(valorPesquisa == "CASA"){
			Casa *auxiliar = dynamic_cast <Casa*>(*itr);
			if(auxiliar != nullptr)
				r.push_back(*itr);
		}
		//Caso a pesquisa seja por chacaras
		else if(valorPesquisa == "CHACARA"){
			Chacara *auxiliar = dynamic_cast <Chacara*>(*itr);
			if(auxiliar != nullptr)
				r.push_back(*itr);
		}
		//Caso tenha colocado um tipo invalido de imovel
		else{
			cout << "Tipo de imovel invalido" << endl;
			return r;
		}
	}
	//Funcao que ordena o vector
	sort(r.begin(), r.end(), [](Imovel* a, Imovel* b){return a->getValor() < b->getValor();});
	return r;
}
//Funcao que retorna todos os imoveis de uma cidade especifica
vector <Imovel*> buscarCidade(vector <Imovel*> v){
	cout << "Digite a cidade que deseja procurar por imoveis: ";
	string cidade;
	getline(cin, cidade);
	vector <Imovel*> r;
	//Loop que percorre o vector
	for(vector<Imovel*>:: iterator itr = v.begin(); itr != v.end(); ++itr){
		//Pegar cidade do imovel por meio de um getter
		string city = (*itr)->getCidade();
		//Caso seja a cidade especificada, colocar no vetor a ser retornado
		if(city == cidade){
			r.push_back(*itr);
		}
	}
	//Ordena o vector pelo valor do imovel
	sort(r.begin(), r.end(), [](Imovel* a, Imovel* b){ return a->getValor() > b->getValor();});
	return r;
}
//Funcao que retorna os imoveis de um proprietario
vector <vector <Imovel*> :: iterator > buscarImovelPorProprietario(vector <Imovel*> v){
	cout << "Digite o nome do proprietario a ser buscado: ";
	string nome;
	getline(cin, nome);
	vector <vector <Imovel*> :: iterator > r;
	//Percorre o vetor
	for(vector<Imovel*>:: iterator itr = v.begin(); itr != v.end(); ++itr){
		//Pegar o proprietario por meio de um getter
		string prop = (*itr)->getProprietario();
		//Caso seja o proprietario especificado, colocar o ITERADOR no vector
		if(prop == nome){
			r.push_back(itr);
		}
	}
	//Retorno eh um vetor de iteradores
	return r;
}
