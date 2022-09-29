import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SameParitySummands {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int cases = Integer.parseInt(input.readLine());
        for(int i = 0; i < cases; i++){
            StringTokenizer st = new StringTokenizer(input.readLine(), " ");
            int sum = Integer.parseInt(st.nextToken());
            int num = Integer.parseInt(st.nextToken());
            if(sum < num){
                sb.append("NO\n");
            } else {
                int rem = sum % num;
                if(rem % 2 == 0) {
                    sb.append("YES\n");
                    sb.append(sum/num + sum%num);
                    for(int j = 1; j < num; j++){
                        sb.append(" " + sum/num);
                    }
                    sb.append("\n");
                } else if ((num + rem) %2 == 0 && (num + rem) != sum){
                    sb.append("YES\n");
                    sb.append(sum/num - 1 + sum%num + num);
                    for(int j = 1; j < num; j++){
                        sb.append(" " + (sum/num - 1));
                    }
                    sb.append("\n");
                } else {
                    sb.append("NO\n");
                }
            }
        }
        System.out.println(sb);
    }
}
