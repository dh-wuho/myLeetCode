class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        
        vector<int> cnt(26, 0);
        for(char c : tasks) {
            cnt[c - 'A']++;
        }
        sort(cnt.begin(), cnt.end());
        int mx = cnt[25];
        int moreMx = 25;
        while(moreMx > -1 && cnt[moreMx] == mx) {
            moreMx--;
        }
        
        return max(len, (mx - 1) * (n + 1) + 25 - moreMx);
    }
};