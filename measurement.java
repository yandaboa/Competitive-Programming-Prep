import java.io.*;
import java.util.*;
public class measurement {
	public static void main(String[] args) throws IOException {
		// initialize file I/O
		BufferedReader br = new BufferedReader(new FileReader("measurement.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("measurement.out")));
		
		int n = Integer.parseInt(br.readLine());
		int[] day = new int[n];
		String[] cow = new String[n];
		int[] change = new int[n];
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			day[i] = Integer.parseInt(st.nextToken());
			cow[i] = st.nextToken();
			change[i] = Integer.parseInt(st.nextToken());
		}
		
		int bessieMilk = 7, elsieMilk = 7, mildredMilk = 7;
		boolean bessieOn = true, elsieOn = true, mildredOn = true;
		int dayAdjust = 0;
		
		for(int currDay = 1; currDay <= 100; currDay++) {
			for(int i = 0; i < n; i++) {
				if(day[i] == currDay) {
					if(cow[i].equals("Bessie")) {
						bessieMilk += change[i];
					}
					if(cow[i].equals("Elsie")) {
						elsieMilk += change[i];
					}
					if(cow[i].equals("Mildred")) {
						mildredMilk += change[i];
					}
				}
			}
			int highestMilk = Math.max(bessieMilk, Math.max(elsieMilk, mildredMilk));
			boolean bessieOnNext = bessieMilk == highestMilk;
			boolean elsieOnNext = elsieMilk == highestMilk;
			boolean mildredOnNext = mildredMilk == highestMilk;
			if(bessieOn != bessieOnNext || elsieOn != elsieOnNext || mildredOn != mildredOnNext) {
				dayAdjust++;
			}
			bessieOn = bessieOnNext;
			elsieOn = elsieOnNext;
			mildredOn = mildredOnNext;
		}

		// print the answer
		pw.println(dayAdjust);
		pw.close();
	}

}
