/***                                                *
 * 1. Binary Search by Myself                       *                                  
 * Time complexity :                                *
 * Space complexity :                             ***/

class Solution {
public:
    vector<int> weight;
    
    Solution(vector<int> w) {
        weight.push_back(w[0]);
        for(int i = 1; i < w.size(); i++) {
            weight.push_back(weight.back() + w[i]);
        }
    }
    
    int pickIndex() {
        
        int rNum = rand() % weight.back();
        int start = 0;
        int end = weight.size();
        
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(weight[mid] <= rNum) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        
        return start;
    }
};

/***                                                *
 * 2. Binary Search By using STL                    *                                  
 * Time complexity :                                *
 * Space complexity :                             ***/
class Solution {
public:
    vector<int> weight;
    
    Solution(vector<int> w) {
        for(auto i : w) {
            weight.push_back(weight.empty() ? i : (i + weight.back()));
        }
    }
    
    int pickIndex() {
        int rNum = rand() % weight.back();
        auto it = upper_bound(weight.begin(), weight.end(), rNum);        
        return it - weight.begin();
    }
};