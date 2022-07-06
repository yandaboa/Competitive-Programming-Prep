import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class taxi {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int groups = Integer.parseInt(input.readLine());
        StringTokenizer next = new StringTokenizer(input.readLine());
        int[] oneToFour = new int[4];
        for(int i = 0; i < groups; i++){
            oneToFour[Integer.parseInt(next.nextToken()) - 1]++;
        }
        int sol = 0;
        //the fours
        sol += oneToFour[3];

        //1 + 3
        sol += oneToFour[2];
        oneToFour[0] = Math.max(0, oneToFour[0] - oneToFour[2]);
        sol += (oneToFour[0] + oneToFour[1]*2)/4;
        sol += Math.min(1, (oneToFour[0] + oneToFour[1]*2)%4);

        System.out.println(sol);
    }
}
