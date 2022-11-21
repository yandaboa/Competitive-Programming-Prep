//http://www.usaco.org/index.php?page=viewproblem2&cpid=663

import java.io.*;
import java.util.*;

public class square {
    public static void main(String[] args)throws IOException{
        Kattio in = new Kattio("square");
        int x1 = in.nextInt();
        int y1 = in.nextInt();
        int x2 = in.nextInt();
        int y2 = in.nextInt();
        int bx1 = in.nextInt();
        int by1 = in.nextInt();
        int bx2 = in.nextInt();
        int by2 = in.nextInt();
        int xmax = Math.max(x2, bx2);
        int ymax = Math.max(y2, by2);
        int xmin = Math.min(x1, bx1);
        int ymin = Math.min(y1, by1);
        int sol = Math.max(Math.abs(xmax-xmin), Math.abs(ymax-ymin));
        in.write(sol*sol + "");
        in.close();
    }
}
