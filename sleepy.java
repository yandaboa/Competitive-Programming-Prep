//solution to http://www.usaco.org/index.php?page=viewproblem2&cpid=892

import java.util.*;
import java.io.*;

public class sleepy {
    public static void main(String[] args)throws IOException{
        Kattio in = new Kattio("sleepy");
        int length = in.nextInt();
        int[] arr = new int[length];
        for(int i = 0; i < length; i++){
            arr[i] = in.nextInt();
        }
        int ans = length - 1;
        for(int i = length - 2; i >= 0; i--){
            if(arr[i] < arr[i+1]){
                ans = i;
            } else{
                break;
            }
        }
        in.write(ans + "");
        in.close();
    }
}