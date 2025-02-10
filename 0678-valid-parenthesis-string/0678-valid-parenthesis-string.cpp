class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0, mx = 0;

        for (char el: s){
            if (el == '(') {mn++; mx++;}
            if (el == ')') {mn--; mx--;}
            if (el == '*') {mn--; mx++;}

            if (mn < 0) mn = 0;
            if (mx < 0) return false;
        }

        return (mn == 0);
    }
};