import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Diploma {
    public static void main(String[] args)throws IOException{
        BufferedReader BR = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk = new StringTokenizer(BR.readLine());
        long pages = Long.parseLong(tk.nextToken());

        long[] arr = new long[5];
        long[] canBeSplit = {16, 8, 4, 2, 1};
        for(int i = 0; i < 5; i++){
            StringTokenizer tk2 = new StringTokenizer(BR.readLine());
            arr[i] = Long.parseLong(tk2.nextToken());
        }
        Long[] cost = new Long[5];
        for(int i = 0; i < 5; i++){
            cost[i] =  (Long) Math.floor(pages/canBeSplit[i])*arr[i];
            if(pages%canBeSplit[i] != 0){
                cost[i] += arr[i];
            }
        }
        Arrays.sort(cost);
        
        System.out.println(Math.round(cost[0]));

    }
}
