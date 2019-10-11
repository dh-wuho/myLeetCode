class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> mySet;
        while(n != 1) {
            mySet.emplace(n);
            int newN = 0;
            while(n > 0) {
                int d = n % 10;
                newN += d * d;
                n /= 10;
            }
            n = newN;
            if(mySet.count(n)) {
                return false;
            }
        }
        return true;
    }
};