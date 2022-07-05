//INTEGRANTES DO GRUPO
//Clara Luiza Alemar Ribas - 20.1.4008
//Karine Isabelle Marins - 20.1.4057
//Lívia Stéffanny de Sousa - 20.1.4029
//Pedro Henrique Oliveira da Silva - 20.1.4005


#include "funcoes.h"
#include "imovel.h"
#include "casa.h"
#include "apartamento.h"
#include "chacara.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main(){
    //Utilizado o container vector para manipulacao das classes
    vector <Imovel*> v;
    //Funcao que le o arquivo de entrada database_imoveis.txt
    lerArquivo(v);
    //Variavel de finalizacao do programa
    bool LogOut = false;
    //Loop que executa o programa
    while(!LogOut){
        system("clear");
        //Utiliza-se strings para pegar a entrada de comando
        string entrada;
        entrada.clear();
        vector <string> cmd;
        cmd.clear();
        //Funcao que imprime o menu
        printMenu();
        getline(cin, entrada);
        istringstream iss(entrada);
		string token;
        token.clear();
        //Loop que separa o os espaos das palavras em strings diferentes. Necessario para o comando 1
		while (getline(iss, token, ' ')){
			cmd.push_back(token);
		}
        int i;
        //Verifica se o primeiro caracter da entrada eh um digito. Caso nao seja, realizar a funcao stoi() ira resultar
        //em um erro de segmentacao
        if(isdigit(cmd[0][0]))  
            i = stoi(cmd[0]);
        else
            i = 12;
        //Switch case que representa qual funcao sera utilizada
        switch(i){
            //0 = LogOut
            //1 = Imprimir os imoveis
            //2 = Verificar se existe um proprietario especifico na lista
            //3 = Realizar busca por valor do imovel
            //4 = Realizar busca por numero de quartos
            //5 = Realizar busca por tipo de imovel. O conjunto retorna ordenado pelo valor do imovel
            //6 = Realizar busca por nome de cidade.
            //7 = Realizar busca por nome de proprietario.
            case 0:
                LogOut = true;
                break;
            case 1:{
                //Caso seja mais de um comando na linha
                if(cmd.size() != 1){
                    string p(cmd[1]);
                    //Imprime em arquivo externo caso o comando seja '-s'
                    if(p == "-s"){
                        cout << "\n✅ Imprimindo todos os imoveis disponiveis em um arquivo de texto! " << endl;
                        ImprimeContainer(v, true);
                    }
                    //Imprime no main
                    else{
                        cout << "\n✅ Imprimindo todos os imoveis disponiveis: " << endl;
                        ImprimeContainer(v, false);
                    }  
                
                                             
                }
                //Imprime no main
                else{
                    cout << "\n✅ Imprimindo todos os imoveis disponiveis: " << endl;
                    ImprimeContainer(v, false);
                }
                    
                break;
            }
            case 2:{
                //Realiza busca por um proprietario
                if(buscaProprietario(v))
                    cout << "\n ✅ Este proprietario esta no banco de dados! ✅ " << endl;
                else
                    cout << "\n⚠️  Este proprietario nao se encontra em banco de dados! ⚠️" << endl;
                break;
            }
            case 3:{
                //Vetor que sera armazenado o retorno
                vector <Imovel*> r = buscaPorValor(v);
                //Caso o tamanho do vetor seja 0, nao ha imoveis que seguem o requisito pesquisado
                if(r.size() == 0)
                    cout << "\n⚠️  Nenhum imovel abaixo desse valor foi encontrado! ⚠️" << endl;
                else{
                    cout << "\n✅ Imprimindo imoveis abaixo do valor solicitado: " << endl;
                    ImprimeContainer(r, false);
                }
                r.clear();
                break;
            }
            case 4:{
                vector <Imovel*> r = buscaPorQuartos(v);
                //Caso o tamanho do vetor seja 0, nao ha imoveis que seguem o requisito pesquisado
                if(r.size() == 0)
                    cout << "\n ⚠️  Nenhum imovel com esse numero de quartos foi encontrado ⚠️ " << endl;
                else{
                    cout << "\n✅ Imprimindo imoveis com o numero de quartos solicitado: "  << endl;
                    ImprimeContainer(r, false);
                }
                r.clear();
                break;
            }
            case 5:{
                vector <Imovel*> r = buscarTipoOrdenado(v);
                //Caso o tamanho do vetor seja 0, nao ha imoveis que seguem o requisito pesquisado
                if(r.size() == 0)
                    cout << "\n ⚠️  Nenhum imovel por abaixo desse valor foi encontrado ⚠️ " << endl;
                else{
                    cout << "\n✅ Imprimindo imoveis abaixo do valor desejado: " << endl;
                    ImprimeContainer(r, false);
                } 
                r.clear();
                break;
            }
            case 6:{
                vector <Imovel*> r = buscarCidade(v);
                //Caso o tamanho do vetor seja 0, nao ha imoveis que seguem o requisito pesquisado
                if(r.size() == 0)
                    cout << "\n⚠️  Nenhum imovel nessa cidade foi encontrado ⚠️ " << endl;
                else{
                    cout <<"\n✅ Imprimindo imoveis encontrados nesta cidade: " << endl;
                    ImprimeContainer(r, false);
                }   
                r.clear();
                break;
            }
            case 7:{
                vector <vector <Imovel*> :: iterator> r = buscarImovelPorProprietario(v);
                //Caso o tamanho do vetor seja 0, nao ha imoveis que seguem o requisito pesquisado
                if(r.size() == 0)
                    cout << "⚠️ Nenhum imovel para este proprietario foi encontrado ⚠️ " << endl;
                else{
                    cout << "\n✅ Imprimindo imoveis deste proprietario: " << endl;
                    //Loop para imprimir os imoveis
                    for(vector <vector<Imovel*>:: iterator > :: iterator itr = r.begin(); itr != r.end(); ++itr){
		                cout << *(*(*itr));
	                }
                }
                r.clear();
                break;
            }
            //Caso o comando seja invalido
            default:
                cout << "⚠️  Comando invalido! ⚠️ " << endl;
        }
        cout << endl;
        if(!LogOut){
            cout << "▶️  Pressione enter para continuar ";
            char c;
            c = getchar();
            //Caso o enter nao seja pressionado, fica em loop ate se apertar o enter
            while(c != 10){
                c = getchar();
            }
        }
        
        
    }

}
