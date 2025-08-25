/**
 * Intuition:
 * - Problem reduces to finding the maximum number of envelopes that can be nested.
 * - First sort envelopes by width ascending.
 *   - But if widths are equal, sort heights descending.
 *   - Why? → This avoids counting envelopes with the same width as valid LIS steps.
 *     Example: (5,4) and (5,6). If sorted ascending by height, LIS would wrongly
 *     allow (5,4) → (5,6), but widths are equal so it's invalid. Descending fixes this.
 * - After sorting, the width order is fixed, so we only need to find the
 *   Longest Increasing Subsequence (LIS) on the heights.
 * - We use patience sorting (binary search + vector) to build LIS in O(n log n).
 * - The length of this LIS = maximum number of envelopes we can nest.
 */

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = envelopes.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(ans.begin(), ans.end(), envelopes[i][1]);

            if (it == ans.end()) ans.push_back(envelopes[i][1]);
            else *it = envelopes[i][1];
        }

        return ans.size();
    }
};