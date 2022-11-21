//http://www.usaco.org/index.php?page=viewproblem2&cpid=639

import java.io.*;
import java.util.*;

public class diamond {
    public static void main(String[] args)throws IOException{
        Kattio in = new Kattio("diamond");
        int size = in.nextInt();
        int k = in.nextInt();
        ArrayList<Integer> jewels = new ArrayList<Integer>();
        for(int i = 0; i < size; i++){
            jewels.add(in.nextInt());
        }
        Collections.sort(jewels);
        int sol = 0;
        for(int i = 0; i < size; i++){
            int min = jewels.get(i);
            int temp = 0;
            for(int j = i; j < size; j++){
                if(jewels.get(j) <= min + k){
                    temp++;
                }else{
                    break;
                }
            }
            sol = Math.max(sol, temp);
        }
        in.write(sol + "");
        in.close();

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