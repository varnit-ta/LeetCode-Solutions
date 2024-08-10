class Solution {
public:
    int maxArea(vector<int>& height) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(0);

        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int m = min(height[left], height[right]);
            maxArea = max((right - left) * m, maxArea);

            height[left] < height[right] ? left++ : right--;
        }

        return maxArea;
    }
};