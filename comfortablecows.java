#inefficient solution to http://usaco.org/index.php?page=viewproblem2&cpid=1108

import java.util.*;
import java.io.*;

public class comfortablecows {
    public static void main(String[] args)throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cownum = Integer.parseInt(in.readLine());
        HashMap<Integer, ArrayList<Integer>> byx = new HashMap<Integer, ArrayList<Integer>>();
        HashMap<Integer, ArrayList<Integer>> byy = new HashMap<Integer, ArrayList<Integer>>();
        ArrayList<point> cows = new ArrayList<point>();
        int[] ans = new int[cownum];
        for(int i = 0; i < cownum; i++){
            String a = in.readLine();
            point b = new point(Integer.parseInt(a.split(" ")[0]), Integer.parseInt(a.split(" ")[1]));
            cows.add(b);
            if(byx.containsKey(b.x)){
                byx.get(b.x).add(b.y);
            } else{
                byx.put(b.x, new ArrayList<Integer>());
                byx.get(b.x).add(b.y);
            }
            if(byy.containsKey(b.y)){
                byy.get(b.y).add(b.x);
            } else{
                byy.put(b.y, new ArrayList<Integer>());
                byy.get(b.y).add(b.x);
            }
            ans[i] = comfort(cows, byx, byy);
        }
        for(int i = 0; i < ans.length; i++){
            System.out.println(ans[i]);
        }
    }

    public static int comfort(ArrayList<point> cows, HashMap<Integer, ArrayList<Integer>> byx, HashMap<Integer, ArrayList<Integer>> byy){
        int comfnum = 0;
        for (int i = 0; i < cows.size(); i++){
            int x = cows.get(i).x;
            int y = cows.get(i).y;
            int adj = 0;
            if(byx.get(x).contains(y+1)){
                adj++;
            }
            if(byx.get(x).contains(y-1)){
                adj++;
            }
            if(byy.get(y).contains(x+1)){
                adj++;
            }
            if(byy.get(y).contains(x-1)){
                adj++;
            }
            if (adj == 3){
                comfnum++;
            }
        }
        return comfnum;
    }
}

class point{
    public int x;
    public int y;

    public point(int x, int y){
        this.x = x;
        this.y = y;
    }
    public String toString(){
        return "(" + x + ", " + y + ")";
    }
}
