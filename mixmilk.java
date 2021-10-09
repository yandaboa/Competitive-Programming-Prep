//solution to http://www.usaco.org/index.php?page=viewproblem2&cpid=855

import java.util.*;
import java.io.*;

public class mixmilk{
    public static void main(String[] args)throws IOException{
        Kattio in = new Kattio("mixmilk");
        bucket a = new bucket(in.nextInt(), in.nextInt());
        bucket b = new bucket(in.nextInt(), in.nextInt());
        bucket c = new bucket(in.nextInt(), in.nextInt());
        for(int i = 0; i < 33; i++){
            b.pour(a);
            c.pour(b);
            a.pour(c);
        }

        b.pour(a);
        in.write(a.currentMilk + "\n" + b.currentMilk + "\n" + c.currentMilk);
        in.close();
    } 
}

class bucket{
    public int size;
    public int currentMilk;
    
    public bucket(int size, int currentMilk){
        this.size = size;
        this.currentMilk = currentMilk;
    }

    public void setMilk(int a){
        this.currentMilk = a;
    }

    // pours a into this bucket
    public void pour(bucket a){
        if(this.size < a.currentMilk + this.currentMilk){
            int temp = this.currentMilk;
            this.currentMilk = this.size;
            a.setMilk(Math.abs(this.size - temp - a.currentMilk));
        } else{
            this.currentMilk = this.currentMilk + a.currentMilk;
            a.currentMilk = 0;
        }
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