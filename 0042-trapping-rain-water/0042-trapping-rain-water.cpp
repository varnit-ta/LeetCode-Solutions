class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];

        int total = 0;

        while (left < right) {
            if (leftMax <= rightMax) {
                ++left;
                if (height[left] < leftMax) {
                    total += leftMax - height[left];
                } else {
                    leftMax = height[left];
                }
            } else {
                --right;
                if (height[right] < rightMax) {
                    total += rightMax - height[right];
                } else {
                    rightMax = height[right];
                }
            }
        }

        return total;
    }
};