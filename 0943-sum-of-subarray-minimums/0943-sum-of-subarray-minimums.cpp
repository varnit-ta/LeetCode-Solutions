class Solution {
public:
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, n);
        stack<int> stk;

        for (int i = 0; i < n; i++){
            while (!stk.empty() && arr[i] <= arr[stk.top()]){
                res[stk.top()] = i;
                stk.pop();
            }

            stk.push(i);
        }

        return res;
    }

    vector<int> findPSE(vector<int>& arr){
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;

        for (int i = 0; i < n; i++){
            while (!stk.empty() && arr[i] <= arr[stk.top()]){
                stk.pop();
            }

            if (!stk.empty()) res[i] = stk.top();
            stk.push(i);
        }

        return res;
    }


    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);

        int total = 0;
        long long mod = 1e9 + 7;

        for (int i = 0; i < arr.size(); i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;

            total = (total + (left * right % mod) * arr[i]) % mod;
        }

        return total;
    }
};