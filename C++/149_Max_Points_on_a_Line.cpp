class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); i++) {
            int duplica = 1;
            map<pair<int, int>, int> m;
            for(int j = i + 1; j < points.size(); j++) {
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                if(x1 == x2 && y1 == y2) {
                    duplica++;
                    continue;
                }
                int dx = x1 - x2;
                int dy = y1 - y2;
                int d = gcf(dx, dy);
                m[{dx / d, dy / d}]++;
            }
            
            res = max(res, duplica);
            for(auto it = m.begin(); it != m.end(); it++) {
                res = max(res, it->second + duplica);
            }
        }
        
        return res;
    }
    
    int gcf(int a, int b) {
        if(b == 0) {
            return a;
        }
        
        int c;        
        while(a % b != 0) {
            c = a % b;
            a = b;
            b = c;
        }
        return b;
    }
};