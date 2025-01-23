class Solution {
public:
    string largestOddNumber(string num) {
        string res = num;

        for (int i = num.size() - 1; i >= 0; i--){
            if ((num[i] - '0') % 2 != 0) break;
            res.pop_back();
        }

        return res;
    }
};