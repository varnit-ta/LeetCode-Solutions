/*
    The idea is to simulate the process of removing from both sides:
    - We calculate the minimum cost to remove all '1's from the left up to each index.
    - We also calculate the cost to remove all '1's from the right starting from each index.
    
    For each index, we consider the total cost of removing some '1's from the left
    and the rest from the right — essentially trying all possible split points.
    
    We also make sure to consider the edge cases where we remove everything either
    from the left only or from the right only.
    
    The final answer is the minimum cost among all these options.

    Link: https://www.youtube.com/watch?v=QjPL6-ZX_Cs
*/

class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();

        vector<int> left(n, 0);
        if (s[0] == '1') left[0] = 1;

        for (int i = 1; i < n; i++)
            if (s[i] == '1') left[i] = min(i + 1, left[i - 1] + 2);
            else left[i] = left[i - 1];

        vector<int> right(n, 0);
        if (s[n - 1] == '1') right[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)
            if (s[i] == '1') right[i] = min(n - i, right[i + 1] + 2);
            else right[i] = right[i + 1];

        int mini = right[0];           // remove all from right
        mini = min(mini, left[n - 1]); // remove all from left
        
        for (int i = 1; i < n-1; i++)
            mini = min(mini, left[i] + right[i]);

        return mini;
    }
};