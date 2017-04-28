package com.company;

/**
 * Created by Figo on 2017-03-13.
 */
public class Field
{
    private
        int bomb,hide,flag;

    public Field()
    {
        bomb = 0;
        hide = 0;
        flag = 0;
    }

    public void setBomb(int bomb) {
        this.bomb = bomb;
    }

    public void setFlag(int flag) {
        this.flag = flag;
    }

    public void setHide(int hide) {
        this.hide = hide;
    }

    public int getFlag() {
        return flag;
    }

    public int getBomb() {
        return bomb;
    }

    public int getHide() {
        return hide;
    }

    public void info()
    {
        System.out.println("["+bomb+hide+flag+"]");
    }





}
