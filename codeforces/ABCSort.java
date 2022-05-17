import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ABCSort {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(input.readLine());
        for(int i = 1; i <= t; i++){
            int arrLength = Integer.parseInt(input.readLine());
            int[] arr = new int[arrLength];
            String[] textInputArr = input.readLine().split(" ");
            for(int a = 0; a < arrLength; a++){
                arr[a] = Integer.parseInt(textInputArr[a]);
            }
            for(int j = arrLength - 1; j >= 0; j -= 2){
                try{
                    int right = arr[j];
                    int left = arr[j - 1];
                    if(right < left){
                        arr[j] = left;
                        arr[j-1] = right;
                    }
                } catch (Exception e){
                    break;
                }
            }
            boolean isSorted = true;
            for(int j = 1; j < arr.length; j++){
                if(arr[j] < arr[j - 1]){
                    isSorted = false;
                }
            }
            if(isSorted){
                sb.append("YES\n");
            } else {
                sb.append("NO\n");
            }
        }
        System.out.print(sb);
    }
}