package com.company;

import javax.swing.*;
import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        Map map = new Map(3, 3);
        map.display();
        Scanner sc = new Scanner(System.in);
        int x, y;
        System.out.println("Wbierz liczbę min:");

        map.deployMines(sc.nextInt(), true);

        while (map.endOfGame == false && map.mines > 0) {
            map.display();
            System.out.println("Chcesz odkryć pole czy oznaczyć flagą?");
            System.out.println("1.Odkyć");
            System.out.println("2.Oznaczyć flagą");
            System.out.println("3.Odnaczyć flage");

            switch (sc.nextInt()) {
                case 1:
                    System.out.println("Podaj współrzędne");
                    x = sc.nextInt();
                    y = sc.nextInt();
                    if(map.height>x && x>=0 && map.weight>y && y>=0)
                        map.reveal(x, y);
                    break;
                case 2:
                    System.out.println("Podaj współrzędne");
                    x = sc.nextInt();
                    y = sc.nextInt();
                    if(map.height>x && x>=0 && map.weight>y && y>=0)
                        map.flagOn(x, y);
                    break;
                case 3:
                    System.out.println("Podaj współrzędne");

                    x = sc.nextInt();
                    y = sc.nextInt();
                    if(map.height>x && x>=0 && map.weight>y && y>=0)
                        map.flagOff(x, y);
                    break;
            }

        }
        map.display();
        if(map.endOfGame == false && map.mines==0)
        {
            System.out.println("Gratuluję wygranej");
        }
        else
        {
            System.out.println("Przegrana");
        }
    }
}
