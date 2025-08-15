class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> arr(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (boxes[i] == '1') arr[j] += (j - i);
                if (boxes[j] == '1') arr[i] += (j - i);
            }
        }

        return arr;
    }
};