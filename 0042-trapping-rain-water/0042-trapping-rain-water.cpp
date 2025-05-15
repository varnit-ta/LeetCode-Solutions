class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> water(n, 0);
        int totalWater = 0;

        int leftMax = 0;
        for (int i = 0; i < n; ++i) {
            if (height[i] >= leftMax) {
                leftMax = height[i];
                water[i] = -1;
            } else {
                water[i] = leftMax - height[i];
            }
        }

        int rightMax = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (height[i] >= rightMax) {
                rightMax = height[i];
                water[i] = -1;
            } else {
                if (water[i] != -1) {
                    water[i] = min(water[i], rightMax - height[i]);
                }
            }

            if (water[i] != -1) {
                totalWater += water[i];
            }
        }

        return totalWater;
    }
};
