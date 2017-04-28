/**
 * Created by Figo on 2017-04-22.
 */
public class Field {
    private boolean checked;
    private String sign;

    public boolean isChecked() {
        return checked;
    }

    public String getSign() {
        return sign;
    }

    public void setChecked(boolean checked) {
        this.checked = checked;
    }

    public void setSign(String sign) {
        this.sign = sign;
    }
    public Field()
    {
        checked = false;
    }

}
