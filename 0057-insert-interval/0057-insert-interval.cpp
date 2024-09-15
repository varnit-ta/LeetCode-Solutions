class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n == 0 && newInterval.size() == 0) return {};
        if (n == 0 && newInterval.size() != 0) return {newInterval};

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < n+1; i++){
            if (res.back()[1] >= intervals[i][0]) res.back()[1] = max(intervals[i][1], res.back()[1]);
            else res.push_back(intervals[i]);
        }

        return res;
    }
};