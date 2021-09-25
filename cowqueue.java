//solution to http://www.usaco.org/index.php?page=viewproblem2&cpid=713

import java.util.*;
import java.io.*;

public class cowqueue {
    public static void main(String[] args)throws IOException{
        BufferedReader in = new BufferedReader(new FileReader(new File("cowqueue.in")));
        BufferedWriter out = new BufferedWriter(new FileWriter(new File("cowqueue.out")));

        int cownum = Integer.parseInt(in.readLine());
        cow[] cows = new cow[cownum];
        for(int i = 0; i < cownum; i++){
            String[] s = in.readLine().split(" ");
            cows[i] = new cow(Integer.parseInt(s[0]), Integer.parseInt(s[1]));
        }
        Arrays.sort(cows);
        int time = 0;
        for(int i = 0; i < cows.length; i++){
            System.out.println(cows[i]);
            if(time < cows[i].timearr){
                time = cows[i].timearr;
                time += cows[i].timetak;
            } else{
                time += cows[i].timetak;
            }
        }
        out.write(time + "");
        out.close();
    }
}

class cow implements Comparable<cow>{
    public int timearr;
    public int timetak;

    public cow(int timearr, int timetak){
        this.timearr = timearr;
        this.timetak = timetak;
    }

    public int compareTo(cow sd){
        return timearr - sd.timearr;
    }
    public String toString(){
        return timearr + " | " + timetak;
    }
}