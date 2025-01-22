class Solution {
public:
    string removeOuterParentheses(string s) {
        int bal = 0;
        string result = "";

        for (char el: s){
            if (el == '('){
                if (bal > 0) result += "(";
                bal++;
            }else{
                bal--;
                if (bal > 0) result += ")";
            }
        }
        return result;
    }
};