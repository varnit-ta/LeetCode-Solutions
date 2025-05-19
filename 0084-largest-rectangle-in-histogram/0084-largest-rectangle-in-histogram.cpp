class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        heights.push_back(0); // Sentinel to flush stack
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int h = heights[stk.top()];
                stk.pop();
                
                int w = stk.empty() ? i : (i - stk.top() - 1);
                maxArea = max(maxArea, h * w);
            }
            stk.push(i);
        }

        return maxArea;
    }
};
