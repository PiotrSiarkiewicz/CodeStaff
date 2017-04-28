import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by Figo on 2017-04-21.
 */
public class PlayerSett extends JFrame {
    private JFrame frame;
    private JButton doneButton;
    private JPanel mainPanel;
    private JTextField player1Name;
    private JTextField player2Name;
    private JComboBox player1Box;
    private JComboBox player2Box;


    public PlayerSett() {

        frame = new JFrame("Player Settings");
        frame.setContentPane(mainPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setSize(400,200);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);




        doneButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                String name1 = player1Name.getText();
                String name2 = player2Name.getText();
                String sign1 = player1Box.getSelectedItem().toString();
                String sign2 = player2Box.getSelectedItem().toString();
                boolean check = true;
                if(name1.equals("") || name2.equals(""))
                {
                    JOptionPane.showMessageDialog(null,"Please set all names for players");
                    check = false;
                }
                if(player1Box.getSelectedItem().toString().equals(player2Box.getSelectedItem().toString()))
                {
                    JOptionPane.showMessageDialog(null,"Signs for players need to be different");
                    check = false;
                }
                if(check == true)
                {
                    JOptionPane.showMessageDialog(null,"Lets start The Game!");
                    frame.setVisible(false);

                    Players.setPlayer1Name(name1);
                    Players.setPlayer2Name(name2);
                    Players.setPlayer1Sign(sign1);
                    Players.setPlayer2Sign(sign2);
                    Game frame2 = new Game();
                    frame.dispose();


                }
            }

        });

    }



    public static void main(String[] args)
    {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                PlayerSett app = new PlayerSett();
            }
        });


    }





}
