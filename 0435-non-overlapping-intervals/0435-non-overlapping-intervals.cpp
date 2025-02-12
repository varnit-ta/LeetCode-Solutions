bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);

        int choosen = 0, freeAt = INT_MIN;

        for (int i = 0; i < n; i++){
            if (intervals[i][0] >= freeAt){
                choosen++;
                freeAt = intervals[i][1];
            }
        }

        return (n - choosen);
    }
};