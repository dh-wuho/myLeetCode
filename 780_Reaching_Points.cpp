class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(sx <= tx && sy <= ty) {
            if(tx > ty) {
                if(ty == sy) {
                    return (tx - sx) % ty == 0;
                }
                tx %= ty;
            }
            else {
                if(tx == sx) {
                    return (ty - sy) % tx == 0;
                }
                ty %= tx;
            }
        }
        
        return tx == sx && ty == sy;
    }
};