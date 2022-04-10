import java.awt.Color;
import java.awt.GridLayout;
import java.util.LinkedList;
import javax.swing.*;

public class Table extends javax.swing.JFrame {
    
    //Access the Calculation class
    Calculation calc = new Calculation();
    
   
    JButton[] buttons;
    // Make Link list for marked numbers 
      LinkedList<Integer> primes = new LinkedList<Integer>();
      
      //This function will initialize the table
    void initTable(int num){
         num++;
          buttons = new JButton[num];
  
        JPanel panel = new JPanel();
        panel.setBounds(0, 50, 600, 600);
        buttons[1] = new JButton("1");
        buttons[1].setBackground(Color.GRAY);
        panel.add(buttons[1]);
        for(int i = 2; i < num ;i++){
            buttons[i] = new JButton(Integer.toString(i));
            buttons[i].setBackground(Color.GREEN);
            
          
            panel.add(buttons[i]);
        }
        panel.setLayout(new GridLayout(num/10,10));
        
        
        this.add(panel);
    }
    
    // This function will find the next not marked number
    // and find its multiple
    int nextNotMarked(){
     currentPosition++;

       
          

            //traverse through the linked list to find the prime
              
            for(int o = 0; o< primes.size();o++){
                if(primes.get(o) == currentPosition){
                      currentPosition++;
                   
                } 
            } 
   
            return currentPosition;
     }
    
    // This will update the table
    // Marked items will turn red
    void updateTable(int num, int multipleOf){
        
        calc.multiples(num+1,multipleOf);
        primes = calc.marked;
        num++;

        for(int i = 2; i < num ;i++){
            buttons[i].setBackground(Color.GREEN);

            //traverse through the linked list to find marked numbers
            //And change the color accordingly
 
            for(int o = 0; o< primes.size();o++){
                if(primes.get(o)== i){
                     buttons[i].setBackground(Color.RED);
                }
            } 
   
        }
    }
    
    
    //INITIALIZER OF THE PROGRAM
    //will start at 2 cuz 1 is already a prime
    public int currentPosition = 2;
    public int maxNum; // will hold the input of the user
    public Table(int num) {
        initComponents();
        this.setResizable(false);
        initTable(num);
        maxNum = num;

    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jButton1 = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Sieve of Eratosthenes Table");
        setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));

        jLabel1.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("THE TABLE");

        jButton1.setFont(new java.awt.Font("Tahoma", 1, 11)); // NOI18N
        jButton1.setText("NEXT");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jLabel2.setForeground(new java.awt.Color(255, 0, 0));
        jLabel2.setText("RED = NOT PRIME");

        jLabel3.setForeground(new java.awt.Color(51, 204, 0));
        jLabel3.setText("GREEN = PRIME");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(36, 36, 36)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel2)
                        .addGap(42, 42, 42)
                        .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 225, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jLabel3))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 130, Short.MAX_VALUE)
                .addComponent(jButton1)
                .addGap(19, 19, 19))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLabel3))
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jButton1)
                        .addComponent(jLabel1)))
                .addContainerGap(605, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    
    public int index = 1;
    
    // When next button is clicked
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // TODO add your handling code here:
        if(currentPosition == 2){
            updateTable(maxNum,2);
            currentPosition++;
        } else{
        
           int nextNum = nextNotMarked();
           //check first if the current number is greater than the input of the user
           if((nextNum +1) * (nextNum+1) > maxNum){
                JOptionPane.showMessageDialog(null, "FINISHED!");
                this.setVisible(false);
                new TryDialog().setVisible(true);
           } else{
               // if not
               // update the table
               if(nextNum != 0){
                   updateTable(maxNum,nextNum);
               }
           }
        
        }
    }//GEN-LAST:event_jButton1ActionPerformed

    /**
     * @param args the command line arguments
     */


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    // End of variables declaration//GEN-END:variables
}
