
package SistemaImobiliaria;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ListIterator;
public class Funcoes {
    
    //Construtor da classe Funcoes
    public Funcoes(){
    }
    //funcao que le o arquivo
    public void lerArquivo(ArrayList <Imovel> v){
        Scanner arq = null;
        try{
            arq = new Scanner(new File("../database_imoveis.txt"));
        }
        catch(FileNotFoundException e){
            System.err.println("Error opening File");
            System.exit(1);
        }
        int i = 1;
        //loop que le os dados do arquivo 
        while(arq.hasNext()){
            StringTokenizer tok = new StringTokenizer(arq.nextLine(), ";");
            ArrayList <String> s = new ArrayList <>();
            while(tok.hasMoreTokens()){
                s.add(tok.nextToken());
                
            }
            String[] arm = new String[s.size()];
            s.toArray(arm);
            
            //switch case para verificar o tipo de propriedade
            switch (arm[0]) {
                //caso seja um apartamento
                case "apartamento" ->                     {
                        Apartamento objeto = new Apartamento();
                        objeto.setId(i);
                        objeto.setValor(Double.parseDouble(arm[1]));
                        objeto.setProprietario(arm[2]);
                        objeto.setRua(arm[3]);
                        objeto.setBairro(arm[4]);
                        objeto.setCidade(arm[5]);
                        objeto.setNumero(Integer.parseInt(arm[6]));
                        objeto.setQuartos(Integer.parseInt(arm[7]));
                        objeto.setBanheiros(Integer.parseInt(arm[8]));
                        objeto.setAndar(Integer.parseInt(arm[9]));
                        objeto.setTaxa_condominio(Double.parseDouble(arm[10]));
                        objeto.setElevador(intToBool(Integer.parseInt(arm[11])));
                        objeto.setSacada(intToBool(Integer.parseInt(arm[12])));
                        v.add(objeto);
                    }
                //caso seja uma casa
                case "casa" ->                     {
                        Casa objeto = new Casa();
                        objeto.setId(i);
                        objeto.setValor(Double.parseDouble(arm[1]));
                        objeto.setProprietario(arm[2]);
                        objeto.setRua(arm[3]);
                        objeto.setBairro(arm[4]);
                        objeto.setCidade(arm[5]);
                        objeto.setNumero(Integer.parseInt(arm[6]));
                        objeto.setQuartos(Integer.parseInt(arm[7]));
                        objeto.setBanheiros(Integer.parseInt(arm[8]));
                        objeto.setAndares(Integer.parseInt(arm[9]));
                        objeto.setSala_jantar(intToBool(Integer.parseInt(arm[10])));
                        v.add(objeto);
                    }
                //caso seja uma chacara
                default ->                     {
                            Chacara objeto = new Chacara();
                            objeto.setId(i);
                            objeto.setValor(Double.parseDouble(arm[1]));
                            objeto.setProprietario(arm[2]);
                            objeto.setRua(arm[3]);
                            objeto.setBairro(arm[4]);
                            objeto.setCidade(arm[5]);
                            objeto.setNumero(Integer.parseInt(arm[6]));
                            objeto.setQuartos(Integer.parseInt(arm[7]));
                            objeto.setBanheiros(Integer.parseInt(arm[8]));
                            objeto.setSalao_festa(intToBool(Integer.parseInt(arm[9])));
                            objeto.setSalao_jogos(intToBool(Integer.parseInt(arm[10])));
                            objeto.setCampo_futebol(intToBool(Integer.parseInt(arm[11])));
                            objeto.setChurrasqueira(intToBool(Integer.parseInt(arm[12])));
                            objeto.setPiscina(intToBool(Integer.parseInt(arm[13])));
                            v.add(objeto);
                    }
            }
            i++;
        }
        arq.close(); //fecha o arquivo
    }
    
    
    //funcao que converte um valor inteiro em booleano
    public boolean intToBool(int i){
        return (i > 0);
    }
    
