package algorithm;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.io.*;
import java.util.Scanner;

public class Algorithm implements ActionListener {
    
    JLabel l1,l2,l3,l4,l5,l6,l7;
    JTextField t1,t2,t3,t4,t5,t6,t7;
    JTextArea ta1, ta2;
    JButton jbtn, sc, csc;
    JComboBox<Integer> cb;
    
    Algorithm(){
        
        JFrame jfrm = new JFrame("Scan and Cscan");
        jfrm.setLayout(null);
        jfrm.setSize(500, 500);
        jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
       l7 = new JLabel("Insert the following information");
       l7.setBounds(60,10,250,30);
       
       l1 = new JLabel("Enter the number of Tracks");
       t1 = new JTextField();
       l1.setBounds(10,50,200,30);
       t1.setBounds(200, 50, 100, 30);
       
       l2 = new JLabel("Enter initial head position");
       t2 = new JTextField();
       l2.setBounds(10,90,200,30);
       t2.setBounds(200, 90, 100, 30);
       
       l3 = new JLabel("Enter total disk size");
       t3 = new JTextField();
       l3.setBounds(10,130,200,30);
       t3.setBounds(200, 130, 100, 30);
       
       l4 = new JLabel("Enter the head movement direction(1/0)");
       cb = new JComboBox<Integer>();
       cb.addItem(0);
       cb.addItem(1);
       l4.setBounds(10,170,250,30);
       cb.setBounds(250, 170, 100, 30);
       
       l5 = new JLabel("Enter the requests separated by comma");
       t5 = new JTextField();
       l5.setBounds(10, 210,250,30);
       t5.setBounds(250, 210, 200, 30);
       
       jbtn = new JButton("Submit");
       jbtn.setBounds(80, 250, 100, 30);
       
       sc = new JButton("Scan");
       csc = new JButton("CScan");
       sc.setBounds(10, 290, 100, 30);
       csc.setBounds(10, 330, 100, 30);
       
       ta1 = new JTextArea();
       ta2 = new JTextArea();
       ta1.setBounds(150, 290, 200, 30);
       ta2.setBounds(150, 330, 200, 30);
       
       
       jbtn.addActionListener(this);
       sc.addActionListener(this);
       csc.addActionListener(this);

       
//       t5.addKeyListener(new KeyAdapter() {
//         public void keyPressed(KeyEvent ke) {
//            String value = t5.getText();
//            int l = value.length();
//            if (ke.getKeyChar() >= '0' && ke.getKeyChar() <= '9') {
//               t5.setEditable(true);
//            } else {
//               t5.setEditable(false);
//            }
//         }
//      });
       
       
       jfrm.add(l7);
       jfrm.add(l1);
       jfrm.add(l2);
       jfrm.add(l3);
       jfrm.add(l4);
       jfrm.add(l5);
       jfrm.add(t1);
       jfrm.add(t2);
       jfrm.add(t3);
       jfrm.add(cb);
       jfrm.add(t5);
       jfrm.add(jbtn);
       jfrm.add(sc);
       jfrm.add(csc);
       jfrm.add(ta1);
       jfrm.add(ta2);
       
       
       jfrm.setVisible(true);
    }
    
    @Override
    public void actionPerformed(ActionEvent ae){
        
        String submit = ae.getActionCommand();
        int numReq, initial, size, dir;
        PrintWriter pw;
        Scanner scr,cscr;
        
        if (submit.equals("Submit")){
            numReq = Integer.parseInt(t1.getText());
            initial = Integer.parseInt(t2.getText());
            size = Integer.parseInt(t3.getText());
            dir = (int) cb.getSelectedItem();
            
            String str = t5.getText();
            String strA[] = new String[numReq];
            strA = str.split(",");
            int nums []= new int[numReq];
            for (int i = 0 ; i < nums.length ; i++){
                nums[i] = Integer.parseInt(strA[i]);
            }
                        
            try{
                
                pw = new PrintWriter("C:\\Users\\hp\\Desktop\\input.txt");
                pw.println(numReq);
                pw.println(initial);
                pw.println(size);
                pw.println(dir);
                
                for (int i = 0 ; i < nums.length ; i++){
                    pw.println(nums[i]);
                }
                pw.flush();
                pw.close();
            }
            catch (IOException exc){
                System.out.println("Write error: " + exc.getMessage());
            }
        }
        
        try{
            scr = new Scanner(new File("C:\\Users\\hp\\Desktop\\scan.txt"));
            String str = "";
            while (scr.hasNextLine()){
                str = scr.nextLine();
            }
            
            if (ae.getSource() == sc){
            ta1.setText(str);
            }
            cscr = new Scanner(new File("C:\\Users\\hp\\Desktop\\cscan.txt"));
            String str2 = "";
            while (cscr.hasNextLine()){
                str2 = cscr.nextLine();
            }
            if (ae.getSource() == csc){
                ta2.setText(str2);
            }
        }
        catch(IOException exc){
            System.out.println("read error: " + exc.getMessage());
        }
        
    }
   
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            
            @Override
            public void run() {
                new Algorithm();
            }
        });
    }
}
