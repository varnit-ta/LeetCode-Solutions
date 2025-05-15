class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0, el;
        vector<int> holding(height.size());

        int mx = 0;
        for (int i = 0; i < height.size(); i++){
            el = height[i];

            if (el >= mx) {
                mx = el;
                holding[i] = -1;
            }
            else{
                holding[i] = mx - el;
            }
        }

        mx = 0;
        for (int i = height.size() - 1; i >= 0; i--){
            el = height[i];

            if (el >= mx){ 
                holding[i] = -1;
                mx = el;
            }
            else{
                if (holding[i] != -1) holding[i] = min(holding[i], mx - el);
            }

            if (holding[i] != -1) total += holding[i];
        }

        return total;
    }
};