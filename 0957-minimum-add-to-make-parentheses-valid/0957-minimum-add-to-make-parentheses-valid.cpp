class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int count = 0;

        for (auto chr : s){
            if (chr == '(') stk.push('(');

            if (chr == ')'){
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else count++;
            }
        }

        while (!stk.empty()){
            count++;
            stk.pop();
        }

        return count;
    }
};