class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int num : nums) {
            pq.push(num);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        return pq.top();
    }
};



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int pivotK;
        
        while(true) {
            pivotK = partition(nums, left, right);
            if(pivotK == k - 1) {
                break;
            }
            if(pivotK > k - 1) {
                right = pivotK - 1;
            }
            if(pivotK < k - 1) {
                left = pivotK + 1;
            }
        }
        
        return nums[pivotK];
    }
    
    int partition(vector<int>& nums, int left, int right) {
        // srand(time(NULL));
        // int pivotIndex = rand() % ((right - left) + 1) + left;
        int pivotIndex = left;
        int pivot = nums[pivotIndex];
        int l = left + 1;
        int r = right;
        while(l <= r) {
            if(nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            if(nums[l] >= pivot) {
                l++;
            }
            if(nums[r] <= pivot) {
                r--;
            }
        }
        // swap(nums[left], nums[l]);
        // return l;
        swap(nums[left], nums[r]);
        return r;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int pivotK;
        
        while(true) {
            pivotK = partition(nums, left, right);
            if(pivotK == k - 1) {
                break;
            }
            if(pivotK > k - 1) {
                right = pivotK - 1;
            }
            if(pivotK < k - 1) {
                left = pivotK + 1;
            }
        }
        
        return nums[pivotK];
    }
    
    int partition(vector<int>& nums, int left, int right) {
        srand(time(NULL));
        int pivotIndex = rand() % ((right - left) + 1) + left;
        int pivot = nums[pivotIndex];
        
        swap(nums[pivotIndex], nums[right]);
        // fp is the leftmost element which is bigger than pivot
        int fp = left;
        
        for(int sp = left; sp <= right; sp++) {
            if(nums[sp] > pivot) {
                swap(nums[fp], nums[sp]);
                fp++;
            }
        }
        swap(nums[fp], nums[right]);
        
        return fp;
    }
};