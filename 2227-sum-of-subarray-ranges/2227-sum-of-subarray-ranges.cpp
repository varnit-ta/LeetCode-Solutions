class Solution {
public:
    vector<int> findNGE(vector<int>& arr, int n){
        vector<int> res(n, n);
        stack<int> stk;

        for (int i = 0; i < n; i++){
            while (!stk.empty() && arr[stk.top()] < arr[i]){
                res[stk.top()] = i;
                stk.pop();
            }

            stk.push(i);
        }

        return res;
    }

    vector<int> findPGE(vector<int>& arr, int n){
        vector<int> res(n, -1);
        stack<int> stk;

        for (int i = 0; i < n; i++){
            while (!stk.empty() && arr[stk.top()] < arr[i]) stk.pop();

            if (!stk.empty()) res[i] = stk.top();
            stk.push(i);
        }

        return res;
    }

    vector<int> findNSE(vector<int>& arr, int n){
        vector<int> res(n, n);
        stack<int> stk;

        for (int i = 0; i < n; i++){
            while (!stk.empty() && arr[stk.top()] > arr[i]){
                res[stk.top()] = i;
                stk.pop();
            }

            stk.push(i);
        }

        return res;
    }

    vector<int> findPSE(vector<int>& arr, int n){
        vector<int> res(n, -1);
        stack<int> stk;

        for (int i = 0; i < n; i++){
            while (!stk.empty() && arr[stk.top()] > arr[i]) stk.pop();

            if (!stk.empty()) res[i] = stk.top();
            stk.push(i);
        }

        return res;
    }


    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevMin = findPSE(nums, n);
        vector<int> nextMin = findNSE(nums, n);
        vector<int> prevMax = findPGE(nums, n);
        vector<int> nextMax = findNGE(nums, n);

        long long total = 0;

        for (int i = 0; i < n; i++){
            long long mn = (i - prevMin[i]) * (nextMin[i] - i);
            long long mx = (i - prevMax[i]) * (nextMax[i] - i);
            total += (mx - mn) * nums[i];
        }

        return total;
    }
};