    //Funcao que busca se um proprietario eh dono de um dos imoveis
    public boolean buscaProprietario(ArrayList <Imovel> v, String nome){
        
        //Loop que percorre o ArrayList
        for(Imovel E : v){
            //utiliza o getter para pegar um proprietario 
            String prop = E.getProprietario();
            if(prop.equals(nome)){
                return true;
            }
        }

        return false;   
    }
     
     //Funcao que retorna um ArrayList contendo os imoveis menores que um valor passado
    public ArrayList <Imovel> buscaPorValor(ArrayList <Imovel> v, double valorPesquisa){
	
	ArrayList <Imovel> r = new ArrayList <>();
        //Loop que percorre o ArrayList
	for(var E : v){
                //utiliza o getter para pegar o valor do imovel
		double valorImovel = E.getValor();
                
                //Caso o valor do imovel seja menor que o valor passado para pesquisa
		//coloca-se o imovel no ArrayList que sera retornado
		if(valorPesquisa >= valorImovel)
			r.add(E);
	}
        
	return r;
        
    }
    
    //Funcao que retorna um ArrayList contendo os imoveis com um numero minimo de quartos
    public ArrayList <Imovel> buscaPorQuartos(ArrayList <Imovel> v, int valorPesquisa){
        
        ArrayList <Imovel> r = new ArrayList <>();
        
        //loop que percorre o ArrayList
        for(var E : v){
            //utiliza o getter para pegar o numero de quartos dos imoveis 
            int valorImovel = E.getQuartos();
            
            //Caso o numero de quartos do imovel seja maior ou igual ao valor passado para pesquisa
            //coloca-se o imovel no ArrayList que sera retornado
            if(valorPesquisa <= valorImovel)
               r.add(E);
        }

	return r;
    } 
    
    //Funcao que retorna todos os imoveis de uma cidade especifica
    public ArrayList <Imovel> buscarCidade(ArrayList <Imovel> v, String nome){
       
        ArrayList <Imovel> r = new ArrayList <>();
        
        //loop que percorre o ArrayList
        for(Imovel E : v){
            //Pegar cidade do imovel por meio de um getter
            String city = E.getCidade();
            //Caso seja a cidade especificada, colocar no ArrayList a ser retornado
            if(nome.equals(city)){
                r.add(E);
            }
        }
        //ordena o ArrayList pelo valor do imovel
        r.sort((a,b) -> a.compareTo(b));
        return r;
    }
    //Funcao que retorna uma List de Iteradores do tipo Imovel de acordo com um Proprietario
    public ListIterator <Imovel> buscarImovelPorProprietario(ArrayList <Imovel> v, String nome){

	ArrayList <Imovel> r = new ArrayList <>();
	for(var E : v){
            //Pegar o proprietario por meio de um getter
            String prop = E.getProprietario();
            //Caso seja o proprietario especificado, colocar o ITERADOR no ArrayList
            if(prop.equals(nome)){
                r.add(E);
            }
	}
	//Retorno eh uma List de iteradores
        ListIterator <Imovel> u = r.listIterator();
	return u;
    }

    //Funcao que retorna um ArrayList de um tipo de imovel ordenado de acordo com o valor
    public ArrayList <Imovel> buscarTipoOrdenado(ArrayList <Imovel> v, String valorPesquisa){
        
	ArrayList <Imovel> r = new ArrayList <>();
	//Loop que percorre o ArrayList
	for(Imovel E : v){
            //Switch case para verificar o tipo de propriedade
            switch (valorPesquisa) {
                case "Apartamento":
                    if(E instanceof Apartamento)
                        r.add(E);
                    break;
                case "Casa":
                    if(E instanceof Casa)
                        r.add(E);
                    break;
                case "Chacara":
                    if(E instanceof Chacara)
                        r.add(E);
                    break;
                default:
                    System.out.println("Tipo de imovel invalido");
                    return r;
            }
	}
	//Funcao que ordena o ArrayList
	r.sort((a,b) -> a.compareTo(b));
	return r;
    }
}
