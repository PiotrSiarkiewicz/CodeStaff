/**
 * Created by Figo on 2017-04-22.
 */
public class Players {
    private static String player1Sign;
    private static String player2Sign;
    private static String player1Name;
    private static String player2Name;


    
    private static Players ourInstance = new Players();

    public static Players getInstance() {
        return ourInstance;
    }

    private Players() {

    }


    public static String getPlayer2Sign() {
        return player2Sign;
    }

    public static String getPlayer1Name() {
        return player1Name;
    }

    public static String getPlayer2Name() {
        return player2Name;
    }

    public static String getPlayer1Sign() {

        return player1Sign;
    }

    public static void setPlayer1Sign(String player1Sign) {
        Players.player1Sign = player1Sign;
    }

    public static void setPlayer2Sign(String player2Sign) {
        Players.player2Sign = player2Sign;
    }

    public static void setPlayer1Name(String player1Name) {
        Players.player1Name = player1Name;
    }

    public static void setPlayer2Name(String player2Name) {
        Players.player2Name = player2Name;
    }
}
