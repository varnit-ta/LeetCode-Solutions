class Solution {
public:
    int help(string& s, int l, int r){
        int count = 0;

        while (l >= 0 && r < s.size() && s[l] == s[r]){
            count++;
            l--; r++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++){
            count += help(s, i, i);
            count += help(s, i, i+1);
        }

        return count;
    }
};