import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class KnotDivisibleByN {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(input.readLine());
        String sol = "";
        for(int i = 0; i < testCases; i++){
            StringTokenizer line = new StringTokenizer(input.readLine());
            int a = Integer.parseInt(line.nextToken());
            int b = Integer.parseInt(line.nextToken());
            if(a>b){
                sol += b + "\n";
            } else {
                int multipleBy = b/(a - 1);
                int remainder = b%(a - 1);
                if(remainder == 0){
                    sol += multipleBy*a - 1 + "\n";
                }else {
                    sol += (multipleBy*a + remainder) + "\n";
                }
            }

        }
        System.out.println(sol);
    }
}