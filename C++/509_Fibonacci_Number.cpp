class Solution {
public:
    int fib(int N) {
        if(N < 2) {
            return N;
        }
        return fib(N - 1) + fib(N - 2);
    }
};

class Solution {
public:
    int fib(int N) {
        if(N < 2) {
            return N;
        }
        int a = 0;
        int b = 1;
        int c = 0;
        for(int i = 1; i < N; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}; 