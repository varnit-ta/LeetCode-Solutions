#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        vector<string> ph = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        function<void(int, string)> backtrack = [&](int index, string current) {
            if (index == digits.size()) {
                res.push_back(current);
                return;
            }

            string letters = ph[digits[index] - '0'];
            for (char c : letters) {
                backtrack(index + 1, current + c);
            }
        };

        backtrack(0, "");
        return res;
    }
};
