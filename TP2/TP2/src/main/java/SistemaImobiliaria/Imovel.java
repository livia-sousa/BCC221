
package SistemaImobiliaria;

public class Imovel implements Comparable <Imovel>{
    private int id, numero, quartos, banheiros;
    private double valor;
    private String proprietario, rua, bairro, cidade;
    
    //Sobrecarga do <<
    @Override
    public String toString() {
        return "-----\nProprietario: " + proprietario + "\nValor do Imovel: "  + valor + "\nNumero de Quartos: " + quartos + "\nRua: " + rua + "\nBairro: " + bairro + "\nCidade: " + cidade + "\n";
    }
    
    //Construtor de Imovel vazio
    public Imovel() {
        id = numero = quartos = banheiros = 0;
        valor = 0;
        proprietario = "";
        rua = "";
        bairro = "";
        cidade = "";
    }
    
    //Construtor de imovel
    public Imovel(int id, int numero, int quartos, int banheiros, double valor, String proprietario, String rua, String bairro, String cidade) {
        this.id = id;
        this.numero = numero;
        this.quartos = quartos;
        this.banheiros = banheiros;
        this.valor = valor;
        this.proprietario = proprietario;
        this.rua = rua;
        this.bairro = bairro;
        this.cidade = cidade;
    }
    //Getters e Setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public int getQuartos() {
        return quartos;
    }

    public void setQuartos(int quartos) {
        this.quartos = quartos;
    }

    public int getBanheiros() {
        return banheiros;
    }

    public void setBanheiros(int banheiros) {
        this.banheiros = banheiros;
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    public String getProprietario() {
        return proprietario;
    }

    public void setProprietario(String proprietario) {
        this.proprietario = proprietario;
    }

    public String getRua() {
        return rua;
    }

    public void setRua(String rua) {
        this.rua = rua;
    }

    public String getBairro() {
        return bairro;
    }

    public void setBairro(String bairro) {
        this.bairro = bairro;
    }

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }
    
    //Implementacao da funcao compareTo, que implementa a
    //interface Comparable
    @Override
    public int compareTo(Imovel o) {
        if(valor > o.valor)
            return 1;
        else if(valor == o.valor)
            return 0;
        else
            return -1;
    }
    
}