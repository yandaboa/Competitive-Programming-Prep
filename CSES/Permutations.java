import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Permutations {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(input.readLine());
        if(n <= 3 && n != 1){
            System.out.println("NO SOLUTION");
        } else {
            StringBuilder sb = new StringBuilder();
            for(long i = 2; i <= n; i += 2){
                sb.append(i + " ");
            }
            for(long i = 1; i <= n; i += 2){
                sb.append(i + " ");
            }
            System.out.print(sb);
        }
    }
}