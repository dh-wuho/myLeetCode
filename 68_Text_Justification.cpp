class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int numWords = words.size();
        int wIndex;
        for(int i = 0; i < numWords; i = wIndex) {
            int len = -1;
            for(wIndex = i; wIndex < numWords && len + words[wIndex].size() + 1 <= maxWidth; wIndex++) {
                len += words[wIndex].size() + 1;
            }
            
            string currLine = words[i];
            int space = 1;
            int extra = 0;
            
            if(wIndex != i + 1 && wIndex != numWords) {
                space = (maxWidth - len) / (wIndex - i - 1) + 1; // len includes one space in each word.
                extra = (maxWidth - len) % (wIndex - i - 1); 
            }
            
            for(int j = i + 1; j < wIndex; j++) {
                for(int k = 0; k < space; k++) {
                    currLine.push_back(' ');
                }
                if(extra) {
                    currLine.push_back(' ');
                    extra--;
                }
                currLine += words[j];
            }
            
            int rest = maxWidth - currLine.size();
            while(rest) {
                currLine.push_back(' ');
                rest--;
            }
            res.push_back(currLine);
        }
        
        return res;
    }
};