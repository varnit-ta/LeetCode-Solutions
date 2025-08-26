class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, 0), right(n, 0);

        for (int i = 1; i < n; i++) 
            if (arr[i-1] < arr[i])
                left[i] = left[i-1] + 1;
        
        for (int i = n-2; i >= 0; i--) 
            if (arr[i] > arr[i+1])
                right[i] = right[i+1] + 1;

        int maxLen = 0;

        for (int i = 1; i < n-1; i++) 
            if (arr[i-1] < arr[i] && arr[i] > arr[i+1])
                maxLen = max(maxLen, left[i] + right[i] + 1);

        return maxLen;   
    }
};