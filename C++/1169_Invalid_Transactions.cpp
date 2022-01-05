class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<string> name(n);
        vector<int> time(n);
        vector<int> amount(n);
        vector<string> city(n);
        vector<string> res;
        vector<bool> isValid(n, true);
        
        for(int i = 0; i < n; i++) {
            stringstream ss(transactions[i]);
            string tmp;
            std::getline(ss, name[i], ',');
            std::getline(ss, tmp, ',');
            std::istringstream(tmp) >> time[i];
            std::getline(ss, tmp, ',');
            std::istringstream(tmp) >> amount[i];
            std::getline(ss, city[i], ',');
        }
        
        for(int i = 0; i < n; i++) {
            if(amount[i] > 1000) {
                isValid[i] = false;
            }
            for(int j = 0; j < n; j++) {
                if(name[i] == name[j] && city[i] != city[j] && abs(time[i] - time[j]) <= 60) {
                    isValid[i] = false;
                    isValid[j] = false;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(!isValid[i]) {
                res.push_back(transactions[i]);
            }
        }
        
        return res;
    }
};