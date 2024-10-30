class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, maxOnes = 0, zeroCount = 0;
        
        for (int right = 0; right < nums.size(); right++){
            if (nums[right] == 0) {
                zeroCount++;
            }
            
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            maxOnes = max(maxOnes, right - left + 1);
        }
        
        return maxOnes;
    }
};