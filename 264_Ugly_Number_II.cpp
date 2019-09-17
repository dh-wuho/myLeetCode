class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int num_2 = 0, num_3 = 0, num_5 = 0;
        for(int i = 1; i < n; i++) {
            int product_2 = 2 * res[num_2];
            int product_3 = 3 * res[num_3];
            int product_5 = 5 * res[num_5];
            int ith = min(product_2, min(product_3, product_5));
            if(ith == product_2) {
                num_2++;
            }
            if(ith == product_3) {
                num_3++;
            }
            if(ith == product_5) {
                num_5++;
            }
            res.push_back(ith);
        }
        
        return res.back();
    }
};