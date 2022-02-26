import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class NumberSpiral {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(input.readLine());
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < testCases; i++){
            StringTokenizer line = new StringTokenizer(input.readLine());
            long row = Long.parseLong(line.nextToken());
            long col = Long.parseLong(line.nextToken());
            long larger = Math.max(row, col);
            long smaller = Math.max(row, col);
            long corner = larger*larger;
            if(larger%2 == 1){
                long ans = corner - Math.abs(larger - col) - Math.abs(1 - row);
                sb.append(ans + "\n");
            } else {
                long ans = corner - Math.abs(1 - col) - Math.abs(larger - row);
                sb.append(ans + "\n");
            }
        }
        System.out.println(sb);
    }
}
