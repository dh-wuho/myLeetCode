class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right) {
            int tmp = numbers[left] + numbers[right];
            if(tmp == target) {
                break;
            }
            if(tmp < target) {
                left++;
            }
            else {
                right--;
            }
        }
        
        return {left + 1, right + 1};
    }
};