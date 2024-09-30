class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;

        for (auto x : s) {
            mp[x]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (auto x : mp) {
            if (x.second % 2 == 0) {
                length += x.second; 
            } else {
                length += (x.second - 1);
                hasOdd = true;
            }
        }
        
        if (hasOdd) {
            length += 1;
        }

        return length;
    }
};
