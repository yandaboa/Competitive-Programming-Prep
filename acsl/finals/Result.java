import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'findMatch' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. STRING word
     *  2. STRING guesses
     */

    public static String findMatch(String word, String guesses) {
        String returnStatement = "";

        String[] guessArr = guesses.split(" ");
        WordAttributes[] wordAttributesArr = new WordAttributes[guessArr.length];
        ArrayList<WordAttributes>[] byGreens = new ArrayList[7];
        for(int i = 0; i < 7; i++){
            byGreens[i] = new ArrayList<WordAttributes>();
        }
        for(int i = 0; i < guessArr.length; i++){
            wordAttributesArr[i] = new WordAttributes(guessArr[i], word);
            byGreens[wordAttributesArr[i].greens].add(wordAttributesArr[i]);
            System.out.println(wordAttributesArr[i]);
        }
        int numberOfMatching = 0;
        for(int i = 0; i < wordAttributesArr.length; i++){
            if(wordAttributesArr[i].greens > 0 || wordAttributesArr[i].yellows > 0){
                numberOfMatching++;
            }
        }
        for(int i =6; i > -1; i--){
            Collections.sort(byGreens[i], WordAttributes.CompareByYellows);
            ArrayList<WordAttributes> dups = new ArrayList<WordAttributes>();
            if(byGreens[i].size() >= 1){
                dups.add(byGreens[i].get(0));
                for(int j = 1; j < byGreens[i].size(); j++){
                    if(byGreens[i].get(j).yellows != dups.get(dups.size() - 1).yellows){
                        returnStatement += seperateDupYellows(dups);
                        dups = new ArrayList<WordAttributes>();
                        dups.add(byGreens[i].get(j));
                    } else {
                        dups.add(byGreens[i].get(j));
                    }
                }
                returnStatement += seperateDupYellows(dups);
            }
        }
        System.out.println(returnStatement);
        String firstSix = "";
        String[] omg = returnStatement.split(" ");
        for(int i = 0; i < 6 && i < omg.length; i++){
            firstSix += omg[i] + " ";
        }
        System.out.println(firstSix);
        if(numberOfMatching < 6){
            String alph = "abcdefghijklmnopqrstuvwxyz";
            firstSix = "";
            for(int i = 0; i < alph.length(); i++){
                if(!guesses.contains(alph.charAt(i) + "")){
                    firstSix += alph.charAt(i);
                }
            }
        }
        return firstSix;
    }

    private static String seperateDupYellows(ArrayList<WordAttributes> dupYellows){
            if(dupYellows.size() == 0){
                return "";
            }
            if(dupYellows.size() == 1){
                return dupYellows.get(0).guess + " ";
            }
            ArrayList<WordAttributes> firstAndLast = new ArrayList<WordAttributes>();
            ArrayList<WordAttributes> first = new ArrayList<WordAttributes>();
            ArrayList<WordAttributes> last = new ArrayList<WordAttributes>();
            ArrayList<WordAttributes> neither = new ArrayList<WordAttributes>();

            for(int j = 0; j < dupYellows.size(); j++){
                if(dupYellows.get(j).firstGreen && dupYellows.get(j).lastGreen){
                    firstAndLast.add(dupYellows.get(j));
                } else if(dupYellows.get(j).firstGreen){
                    first.add(dupYellows.get(j));
                } else if (dupYellows.get(j).lastGreen){
                    last.add(dupYellows.get(j));
                } else {
                    neither.add(dupYellows.get(j));
                }
            }
            Collections.sort(firstAndLast, WordAttributes.CompareByVowels);
            Collections.sort(first, WordAttributes.CompareByVowels);
            Collections.sort(last, WordAttributes.CompareByVowels);
            Collections.sort(neither, WordAttributes.CompareByVowels);
            String returned = "";
            for(int i = 0; i < firstAndLast.size(); i++){
                returned += firstAndLast.get(i).guess + " ";
            }
            for(int i = 0; i < first.size(); i++){
                returned += first.get(i).guess + " ";
            }
            for(int i = 0; i < last.size(); i++){
                returned += last.get(i).guess + " ";
            }
            for(int i = 0; i < neither.size(); i++){
                returned += neither.get(i).guess + " ";
            }
            System.out.println(firstAndLast + " NEXT " + first + " NEXT " + last + " NEXT " + neither);
            return returned;        
    }
}

class WordAttributes {
    public int greens;
    public int yellows;

    public boolean firstGreen;
    public boolean lastGreen;
    public int numVowelGreen;
    public String rep;

    public String guess;
    public WordAttributes(String guess, String target){
        greens=0;
        yellows = 0;
        firstGreen = false;
        lastGreen = false;
        numVowelGreen = 0;
        this.guess = guess;
        if(guess.charAt(0) == target.charAt(0)){
            firstGreen = true;
        }
        if(guess.charAt(guess.length() - 1) == target.charAt(target.length() -1)){
            lastGreen = true;
        }
        ArrayList<Integer> greened = new ArrayList<Integer>();
        for(int i = 0; i < guess.length(); i++){
            if(guess.charAt(i) == target.charAt(i)){
                greened.add(i);
                target = target.substring(0, i) + "G" + target.substring(i + 1, target.length());
                greens++;
                if("aeiou".contains(guess.charAt(i)+ "")){
                    numVowelGreen++;
                }
            }
        }
        
        for(int i = 0; i < guess.length(); i++){
            if(target.contains(guess.charAt(i) + "") && !greened.contains(i)){
                System.out.println(target + " " + guess.charAt(i));
                yellows++;
                target = target.substring(0, target.indexOf(guess.charAt(i))) + "Y" + target.substring(target.indexOf(guess.charAt(i)) + 1, target.length());
            }
        }

        System.out.println(target);
    }
    public static Comparator<WordAttributes> CompareByYellows = new Comparator<WordAttributes>() {

        public int compare(WordAttributes s1, WordAttributes s2) {
           return s2.yellows - s1.yellows;
        }};
    
    public static Comparator<WordAttributes> CompareByVowels = new Comparator<WordAttributes>() {

        public int compare(WordAttributes s1, WordAttributes s2) {
           int temp = s2.numVowelGreen - s1.numVowelGreen;
           if(temp == 0){
               return -1*s2.guess.compareToIgnoreCase(s1.guess);
           }
           return temp;
    }};

    public String toString(){
        return greens + " | " + yellows + " | " + firstGreen + " | " + lastGreen + " | " + numVowelGreen + " WORD: " + guess;
    }
}