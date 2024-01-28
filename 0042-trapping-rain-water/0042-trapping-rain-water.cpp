class Solution {
public:
    int trap(vector<int>& height) {
        int maxHeight = *max_element(height.begin(), height.end());
        int maxHeightIndex;

        for (int i = 0; i < height.size(); i++){
            if (height[i] == maxHeight){
                maxHeightIndex = i;
                break;
            }
        }

        int walls = 0, water = 0, holdWater = 0;
        int left = 0, right = height.size() - 1;

        while (left != maxHeightIndex){
            if (height[left] < walls){
                water = water + (walls - height[left]);
            }else{
                walls = height[left];
            }
            left++;
        }

        holdWater += water;
        water = 0;
        walls = 0;

        while (right != maxHeightIndex){
            if (height[right] < walls){
                water = water + (walls - height[right]);
            }else{
                walls = height[right];
            }
            right--;
        }

        holdWater += water;

        return holdWater;
    }
};