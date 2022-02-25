import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.concurrent.atomic.LongAdder;

public class WeirdAlgorithm {
    public static void main(String[] args)throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        long n = Integer.parseInt(input.readLine());
        System.out.print(n + " ");
        while(n != 1){
            if(n%2 == 0){
                n /= 2;
                System.out.print(n + " ");
            } else {
                n = 3*n + 1;
                System.out.print(n + " ");
            }
        }
    }
}