class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3, -1);
        int total = 0;

        for (int i = 0; i < s.size(); i++){
            last[s[i] - 'a'] = i;

            if (last[0] != -1 && last[1] != -1 && last[2] != -1){
                int minLast = min({last[0], last[1], last[2]});
                total += minLast + 1;
            }
        }

        return total;
    }
};