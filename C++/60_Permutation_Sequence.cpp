class Solution {
public:
    string getPermutation(int n, int k) {
        string nums = "123456789";
        vector<int> factorial(n, 1);
        string res = "";
        for(int i = 1; i < n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        k--;
        for(int i = n - 1; i > -1; i--) {
            int index = k / factorial[i];
            k %= factorial[i];
            res.push_back(nums[index]);
            nums.erase(index, 1);
        }
        
        return res;
    }
};