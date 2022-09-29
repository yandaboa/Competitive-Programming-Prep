class Solution {
public:
    int maxArea(vector<int>& height) {
        long long largest = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left != right){
            largest = std.max(height.at(left)*height.at(right)*(right - left), largest);
            if(height[left] > height[right]){
                right--;
            } else {
                left++;
            }
        }
        return largest;
    }
};