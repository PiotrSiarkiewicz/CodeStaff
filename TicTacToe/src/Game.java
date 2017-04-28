

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;


/**
 * Created by Figo on 2017-04-21.
 */
public class Game extends JFrame  {

    private JPanel mainPanel;
    private JButton button1;
    private JButton button2;
    private JButton button3;
    private JButton button4;
    private JButton button5;
    private JButton button6;
    private JButton button7;
    private JButton button8;
    private JButton button9;
    private JLabel player2Label;
    private JLabel player1Label;
    private JLabel turnLabel;
    private int index;
    private Field[] field;
    private int playerTurn = 1;
    private File imageFile;
    private ImageIcon cross;
    private ImageIcon circle;

    private JFrame frame;
    private BufferedImage resizedImage;

    private BufferedImage backgroundImage;

    public static void main(String[] args)
    {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                Game app = new Game();


            }
        });


    }
    public Game ()
    {



        turnLabel.setText("Player 1 move");
        circle = new ImageIcon(this.getClass().getResource("/Images/circle.png"));
        cross = new ImageIcon(this.getClass().getResource("/Images/cross.png"));
        field = new Field[9];
        for(int i = 0; i<9;i++)
        {
            field[i] = new Field();

        }

        readBackground();
        DrawGUI();
        frame.addComponentListener(new ComponentListener() {
            public void componentResized(ComponentEvent e) {
                //resizeBackground();
            }

            @Override
            public void componentMoved(ComponentEvent e) {

            }

            @Override
            public void componentShown(ComponentEvent e) {

            }

            @Override
            public void componentHidden(ComponentEvent e) {

            }
        });

        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                index = 0;
                Click();
            }
        });
        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                index = 1;
                Click();
            }
        });
        button3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                index = 2;
                Click();
            }
        });
        button4.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                index = 3;
                Click();
            }
        });
        button5.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                index = 4;
                Click();
            }
        });
        button6.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                index = 5;
                Click();
            }
        });
        button7.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                index = 6;
                Click();
            }
        });
        button8.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                index = 7;
                Click();
            }
        });
        button9.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                index = 8;
                Click();
            }
        });
        index = 1;
        Click();
        field[index].setSign("");
        field[index].setChecked(false);
        button2.setIcon(new ImageIcon(this.getClass().getResource("/Images/blank.png")));
    }

    private void Click() {
        if(!field[index].isChecked())
        {

            switch (playerTurn)
            {
                case 1:
                    turnLabel.setText("Player 2 Move");
                    playerTurn = 2;
                    check(Players.getPlayer1Sign());

                    break;
                case 2:
                    turnLabel.setText("Player 1 Move");
                    playerTurn = 1;
                    check(Players.getPlayer2Sign());

                    break;
            }

        }
        else
        {
            JOptionPane.showMessageDialog(null, "This field is checked");
        }
    }

    private void check(String sign) {
        field[index].setChecked(true);
        field[index].setSign(sign);
        if(sign.equals("X")) {
            switch (index) {
                case 0:
                    button1.setIcon(cross);
                    break;
                case 1:
                    button2.setIcon(cross);
                    break;
                case 2:
                    button3.setIcon(cross);
                    break;
                case 3:
                    button4.setIcon(cross);
                    break;
                case 4:
                    button5.setIcon(cross);
                    break;
                case 5:
                    button6.setIcon(cross);
                    break;
                case 6:
                    button7.setIcon(cross);
                    break;
                case 7:
                    button8.setIcon(cross);
                    break;
                case 8:
                    button9.setIcon(cross);
                    break;
            }
        }

        if(sign.equals("O"))
            {
                switch (index)
                {
                    case 0:
                        button1.setIcon(circle);
                        break;
                    case 1:
                        button2.setIcon(circle);
                        break;
                    case 2:
                        button3.setIcon(circle);
                        break;
                    case 3:
                        button4.setIcon(circle);
                        break;
                    case 4:
                        button5.setIcon(circle);
                        break;
                    case 5:
                        button6.setIcon(circle);
                        break;
                    case 6:
                        button7.setIcon(circle);
                        break;
                    case 7:
                        button8.setIcon(circle);
                        break;
                    case 8:
                        button9.setIcon(circle);
                        break;
                }
        }

        enOfGame();
    }
    private  int loop(int x , int z, int y)
    {
        int count = 0;
        for(int i = x; i<z; i+=y) {
            if (field[i].isChecked()) {
                if (field[i].getSign().equals("X")) count++;
                else
                    count = 0;
            }
        }
        if(count < 3)
        {
            count = 0;
            for(int i = x; i<z; i+=y)
            {
                if (field[i].isChecked())
                    if(count < 3) {
                        if (field[i].getSign().equals("O"))
                            count ++;
                        else
                            count = 0;
                    }
            }

        }
        return count;
    }

    private void enOfGame() {
        int count,x,y = 0;

        count = loop(0,9,3);
        if (count == 3)winner();

        count = loop(1,9,3);
        if (count == 3)winner();

        count = loop(2,9,3);
        if (count == 3)winner();

        count = loop(0,3,1);
        if (count == 3)winner();

        count = loop(3,6,1);
        if (count == 3)winner();


        count = loop(6,9,1);
        if (count == 3)winner();


        count = loop(0,9,4);
        if (count == 3)winner();


        count = loop(2,7,2);
        if (count == 3)winner();


        remis();
    }

    private void remis() {
        int count = 0;
        for(int i=0; i<9;i++)
            if(field[i].isChecked()) count++;
        if(count == 9)
        {
            JOptionPane.showMessageDialog(null,"Remis");
            frame.dispose();
        }
    }

    private void winner() {
        if(playerTurn == 1)
        {
            JOptionPane.showMessageDialog(null, "Player 2 Wins");
        }else
        {
            JOptionPane.showMessageDialog(null, "Player 1 Wins");
        }
        frame.dispose();


    }

    public void resizeBackground()
    {
        resizedImage=resize(backgroundImage,frame.getWidth(), frame.getHeight());

    }


    public void readBackground()
    {

        try {
            backgroundImage = ImageIO.read(this.getClass().getResource("/Images/grid.png"));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public void DrawGUI(){



        frame = new JFrame("TicTacToe")
        {
            public void paint(Graphics g)
            {

                super.paint(g);
                g.drawImage(backgroundImage,0,0,null);
            }

        };

        frame.setContentPane(mainPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setSize(442,470);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        player1Label.setText("Plyer1:   "+Players.getPlayer1Name());
        player2Label.setText("Plyer2:   "+Players.getPlayer2Name());

    }



    public static BufferedImage resize(BufferedImage image, int width, int height) {
        BufferedImage bi = new BufferedImage(width, height, BufferedImage.TRANSLUCENT);
        Graphics2D g2d = (Graphics2D) bi.createGraphics();
        g2d.addRenderingHints(new RenderingHints(RenderingHints.KEY_RENDERING, RenderingHints.VALUE_RENDER_QUALITY));
        g2d.drawImage(image, 0, 0, width, height, null);
        g2d.dispose();
        return bi;
    }
}
