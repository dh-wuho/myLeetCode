class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) {
            return 0;
        }
        int trasctions = 2;
        int days = prices.size();
        vector<vector<int>> global(days, vector<int>(trasctions + 1, 0));
        vector<vector<int>> local(days, vector<int>(trasctions + 1, 0));
        
        for(int i = 1; i < days; i++) {
            int diff = prices[i] - prices[i - 1];
            for(int j = 1; j < trasctions + 1; j++) {
                local[i][j] = max(global[i - 1][j - 1], local[i - 1][j]) + diff;
                global[i][j] = max(global[i - 1][j], local[i][j]);
            }
        }
        
        return global[days - 1][trasctions];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN;
        int buy2 = INT_MIN;
        int sell1 = 0;
        int sell2 = 0;
        for(int price : prices) {
            buy1 = max(buy1, - price);
            sell1 = max(sell1, buy1 + price);
            buy2 = max(buy2, sell1 - price);
            sell2 = max(sell2, buy2 + price);
        }
        
        return sell2;
    }
};