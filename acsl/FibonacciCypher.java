import java.math.BigInteger;
import java.util.Arrays;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

import javax.security.auth.x500.X500Principal;

class Result {

    private static BigInteger[] fibonacci;
    private static char[] alphabet = "abcdefghijklmnopqrstuvwxyz".toCharArray();

    /*
     * Complete the 'fibCypher' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. CHARACTER option
     *  2. INTEGER num1
     *  3. INTEGER num2
     *  4. CHARACTER key
     *  5. STRING msg
     */
    public static String fibCypher(char option, int num1, int num2, char key, String msg) {
        if(option == 'E'){
            return fibCypherEncode(num1, num2, key, msg);
        } else {
            return fibCypherDecode(num1, num2, key, msg);
        }
    }

    public static String createFibonacci(int num1, int num2){
        BigInteger Big1 = BigInteger.valueOf(num1);
        BigInteger Big2 = BigInteger.valueOf(num2);
        fibonacci = new BigInteger[200];
        fibonacci[0] = Big1;
        fibonacci[1] = Big2;
        for(int i = 2; i < fibonacci.length; i++){
            fibonacci[i] = Big1.add(Big2);
            Big1 = Big2;
            Big2 = fibonacci[i];
        }
        return Arrays.toString(fibonacci);
    }

    private static String fibCypherEncode(int num1, int num2, char key, String msg){
        String sol = "";
        createFibonacci(num1, num2);
        int indexOfKey = -1;
        key = Character.toLowerCase(key);
        for(int i = 0; i < alphabet.length; i++){
            if(alphabet[i] == key){
                indexOfKey = i;
            }
        }
        for(int i = 0; i < msg.length(); i++){
            int offset; 
            if(i%2 == 0){
                offset = (fibonacci[i].mod(new BigInteger("26")).intValue() + indexOfKey)%26;
            } else {
                offset = (indexOfKey - fibonacci[i].mod(new BigInteger("26")).intValue())%26;
                if(offset < 0){
                    offset = 26 + offset;
                }
            }
            int encoded = 3 * ((int) alphabet[offset]) + (int) msg.charAt(i);
            sol += encoded + " ";
        }
        sol = sol.substring(0, sol.length() - 1);
        return sol;
    }

    private static String fibCypherDecode(int num1, int num2, char key, String msg){
        StringTokenizer line = new StringTokenizer(msg, " ");
        int[] seq = new int[line.countTokens()];
        for(int i = 0; i < seq.length; i++){
            seq[i] = Integer.parseInt(line.nextToken());
        }
        String sol = "";
        createFibonacci(num1, num2);
        int indexOfKey = -1;
        key = Character.toLowerCase(key);
        for(int i = 0; i < alphabet.length; i++){
            if(alphabet[i] == key){
                indexOfKey = i;
            }
        }
        for(int i = 0; i < seq.length; i++){
            int offset; 
            if(i%2 == 0){
                offset = (fibonacci[i].mod(new BigInteger("26")).intValue() + indexOfKey)%26;
            } else {
                offset = (indexOfKey - fibonacci[i].mod(new BigInteger("26")).intValue())%26;
                if(offset < 0){
                    offset = 26 + offset;
                }
            }
            char decoded = ((char) (seq[i] - 3*((int) alphabet[offset])));
            sol += decoded;
        }
        return sol;
    }

}

public class FibonacciCypher {
    public static void main(String[] args){
        Result testing = new Result();
        System.out.println(Result.fibCypher('D', 3, 7, 'h', "436 407 456 444 425 439"));
    }
}