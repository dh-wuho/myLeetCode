// O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || (k % n) == 0) {
            return;
        }
        k %= n;
        int start = 0;
        int index = 0;
        int pre = 0;
        int curr = nums[0];
        for(int i = 0; i < n; i++) {
            pre = curr;
            index = (index + k) % n;
            curr = nums[index];
            nums[index] = pre;
            if(index == start) {
                index = ++start;
                curr = nums[index];
            }
        }
    }
};