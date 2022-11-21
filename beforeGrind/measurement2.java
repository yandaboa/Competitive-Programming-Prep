import java.util.*;
import java.io.*;

public class measurement2{
    static Map<Integer, Integer> ids = new HashMap<>();
    static int n, start, A;
    static note[] notes;
    static TreeMap<Integer, Integer> values = new TreeMap<>((o1, o2) -> o2-o1);
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("measurement.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("measurement.out")));
		// read in all of the notes
		n = Integer.parseInt(br.readLine().split(" ")[0]);
        start = Integer.parseInt(br.readLine().split(" ")[1]);
		notes = new note[n];
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
            int d = Integer.parseInt(st.nextToken());
            int id = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
			notes[i] = new note(d, id, c);
            ids.put(id, 0);
        }

        Arrays.sort(notes, Comparator.comparingInt(o -> o.d));
		values.put(0, n+1);

        for (int i = 0; i < n; i++) {
			int change = ids.get(notes[i].id);
			boolean wasTop = change == values.firstKey();
			int prevCnt = values.get(change);
			values.put(change, values.get(change)-1);
			if (values.get(change) == 0) values.remove(change);

			change += notes[i].change;
			ids.put(notes[i].id, change);
			values.put(change, values.getOrDefault(change, 0)+1);

			boolean isTop = change == values.firstKey();
			int curCnt = values.get(change);

			if(wasTop){
				if(isTop && curCnt == prevCnt && curCnt == 1){
					continue;
				}
				//If it was the highest and now its not or there are now multiple highest cows, we need to increment answer
				A++;
			}
			else if(isTop){
				//If it wasn't at the highest but now it is, then we need to increment answer
				A++;
			}
		}
    }
}

class note implements Comparator<note>{
    public int day;
    public int id;
    public int change;

    public note(int day, int id, int change){
        this.day = day;
        this.id = id;
        this.change = change;
    }

    @Override
    public int compare(note o1, note o2) {
        if(o1.day < o2.day){
            return -1;
        } else {
            return 1;
        }
    }
}

class cow2{
    public int id;
    public int milk;
    
    public cow(int id, int milk){

    }
}