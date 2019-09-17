/***                                                *
 * 1. When get to top of the rows, step = 1; when   *
 * get to bottom of the rows, stop = -1.            *                             
 * Time complexity : O(n).                          *
 * Space complexity :                             ***/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) {
            return s;
        }        
        
        string row[numRows];
        
        int step = 0;
        int currRow = 0;
        for(int i = 0; i < s.size(); i++) {
            row[currRow].push_back(s[i]);
            if(currRow == 0) {
                step = 1;
            }
            if(currRow == numRows - 1) {
                step = -1;
            }
            currRow += step;
        }
        
        for(int i = 1; i < numRows; i++) {
            row[0] += row[i];
        }
        
        return row[0];
    }
};

/***                                                *
 * 2. Get the law of the index by observing the     *
 * ZigZag string:                                   *
 *                                                  *
 * 0       8                                        *
 * 1     7 9                                        *
 * 2   6   10                                       *
 * 3 5                                              *
 * 4                                                *
 *                                                  *
 * Cycle = 2 * rows - 2;                            *
 * Each cycle has 2 elements in each row except for *
 * the first row and the last row.                  *
 * For elements in the middle,                      *
 * second = cycle - currRow + first;                *    
 * currRow + first to check if next cycle exists.   *                        
 * Time complexity : O(n).                          *
 * Space complexity :                             ***/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) {
            return s;
        }
        
        string res;
        int cycle = 2 * numRows - 2;
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; i + j < s.size(); j += cycle) {
                res.push_back(s[i + j]);
                if(i != 0 && i != numRows - 1 && j + cycle - i < s.size()) {
                    res.push_back(s[j + cycle - i]);
                }
            }
        }
                
        return res;
    }
};