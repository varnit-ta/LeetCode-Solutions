class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.size(), l2 = str2.size();

        int i = min(l1, l2);
        while (i != 0 && (l1 % i != 0 || l2 % i != 0)){
            i--;
        }

        if (str1 + str2 == str2 + str1) return str1.substr(0, i);
        return "";
    }
};