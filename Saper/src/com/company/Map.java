package com.company;

import com.sun.org.apache.xpath.internal.SourceTree;

import java.util.Random;

/**
 * Created by Figo on 2017-03-13.
 */
public class Map {
    int height;
    int weight;
    Field[][] field;
    int mines;
    boolean endOfGame=false;
    boolean win=false;
    public Map(int h,int w)
    {
         height = h;
         weight = w;

        field = new Field[h][w];
        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[i].length; j++) {
                field[i][j] = new Field();
            }
        }

    }
    public void deployMines(int n, boolean  random)
    {
        mines = n;
        if(random == true)
        {
            Random rand = new Random();

            for(int y=0;y<n;y++)
            {
                field[rand.nextInt(height)][rand.nextInt(weight)].setBomb(1);
            }

        }
        else
        {
            int j=0;
            for(int i=0;i<field[0].length;i++)
            {
                field[0][i].setBomb(1);
                field[j++][i].setBomb(1);
            }

        }
    }
    public void debug_Display()
    {
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<weight;j++)
                field[i][j].info();
            System.out.println();
        }
    }
    public boolean hasMine(int x, int y)
    {
        if(field[x][y].getBomb()==1 && y<weight && x<height)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public int countMines(int x, int y)
    {
        int count=0;
       for(int i=x-1; i<=x+1;i++)
           for(int j=y-1;j<=y+1;j++)
               if(0<=i && i<height && 0<=j && j<weight)
                 if(hasMine(i,j)==true)
                    count++;
        return count;
    }
    public void display()
    {
        clear();

        for(int i=0;i<height;i++)
        {
            for(int j=0;j<weight;j++)
            {

                if(field[i][j].getHide()==0  && field[i][j].getFlag()==0) System.out.print("[.]");
                if(field[i][j].getFlag()==1 && field[i][j].getHide()==0) System.out.print("[?]");
                if(field[i][j].getHide()==1
                        && countMines(i,j)==0
                        && hasMine(i,j)== false) System.out.print("[ ]");
                if(field[i][j].getHide()==1
                        && countMines(i,j)>0
                        && hasMine(i,j)== false) System.out.print("["+countMines(i,j)+"]");
                if(field[i][j].getHide()==1
                        && hasMine(i,j)==true) System.out.print("[X]");

            }
            System.out.println();
        }
    }
    public void reveal(int x ,int y)
    {
        field[x][y].setHide(1);
        if(hasMine(x,y)==true)endOfGame=true;
    }
    public void flagOn(int x,int y)
    {
        field[x][y].setFlag(1);
        if(field[x][y].getBomb()==1)
            mines--;
        else
        {
            mines++;
        }

    }
    public void flagOff(int x, int y)
    {
        field[x][y].setFlag(0);
        if(field[x][y].getBomb()==1)
            mines++;
        else
        {
            mines--;
        }

    }

    public void clear()
    {
        for(int i=0;i<10;i++)
        {
            System.out.println();
        }
    }


}
