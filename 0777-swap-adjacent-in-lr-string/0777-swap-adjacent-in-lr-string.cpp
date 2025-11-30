class Solution {
public:
    bool canTransform(string start, string result) {
        int i = 0, j = 0;
        int n = start.size();

        while (i < n || j < n) {
            while (start[i] == 'X' && i < n) i++;
            while (result[j] == 'X' && j < n) j++;

            if (i == n || j == n) return i == n && j == n;
            if (start[i] != result[j]) return false;
        
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;

            i++;
            j++;
        }

        return true;
    }
};