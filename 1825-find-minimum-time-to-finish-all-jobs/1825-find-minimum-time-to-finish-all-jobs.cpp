class Solution {
public:
    bool check(vector<int>& jobs, vector<int>& work, int k, int mid, int indx) {
        if (indx == jobs.size())
            return true;

        for (int i = 0; i < k; i++) {
            if (work[i] + jobs[indx] <= mid) {
                work[i] += jobs[indx];
                
                if (check(jobs, work, k, mid, indx + 1)) 
                    return true;

                work[i] -= jobs[indx];
            }
            if (work[i] == 0) break;
        }
        return false;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend());
        int low = *max_element(jobs.begin(), jobs.end());
        int high = accumulate(jobs.begin(), jobs.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            vector<int> work(k, 0);

            if (check(jobs, work, k, mid, 0)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
