
package SistemaImobiliaria;

public class Apartamento extends Imovel{
    private int andar;
    private double taxa_condominio;
    private boolean elevador, sacada;

    //Construtor da classe apartamento
    public Apartamento(int andar, double taxa_condominio, boolean elevador, boolean sacada, int id, int numero, int quartos, int banheiros, double valor, String proprietario, String rua, String bairro, String cidade) {
        super(id, numero, quartos, banheiros, valor, proprietario, rua, bairro, cidade);
        this.andar = andar;
        this.taxa_condominio = taxa_condominio;
        this.elevador = elevador;
        this.sacada = sacada;
    }
    
    //GETTERS E SETTERS PARA APARTAMENTO
    public int getAndar() {
        return andar;
    }

    public void setAndar(int andar) {
        this.andar = andar;
    }

    public double getTaxa_condominio() {
        return taxa_condominio;
    }

    public void setTaxa_condominio (double taxa_condominio) {
        this.taxa_condominio = taxa_condominio;
    }

    public boolean isElevador() {
        return elevador;
    }

    public void setElevador(boolean elevador) {
        this.elevador = elevador;
    }

    public boolean isSacada() {
        return sacada;
    }

    public void setSacada(boolean sacada) {
        this.sacada = sacada;
    }

    //SOBRECARGA DO OPERADOR <<
    @Override
    public String toString() {
        return super.toString() + "Elevador: " + elevador + "\n-----\n";
    }

    public Apartamento(){
    }
}
