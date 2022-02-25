import java.util.Arrays;
import java.util.Comparator;

public class tryingStuffOut {
    public static void main(String[] args){
        Integer[] arr = {-1, 2, 4, 66, 73, 78, -444, 34, 52, -66};
        Arrays.sort(arr, new SortByAbs());
        System.out.println(Arrays.toString(arr));
    }
}

class SortByAbs implements Comparator<Integer>{
    @Override
    public int compare(Integer a, Integer b){
        return Math.abs(a) - Math.abs(b);
    }
}