/***                                                *
 * 1.      Manacher's Algorithm                     *                                          *
 * Time complexity : O(n)                           *
 * Space complexity : O(n)                        ***/


class Solution {
public:
    string longestPalindrome(string s) {
        string tmps = "$#";
        for(int i = 0; i < s.size(); i++) {
            tmps += s[i];
            tmps += "#";
        }
        
        vector<int> radius(tmps.size(), 0);
        int max = 0;
        int center = 1;
        int resLen = 0;
        int resCen = 0;
        
        for(int i = 1; i < tmps.size(); i++) {
            if(max > i) {
                radius[i] =  min(radius[2 * center - i], max - i);
            }
            else {
                radius[i] = 1;
            }
            
            while(tmps[i + radius[i]] == tmps[i - radius[i]]) {
                radius[i]++;
            }
            
            if(max < i + radius[i]) {
                center = i;
                max = i + radius[i];
            }
            
            if(radius[i] > resLen) {
                resCen = i;
                resLen = radius[i];
            }
        }
        
        return s.substr((resCen - resLen) / 2, resLen - 1);
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 1;
        int start = 0;
        
        // start from j to i
        /*
          b a b a d
        b T T T
        a   T F
        b     T
        a
        d
        */
        
        
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
            for(int j = 0; j < i; j++) {
                dp[j][i] = (s[i] == s[j]) && (i - j < 2 || dp[j + 1][i - 1]);
                if(dp[j][i] && i - j + 1 > maxLen){
                    start = j;
                    maxLen = i - j + 1;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) {
            return s;
        }
        
        int n = s.size();
        int maxLen = 0;
        int start = 0;
        
        for(int i = 0; i < n - 1; i++) {
            searchPalindrome(s, i, i, start, maxLen);
            searchPalindrome(s, i, i + 1, start, maxLen);
        }
        
        return s.substr(start, maxLen);
    }
    
    void searchPalindrome(string s, int left, int right, int& start, int& maxLen) {
        while(left > - 1 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        if(maxLen < right - left - 1) {
            start = left + 1;
            maxLen = right - left - 1;
        }
    }
};