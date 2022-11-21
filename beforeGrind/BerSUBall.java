import java.util.*;
import java.io.*;

;public class BerSUBall {
    public static void main(String[] args)throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int numOfBoys = Integer.parseInt(input.readLine());
        StringTokenizer boySkill = new StringTokenizer(input.readLine());
        int[] boySkillArr = new int[numOfBoys];
        for(int i = 0; i < numOfBoys; i++){
            boySkillArr[i] = Integer.parseInt(boySkill.nextToken()) - 1;
        }
        int numOfGirls = Integer.parseInt(input.readLine());
        int[] girlSkillArr = new int[numOfGirls];
        StringTokenizer girlSkill = new StringTokenizer(input.readLine());
        for(int i = 0; i < numOfGirls; i++){
            girlSkillArr[i] = Integer.parseInt(girlSkill.nextToken()) - 1;
        }
        Arrays.sort(boySkillArr);
        Arrays.sort(girlSkillArr);

        HashMap<Integer, Integer> boys = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> girls = new HashMap<Integer, Integer>();
        
        /*for(int i = 0; i < boys.length; i++){
            boys[i] = false;
        }*/
        for(int i = 0; i < boySkillArr.length; i++){
            if(boys.containsKey(boySkillArr[i])){
                boys.put(boySkillArr[i], boys.get(boySkillArr[i]) + 1);
            } else {
                boys.put(boySkillArr[i], 1);
            }
        }
        /*
        for(int i = 0; i < girls.length; i++){
            girls[i] = false;
        }
        */
        for(int i = 0; i < girlSkillArr.length; i++){
            if(girls.containsKey(girlSkillArr[i])){
                girls.put(girlSkillArr[i], girls.get(girlSkillArr[i]) + 1);
            } else {
                girls.put(girlSkillArr[i], 1);
            }
        }

        int validPairsCount = 0;
        if(numOfBoys > numOfGirls){
            validPairsCount = countPairs(girlSkillArr, boys);
        } else {
            validPairsCount = countPairs(boySkillArr, girls);
        }
        System.out.println(validPairsCount);
    }

    private static int countPairs(int[] genderSkill, HashMap<Integer, Integer> oppositeGenderBool){
        int result = 0;
        for(int i = 0; i < genderSkill.length; i++){
            if((oppositeGenderBool.get(genderSkill[i] - 1) != null && oppositeGenderBool.get(genderSkill[i] - 1) > 0)){
                result++;
                oppositeGenderBool.put(genderSkill[i] - 1, oppositeGenderBool.get(genderSkill[i] - 1) - 1);
            } else if(oppositeGenderBool.get(genderSkill[i]) != null && oppositeGenderBool.get(genderSkill[i]) > 0){
                result++;
                oppositeGenderBool.put(genderSkill[i], oppositeGenderBool.get(genderSkill[i]) - 1);
            } else if((oppositeGenderBool.get(genderSkill[i] + 1) != null && oppositeGenderBool.get(genderSkill[i] + 1) > 0)){
                result++;
                oppositeGenderBool.put(genderSkill[i] + 1, oppositeGenderBool.get(genderSkill[i] + 1) - 1);
            }    
        }
        return result;
    }
}
