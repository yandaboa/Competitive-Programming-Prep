//http://www.usaco.org/index.php?page=viewproblem2&cpid=917

import java.util.*;
import java.io.*;

public class traffic {
    public static void main(String[] args)throws IOException{
        Kattio in = new Kattio("traffic");
        int miles = in.nextInt();
        int endmin = -999999;
        int endmax = 999999;
        mile[] steps = new mile[miles];
        for(int i = 0; i < miles; i++){
            String type = in.next();
            if(type.equals("on")){
                steps[i] = new mile(1, in.nextInt(), in.nextInt());
            } else if(type.equals("off")){
                steps[i] = new mile(-1, in.nextInt(), in.nextInt());
            } else {
                steps[i] = new mile(0, in.nextInt(), in.nextInt());
            }
        }
        for(int i = 0; i < miles; i++){
            if(steps[i].type == 1){
                endmax += steps[i].max;
                endmin += steps[i].min;
            } else if(steps[i].type == -1){
                endmax -= steps[i].min;
                endmin -= steps[i].max;
                endmin = Math.max(0, endmin);
            } else {
                endmax = Math.min(steps[i].max, endmax);
                endmin = Math.max(endmin, steps[i].min);
            }
        }
        int startmin = -999999;
        int startmax = 999999;
        for(int i = miles - 1; i > -1; i--){
            if(steps[i].type == 1){
                startmax -= steps[i].min;
                startmin -= steps[i].max;
                startmin = Math.max(0, startmin);
            } else if(steps[i].type == -1){
                startmin += steps[i].min;
                startmax += steps[i].max;
            } else {
                startmax = Math.min(steps[i].max, startmax);
                startmin = Math.max(startmin, steps[i].min);
            }
        }
        in.write(startmin + " " + startmax + "\n" + endmin + " " + endmax + "");
        in.close();
    }

}

class mile {
    public int min;
    public int max;
    public int type;

    public mile(int type, int min, int max){
        this.type = type;
        this.min = min;
        this.max = max;
    }
}