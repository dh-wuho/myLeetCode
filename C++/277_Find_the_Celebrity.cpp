// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        // known[i][0] means the number of people i knows
        // known[i][1] means the number of people who know i
        vector<vector<int>> known(n, vector<int>(2, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(knows(i, j)) {
                    known[i][0]++;
                    known[j][1]++;
                }
                if(knows(j, i)) {
                    known[j][0]++;
                    known[i][1]++;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(known[i][0] == 0 && known[i][1] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};


// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(knows(res, i)) {
                res = i;
            }
        }
        
        for(int i = 0; i < res; i++) {
            if(knows(res, i) || !knows(i, res)) {
                return -1;
            }
        }
        
        for(int i = res + 1; i < n; i++) {
            if(!knows(i, res)) {
                return -1;
            }
        }
        
        return res;
    }
};