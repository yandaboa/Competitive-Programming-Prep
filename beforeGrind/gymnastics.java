import java.util.*;
import java.io.*;

public class gymnastics {
    /*
    public static void main(String[] args)throws IOException{
        Kattio in = new Kattio("gymnastics");
        int sessions = in.nextInt();
        int cownum = in.nextInt();
        coworder[] cows = new coworder[cownum + 1];
        for(int i = 0; i < cows.length; i++){
            cows[i] = new coworder(i);
        }
        for(int i = 0; i < sessions; i++){
            for(int j = 0; j < cownum; j++){
                cows[in.nextInt()].positions.add(j);
            }
        }
        for(coworder a : cows){
            a.initbounds();
            System.out.println(a);
        }
        int perm = 0;
        for(int i = 1; i < cows.length; i++){
            for(int j = 1; j < cows.length; j++){
                if(cows[i].biggest <= cows[j].smallest && i != j){
                    perm++;
                    System.out.println(cows[i] + "      |      " + cows[j]);
                }
            }
        }
        in.write(perm + "");
        in.close();
    }
}

class coworder {
    public int smallest;
    public int biggest;
    public ArrayList<Integer> positions = new ArrayList<Integer>();
    public int index;

    public coworder(int index){
        this.index = index;
    }

    public String toString(){
        return index + ": " + positions + " " + smallest + " | " + biggest;
    }

    public void initbounds(){
        smallest = 100;
        biggest = -100;
        for(int i : positions){
            smallest = Math.min(smallest, i);
            biggest = Math.max(biggest, i);
        }
    }
}
*/
    public static void main(String[] args){
        ;
    }
}


class Kattio extends PrintWriter {
	private BufferedReader r;
	private StringTokenizer st;
	// standard input
	public Kattio() { this(System.in,System.out); }
	public Kattio(InputStream i, OutputStream o) {
		super(o);
		r = new BufferedReader(new InputStreamReader(i));
	}
	// USACO-style file input
	public Kattio(String problemName) throws IOException {
		super(new FileWriter(problemName+".out"));
		r = new BufferedReader(new FileReader(problemName+".in"));
	}
	// returns null if no more input
	public String next() {
		try {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(r.readLine());
			return st.nextToken();
		} catch (Exception e) {}
		return null;
	}
	public int nextInt() { return Integer.parseInt(next()); }
	public double nextDouble() { return Double.parseDouble(next()); }
	public long nextLong() { return Long.parseLong(next()); }
}