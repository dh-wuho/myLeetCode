class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int index = 0;
        int n = s.size();
        reverse(s.begin(), s.end());
        while(start < n) {
            if(s[start] != ' ') {
                if(index != 0) {
                    s[index] = ' ';
                    index++;
                }
                int end = start;
                while(end < n && s[end] != ' ') {
                    s[index] = s[end];
                    index++;
                    end++;
                }    
                reverse(s.begin() + index - (end - start), s.begin() + index);
                start = end;
            } 
            start++;
        }
        
        s.resize(index);
        
        return s;
    }
    
};