
package SistemaImobiliaria;


public class Chacara extends Imovel{
    private boolean salao_festa, salao_jogos, campo_futebol, churrasqueira, piscina;

    public Chacara() {
    }
       
    //Construtor de Chacara
    public Chacara(boolean salao_festa, boolean salao_jogos, boolean campo_futebol, boolean churrasqueira, boolean piscina, int id, int numero, int quartos, int banheiros, double valor, String proprietario, String rua, String bairro, String cidade) {
        super(id, numero, quartos, banheiros, valor, proprietario, rua, bairro, cidade);
        this.salao_festa = salao_festa;
        this.salao_jogos = salao_jogos;
        this.campo_futebol = campo_futebol;
        this.churrasqueira = churrasqueira;
        this.piscina = piscina;
    }

    //GETTERS E SETTERS DE CHACARA
    public boolean isSalao_festa() {
        return salao_festa;
    }

    public void setSalao_festa(boolean salao_festa) {
        this.salao_festa = salao_festa;
    }

    public boolean isSalao_jogos() {
        return salao_jogos;
    }

    public void setSalao_jogos(boolean salao_jogos) {
        this.salao_jogos = salao_jogos;
    }

    public boolean isCampo_futebol() {
        return campo_futebol;
    }

    public void setCampo_futebol(boolean campo_futebol) {
        this.campo_futebol = campo_futebol;
    }

    public boolean isChurrasqueira() {
        return churrasqueira;
    }

    public void setChurrasqueira(boolean churrasqueira) {
        this.churrasqueira = churrasqueira;
    }

    public boolean isPiscina() {
        return piscina;
    }

    public void setPiscina(boolean piscina) {
        this.piscina = piscina;
    }

    //SOBRECARGA DO OPERADOR <<
    @Override
    public String toString() {
        return super.toString() + "Piscina: " + piscina + "\n-----\n";
    }
    
    

}
