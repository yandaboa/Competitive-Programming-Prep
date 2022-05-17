import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class TwoKnights {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int max = Integer.parseInt(input.readLine());
        System.out.println(0);
        StringBuilder sb = new StringBuilder();
        long subCounter = 0;
        long subCounter2 = 8;
        for(long i = 2; i <= max; i++){
            sb.append(XPickTwo(i*i) - subCounter + "\n");
            subCounter += subCounter2;
            subCounter2 += 8;
        }
        System.out.println(sb);
    }

    private static long XPickTwo(long area){
        return (area*(area - 1))/2;
    }
}
