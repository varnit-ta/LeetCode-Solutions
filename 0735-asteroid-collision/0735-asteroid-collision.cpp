class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        for (int el: asteroids){
            if (el > 0){
                stk.push(el);
            }else{
                while (!stk.empty() && stk.top() > 0 && stk.top() < abs(el)) stk.pop();

                if (stk.empty() || stk.top() < 0){
                    stk.push(el);
                }else if(stk.top() == abs(el)){
                    stk.pop();
                }
            }
        }

        vector<int> res(stk.size());
        for (int i = stk.size() - 1; i >= 0; i--){
            res[i] = stk.top();
            stk.pop();
        }

        return res;
    }
};