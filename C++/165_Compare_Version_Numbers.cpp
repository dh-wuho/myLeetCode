class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        version1 += '.';
        version2 += '.';
        
        stringstream ss1(version1);
        stringstream ss2(version2);
        
        int v1 = 0;
        int v2 = 0;
        char dot;
        
        while(ss1.good() || ss2.good()) {
            if(ss1.good()) {
                ss1 >> v1 >> dot;
            }
            if(ss2.good()) {
                ss2 >> v2 >> dot;
            }
            if(v1 > v2) {
                return 1;
            }
            if(v1 < v2) {
                return -1;
            }
            v1 = 0;
            v2 = 0;
        } 
        return 0;
    }
};