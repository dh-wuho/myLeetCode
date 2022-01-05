class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; i++) {
            int sum = 0;
            for(int j = 0; j < nums.size(); j++) {
                sum += (nums[j] >> i) & 1;
            }
            res += (sum % 3) << i;
            
        }
        
        return res;
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0;
        int twice = 0;
        for(int i = 0; i < nums.size(); i++) {
            once = (once^nums[i]) & ~twice;
            twice = (twice^nums[i]) & ~once;
        }
        
        return once;
    }
};