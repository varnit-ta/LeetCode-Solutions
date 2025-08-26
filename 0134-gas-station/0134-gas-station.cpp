class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int currGas = 0, currIndx = 0;
        int totalCost = 0, totalGas = 0;

        for (int i = 0; i < n; i++) {
            currGas += gas[i] - cost[i];
            totalCost += cost[i];
            totalGas += gas[i];

            if (currGas < 0) {
                currGas = 0;
                currIndx = i+1;
            }
        }

        return (totalGas < totalCost) ? -1 : currIndx;
    }
};