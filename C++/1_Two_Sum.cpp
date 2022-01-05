class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> aMap;
        int tmp;
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++) {
            tmp = target - nums[i];
            if(aMap.find(tmp) != aMap.end()) {
                ret.push_back(aMap[tmp]);
                ret.push_back(i);
                return ret;
            }
            aMap[nums[i]] = i;
        }
    }
};


// ibm 面经 two sum

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct pair_hash {
    template <class T1, class T2> 
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};


int main()
{
    vector<int> arr = {1, 3, 2, 1, 3, 3, 1, 2};
    unordered_map<int, int> m;
    unordered_set<pair<int, int>, pair_hash> res;
    int target = 4;
    
    for(int i = 0; i < arr.size(); i++) {
        int tmp = target - arr[i];
        if(m.find(tmp) != m.end()) {
            res.insert(make_pair(tmp, arr[i]));
        }
        else {
            m[arr[i]] = i;
        }
        
    }
    
    for(auto it = res.begin(); it != res.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}