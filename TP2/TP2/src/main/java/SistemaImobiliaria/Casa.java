
package SistemaImobiliaria;


public class Casa extends Imovel{
    private int andares;
    private boolean sala_jantar;

    public Casa() {
    }
    //Construtor de Casa
    public Casa(int andares, boolean sala_jantar, int id, int numero, int quartos, int banheiros, double valor, String proprietario, String rua, String bairro, String cidade) {
        super(id, numero, quartos, banheiros, valor, proprietario, rua, bairro, cidade);
        this.andares = andares;
        this.sala_jantar = sala_jantar;
    }

    //GETTERS E SETTER DE CASA
    public int getAndares() {
        return andares;
    }

    public void setAndares(int andares) {
        this.andares = andares;
    }

    public boolean isSala_jantar() {
        return sala_jantar;
    }

    public void setSala_jantar(boolean sala_jantar) {
        this.sala_jantar = sala_jantar;
    }

    //SOBRECARGA DO OPERADOR <<    
    @Override
    public String toString() {
        return super.toString() + "Andares: " + andares +  "\n-----\n";
    }
    
    
}
