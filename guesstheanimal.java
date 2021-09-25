//solution to http://www.usaco.org/index.php?page=viewproblem2&cpid=893

import java.util.*;
import java.io.*;

public class guesstheanimal {
	static List<String>[] characteristics;

	static int numCommon (int i, int j) {
		int count = 0;
		List<String> one = characteristics[i];
		List<String> two = characteristics[j];

		for (int x = 0; x < one.size(); x++) {
			for (int y = 0; y < two.size(); y++) {
				if (one.get(x).equals(two.get(y))) { // if the same characteristic, add to count
					count++;
				}
			}
		}
		return count;
	}

	public static void main (String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(new File("guess.in")));
        BufferedWriter out = new BufferedWriter(new FileWriter(new File("guess.out")));
		int n = Integer.parseInt(in.readLine());

		characteristics = new List[n];
		for (int x = 0; x < characteristics.length; x++) { // initialize lists
			characteristics[x] = new ArrayList<>();
		}

		for (int i = 0; i < n; i++) { // read input
			String[] s = in.readLine().split(" ");
			int k = Integer.parseInt(s[1]);

			for (int x = 2; x < k + 2; x++) {
				String adjective = s[x];
				characteristics[i].add(adjective); // add to the array of lists
			}
		}

		int largest = 0;
		for (int i = 0; i < n; i++) { // loop through the combinations
			for (int j = i + 1; j < n; j++) {
				largest = Math.max(largest, numCommon(i, j)); // keep track of the largest
			}
		}

        largest++;
		out.write(largest + "");
        out.close();
	}
}