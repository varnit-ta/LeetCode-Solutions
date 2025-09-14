class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int res = 0;
        int left = 0;
        int sm = neededTime[0], mx = neededTime[0];

        for (int right = 1; right < n; right++) {
            if (colors[right] == colors[right-1]) {
                sm += neededTime[right];
                mx = max(mx, neededTime[right]);
            } else {
                if (right - left > 1) {
                    res += (sm - mx);
                }
                left = right;
                sm = neededTime[right];
                mx = neededTime[right];
            }
        }

        if (n - left > 1) {
            res += (sm - mx);
        }

        return res;
    }
};
