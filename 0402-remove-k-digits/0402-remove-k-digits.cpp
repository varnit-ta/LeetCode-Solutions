class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;

        for (char el: num){
            while (!res.empty() && res.back() > el && k){
                k--;
                res.pop_back();
            }
            res.push_back(el);
        }

        while (k-- && !res.empty()) res.pop_back();

        int i = 0;
        while (i < res.size() && res[i] == '0') i++;

        res = res.substr(i);
        return res.empty() ? "0" : res;
    }
};