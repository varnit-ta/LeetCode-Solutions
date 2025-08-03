class Solution {
public:
    int takenSteps(int l, int r, int startPos) {
        if (startPos <= l)
            return r - startPos;

        if (startPos >= r)
            return startPos - l;

        return min(2 * (startPos - l) + (r - startPos),
                   2 * (r - startPos) + (startPos - l));
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> ps(n + 1, 0);

        for (int i = 1; i <= n; i++)
            ps[i] = ps[i - 1] + fruits[i - 1][1];

        int left = 0;
        int maxFruits = 0;

        for (int right = 0; right < n; right++) {
            while (left <= right && takenSteps(fruits[left][0], fruits[right][0], startPos) > k)
                left++;

            maxFruits = max(maxFruits, ps[right + 1] - ps[left]);
        }

        return maxFruits;
    }
};