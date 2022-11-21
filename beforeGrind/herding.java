//http://www.usaco.org/index.php?page=viewproblem2&cpid=915
import java.util.*;
import java.io.*;

public class herding {
    public static void main(String[] args)throws IOException{
        Kattio in = new Kattio("herding");
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        if(a > b){
            int temp = a;
            a = b;
            b = temp;
        }
        if(b > c){
            int temp = b;
            b = c;
            c = temp;
        }
        if(a > b){
            int temp = a;
            a = b;
            b = temp;
        }
        if(c == a+2){
            in.write(0+"\n");
        } else if(c == b + 2 || b == a+2){
            in.write(1 + "\n");
        } else {
            in.write(2 + "\n");
        }
        in.write(Math.max(b - a, c - b)-1 + "");
        in.close();
    }
}
