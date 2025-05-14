class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;

        map<char, char> mp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char el: s){
            if (el == '(' || el == '{' || el == '['){
                s1.push(el);
            }else{
                if (!s1.empty() && s1.top() == mp[el]) s1.pop();
                else return false;
            }
        }

        return s1.empty();
    }
};