class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        for(int i = 0; i < size; i++) {
            if(gas[i] < cost[i]) {
                continue;
            }
            int left = 0;
            for(int j = 0; j < size; j++) {
                int index = (i + j) % size;
                left += gas[index] - cost[index];
                if(left < 0) {
                    break;
                }
                if(j + 1 == size) {
                    return i;
                }
            }
        }
        
        return -1;
    }
};




class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int currSum = 0;
        int sum = 0;
        int start = 0;
        
        for(int i = 0; i < size; i++) {
            sum += gas[i] - cost[i];
            currSum += gas[i] - cost[i];
            if(currSum < 0) {
                start = i + 1;
                currSum = 0;
            }
        }
        
        return sum < 0 ? -1 : start;
    }
};