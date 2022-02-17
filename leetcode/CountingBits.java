class Solution {
    public int[] countBits(int n) {
        int[] ans = new int[n + 1];
        for(int i = 0; i < ans.length; i++){
            int temp = i;
            int count = 0;
            while(i > 0){
                temp = i&(i-1);
                count++;
            }
            ans[i] = count;
        }
        return ans;
    }
}