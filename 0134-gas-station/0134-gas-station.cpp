class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total_gas = 0, total_cost = 0, start = 0, fuel = 0;
    for (int i = 0; i < gas.size(); i++) {
        total_gas += gas[i];
        total_cost += cost[i];
        fuel += gas[i] - cost[i];
        if (fuel < 0) {
            start = i + 1; // Reset start station
            fuel = 0;      // Reset fuel
        }
    }
    return (total_gas >= total_cost) ? start : -1; 
    }
};