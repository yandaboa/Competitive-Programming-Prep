//solution to http://www.usaco.org/index.php?page=viewproblem2&cpid=616

import java.util.*;
import java.io.*;

public class cbarn {
    public static void main(String[] args)throws IOException{
        BufferedReader in = new BufferedReader(new FileReader(new File("cbarn.in")));
        BufferedWriter out = new BufferedWriter(new FileWriter(new File("cbarn.out")));
        int rooms = Integer.parseInt(in.readLine());
        int[] roomspec = new int[rooms];
        for(int i = 0; i < rooms; i++){
            roomspec[i] = Integer.parseInt(in.readLine());
        }
        int total = Integer.MAX_VALUE;
        for(int i = 0; i < rooms; i++){
            int counter = 0;
            int multiple = 0;
            for(int j = i; j < rooms; j++){
                counter += roomspec[j]*multiple;
                multiple++;
            }
            for(int j = 0; j < i; j++){
                counter += roomspec[j]*multiple;
                multiple++;
            }
            total = Math.min(total, counter);
        }
        out.write(total + "");
        out.close();
    }
}
