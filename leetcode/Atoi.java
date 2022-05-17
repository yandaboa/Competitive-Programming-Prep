public class Atoi {
    public static void main(String[] args){
        
    }

    public int myAtoi(String s) {
        double bound = Math.pow(2, 31) - 1;

        int index = 0;
        while(index < s.length() && s.charAt(index) != ' '){
            index++;
        }
        boolean isNeg = false;
        int sol = 0;
        if(s.charAt(index) == '-'){
            isNeg = true;
            index++;
        } else if(s.charAt(index) == '+'){
            index++;
        }
        while(index < s.length()){
            try{
                int curr = Integer.parseInt(String.valueOf(s.charAt(index)));
                sol *= 10;
                sol += curr;
                if(sol >= bound){
                    sol = (int) bound;
                }
            } catch (Exception e){
                break;
            }
        }
        return sol;
    }
}