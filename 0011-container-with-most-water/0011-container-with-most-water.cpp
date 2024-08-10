class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int m = min(height[left], height[right]);
            maxArea = max((right - left) * m, maxArea);

            if (height[left] > height[right]){
                right--;
            }else{
                left++;
            }
        }

        return maxArea;
    }
};