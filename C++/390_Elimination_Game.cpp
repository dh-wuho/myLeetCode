class Solution {
public:
    int lastRemaining(int n) {
        bool fromLeft = true;
        int head = 1;
        int remaining = n;
        int step = 1;
        
        while(remaining > 1) {
            if(fromLeft || remaining % 2 == 1) {
                head += step;
            }
            remaining /= 2;
            step *= 2;
            fromLeft = !fromLeft;
        }
        
        return head;
    }
};