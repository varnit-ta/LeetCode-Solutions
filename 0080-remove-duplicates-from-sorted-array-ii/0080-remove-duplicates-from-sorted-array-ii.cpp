#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int total = 0; 
        int count = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[total]) {
                count++;
            } else {
                count = 1;
            }

            if (count <= 2) {
                nums[++total] = nums[i];
            }
        }

        return (total + 1);
    }
};
