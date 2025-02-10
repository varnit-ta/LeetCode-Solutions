class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> values = {5, 10, 20};
        vector<int> change = {0, 0, 0};

        for (int i = 0; i < bills.size(); i++){
            if (bills[i] == 5){
                change[0]++;
            }else{
                int req = (bills[i] - 5);

                for (int i = 2; i >= 0; i--){
                    int taken = min(change[i], (req / values[i]));
                    req -= values[i] * taken;
                    change[i] -= taken;
                }

                (bills[i] == 10) ? (change[1]++) : (change[2]++);
                if (req) return false;
            }
        }

        return true;
    }

};