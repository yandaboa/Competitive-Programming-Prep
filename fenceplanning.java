//http://www.usaco.org/index.php?page=viewproblem2&cpid=944

import java.util.*;
import java.io.*;

public class fenceplanning {
	static Cow[] cows;
	static List<Integer>[] graph;
	static boolean[] visited;
	static int lowX = Integer.MAX_VALUE;
	static int highX = Integer.MIN_VALUE;
	static int lowY = Integer.MAX_VALUE;
	static int highY = Integer.MIN_VALUE;

	static class Cow {
		int x;
		int y;
	}

	static void floodfill (int currentCow) {
		visited[currentCow] = true;
		Cow cow = cows[currentCow];

		lowX = Integer.min(lowX, cow.x);
		highX = Integer.max(highX, cow.x);
		lowY = Integer.min(lowY, cow.y);
		highY = Integer.max(highY, cow.y);

		for (int connectedCow : graph[currentCow]) {
			if (!visited[connectedCow]) {
				floodfill(connectedCow);
			}
		}
	}

	public static void main (String[] args) throws IOException {
		Kattio io = new Kattio("fenceplan");

		int n = io.nextInt();
		int m = io.nextInt();
		visited = new boolean[n + 1];
		cows = new Cow[n + 1];

		for (int x = 1; x <= n; x++) {
			Cow cow = new Cow();
			cow.x = io.nextInt();
			cow.y = io.nextInt();
			cows[x] = cow;
		}

		graph = new ArrayList[n + 1];
		for (int x = 0; x < graph.length; x++) {
			graph[x] = new ArrayList<>();
		}

		for (int x = 0; x < m; x++) {
			int a = io.nextInt();
			int b = io.nextInt();
			graph[a].add(b);
			graph[b].add(a);
		}

		int lowestPerimeter = Integer.MAX_VALUE;
		for (int cow = 1; cow <= n; cow++) { 
			if (!visited[cow]) {
				floodfill(cow);

				int perimeter = ((highX - lowX) + (highY - lowY)) * 2; 
				lowestPerimeter = Math.min(lowestPerimeter, perimeter); 

				lowX = Integer.MAX_VALUE; 
				highX = Integer.MIN_VALUE;
				lowY = Integer.MAX_VALUE;
				highY = Integer.MIN_VALUE;
			}
		}
		io.println(lowestPerimeter);
		io.close();
	}
	static class Kattio extends PrintWriter {
		private BufferedReader r;
		private StringTokenizer st;
	
		public Kattio() { this(System.in, System.out); }
		public Kattio(InputStream i, OutputStream o) {
			super(o);
			r = new BufferedReader(new InputStreamReader(i));
		}

		public Kattio(String problemName) throws IOException {
			super(new FileWriter(problemName + ".out"));
			r = new BufferedReader(new FileReader(problemName + ".in"));
		}
	
		public String next() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(r.readLine());
				return st.nextToken();
			} catch (Exception e) { }
			return null;
		}
	
		public int nextInt() { return Integer.parseInt(next()); }
		public double nextDouble() { return Double.parseDouble(next()); }
		public long nextLong() { return Long.parseLong(next()); }
	}
}