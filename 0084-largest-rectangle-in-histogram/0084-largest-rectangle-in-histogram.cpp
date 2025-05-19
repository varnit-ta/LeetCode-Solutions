class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<pair<int, int>> stk;
        int mx = 0;

        for (int i = 0; i < arr.size(); i++){
            while (!stk.empty() && arr[i] < stk.top().first){
                pair<int, int> el = stk.top(); 
                stk.pop();

                int left = stk.empty() ? -1 : stk.top().second;
                int right = (i == arr.size() - 1) ? arr.size() - 1: i;

                mx = max(mx, el.first * (right - left - 1));
            }

            stk.push({arr[i], i});
        }

        while (!stk.empty()){
            pair<int, int> el = stk.top(); 
            stk.pop();

            int left = stk.empty() ? -1 : stk.top().second;
            int right = arr.size();

            mx = max(mx, el.first * (right - left - 1));
        }

        return mx;
    }
};