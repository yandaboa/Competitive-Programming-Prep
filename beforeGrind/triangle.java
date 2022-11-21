//http://www.usaco.org/index.php?page=viewproblem2&cpid=1011

import java.util.*;
import java.io.*;

public class triangle {

    public static void main(String[] args)throws IOException{
        Kattio in = new Kattio("triangles");
        int pointsnum = in.nextInt();
		int[] xarr = new int[pointsnum];
		int[] yarr = new int[pointsnum];
        for(int i = 0; i < pointsnum; i++){
			xarr[i] = in.nextInt();
			yarr[i] = in.nextInt();
		}
		int max = 0;
		for(int i = 0; i < pointsnum; i++){
			max = Math.max(max, getxmax(i, xarr, yarr)*getymax(i, xarr, yarr));
		}
		in.write(max + "");
		in.close();
    }

	public static int getxmax(int index, int[] xarr, int[] yarr){
		int dist = 0;
		for(int i = 0; i < xarr.length; i++){
			if(xarr[index] == xarr[i]){
				dist = Math.max(dist, Math.abs(yarr[index] - yarr[i]));
			}
		}
		return dist;
	}

	public static int getymax(int index, int[] xarr, int[] yarr){
		int dist = 0;
		for(int i = 0; i < yarr.length; i++){
			if(yarr[index] == yarr[i]){
				dist = Math.max(dist, Math.abs(xarr[index] - xarr[i]));
			}
		}
		return dist;
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
