/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package Telas;
import SistemaImobiliaria.*;
import javax.swing.ImageIcon;

/**
 *
 * @author Acer
 */
public class TelaMostraImovel extends javax.swing.JFrame {
    //Variaveis que recebem o imovel e a Imagem do Imovel
    //escolhido. Sao somente 3 imagens, uma para cada tipo
    //de imovel
    private Imovel item;
    private ImageIcon Imagem;
    /**
     * Creates new form TelaMostraImovel
     */
    public TelaMostraImovel() {
        initComponents();
    }
    //Construtor que recebe um imovel em especifico
    public TelaMostraImovel(Imovel imovel){
        initComponents();
        item = imovel;
    }
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane2 = new javax.swing.JScrollPane();
        InfosTxt = new javax.swing.JTextPane();
        ImagemLabel = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Detalhes do Imovel");
        setPreferredSize(new java.awt.Dimension(500, 325));
        setResizable(false);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowOpened(java.awt.event.WindowEvent evt) {
                formWindowOpened(evt);
            }
        });

        InfosTxt.setEditable(false);
        InfosTxt.setBackground(new java.awt.Color(240, 240, 240));
        InfosTxt.setBorder(javax.swing.BorderFactory.createEmptyBorder(1, 1, 1, 1));
        InfosTxt.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        InfosTxt.setOpaque(false);
        jScrollPane2.setViewportView(InfosTxt);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(ImagemLabel, javax.swing.GroupLayout.DEFAULT_SIZE, 238, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 163, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(51, 51, 51)
                .addComponent(ImagemLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 167, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(38, Short.MAX_VALUE)
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 220, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(33, 33, 33))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void formWindowOpened(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowOpened
        //Coloca as informacoes de um imovel na caixa de texto
        //utilizando o método toString(), que foi sobrecarregado
        //Na implementacao da classes de imoveis e suas classes
        //derivadas
        InfosTxt.setText(item.toString());
        //Verifica qual o tipo do imovel e mostra na tela a
        //respectiva imagem
        if(item instanceof Apartamento){
            Imagem = new ImageIcon("ApartamentoTeste.png");
            ImagemLabel.setIcon(Imagem);
        }
        else if(item instanceof Casa){
            Imagem = new ImageIcon("CasaTeste.png");
            ImagemLabel.setIcon(Imagem);
        }
        else{
            Imagem = new ImageIcon("ChacaraTeste.png");
            ImagemLabel.setIcon(Imagem);
        }
    }//GEN-LAST:event_formWindowOpened

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(TelaMostraImovel.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(TelaMostraImovel.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(TelaMostraImovel.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(TelaMostraImovel.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new TelaMostraImovel().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel ImagemLabel;
    private javax.swing.JTextPane InfosTxt;
    private javax.swing.JScrollPane jScrollPane2;
    // End of variables declaration//GEN-END:variables
}