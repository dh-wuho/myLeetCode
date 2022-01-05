class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int> > directions = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}}; // 0123 = north, west, south, east
        int x = 0;
        int y = 0;
        int d = 0;
        for(int j = 0; j < instructions.size(); j++) {
            switch(instructions[j]) {
                case 'L': {
                    d++;
                    d %= 4;
                    break;
                }
                case 'R': {
                    d = (d + 3) % 4;
                    break;
                }
                default: {
                    x += directions[d][0];
                    y += directions[d][1];
                }
            }
        }
        
        
        if((x == 0 && y == 0) || d > 0) {
            return true;
        }
        return false;
    }
};