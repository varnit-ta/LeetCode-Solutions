class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<string> res = {};

        if (nums.empty()) return res;

        if (nums.size() == 1){
            res.push_back(to_string(nums[0]));
            return res;
        }

        int first = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++){
            if (nums[i-1] + 1 == nums[i]){
                count++;
            }else{
                if (count == 1){
                    res.push_back(to_string(first));
                    first = nums[i];
                }else{
                    string el = "";

                    el += to_string(first);
                    el += "->";
                    el += to_string(nums[i - 1]);

                    res.push_back(el);

                    first = nums[i];
                    count = 1;
                }
            }
        }


        if (first == nums[nums.size() - 1]){
            res.push_back(to_string(first));
        }else{
            string el = "";

            el += to_string(first);
            el += "->";
            el += to_string(nums[nums.size() - 1]);

            res.push_back(el);
        }

        return res;
    }
};