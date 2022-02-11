import java.util.*;

public class nines {
    public static void main(String[] args){
        int count = 0;
        HashSet<Integer> nines = new HashSet<Integer>(9999);
        for(int i = 1;i < 99; i++){
            if(i%3 == 0){
                i /= 3;
            }
            if(i%3 == 0){
                i /= 3;
            }
            if(i%11 == 0){
                i /= 11;
            }
            if(i%101 == 0){
                i /= 101;
            }
            if(!nines.contains(i)){
                nines.add(i);
                count++;
            }
        }
        System.out.println(count);
        System.out.println("done");

    }
}
