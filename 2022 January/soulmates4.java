import java.util.*;
import java.io.*;

public class soulmates4{
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int numOfPairs = Integer.parseInt(input.readLine());
        long slave = 0;
        long master = 0;
        for(int i = 0; i < numOfPairs; i++){
            StringTokenizer line = new StringTokenizer(input.readLine(), " ");
            slave = Long.parseLong(line.nextToken());
            master = Long.parseLong(line.nextToken());
            long ans = Long.MAX_VALUE;
            for (int removed = 0; master >> removed > 0; removed++) {
                long here = 0;
                long prefix = master >> removed;
                long cow = slave;
                while (cow > prefix) {
                    if (cow % 2L == 1L) {
                        cow++;
                        here++;
                    }
                    cow /= 2L;
                    here++;
                }
                here += prefix - cow;
                here += removed;
                here += Long.bitCount(master & ((1L << removed) - 1L));
                ans = Math.min(ans, here);
            }
            out.append(ans).append('\n');
        }
        System.out.print(out);
        
    }
    
}