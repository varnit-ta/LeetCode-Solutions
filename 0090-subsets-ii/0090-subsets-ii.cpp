class Solution {
public:
    vector<vector<int>> res;
    set<vector<int>> tracks;
    int n;

    void f(vector<int>& nums, vector<int>& v, vector<int>& track, int p){
        res.push_back(v);

        for (int i = p; i < n; i++){
            v.push_back(nums[i]);
            track[nums[i] + 10]++;

            if (tracks.find(track) == tracks.end()){
                tracks.insert(track);
                f(nums, v, track, i+1);
            }

            track[nums[i] + 10]--;
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> track(21, 0);
        vector<int> v;
        n = nums.size();

        f(nums, v, track, 0);
        return res;
    }
};