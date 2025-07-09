/*
    Step 1: XOR all numbers. Duplicates cancel out (a ^ a = 0), so we're left with x ^ y.
    Step 2: Since x ≠ y, x ^ y ≠ 0. This result has at least one bit set — a position where x and y differ.
    Step 3: We isolate the rightmost set bit using xorAll & -xorAll to find one such differing bit.
    Step 4: Use this bit to partition the array into two groups:
            - One group with that bit set
            - One group with that bit unset
    Step 5: In each group, duplicates still cancel out, leaving one unique number in each.
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorAll = 0;
        for (int num : nums)
            xorAll ^= num;

        int distinguishingBit = xorAll & -xorAll;

        vector<int> result(2, 0);

        for (int num : nums) {
            if (num & distinguishingBit)
                result[1] ^= num;
            else
                result[0] ^= num;
        }

        return result;
    }
};
