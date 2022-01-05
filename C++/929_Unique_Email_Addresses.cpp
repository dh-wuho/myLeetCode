class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        string local;
        string domain;
        unordered_set<string> res;
        
        for(int i = 0; i < emails.size(); i++) {
            int atPos = emails[i].find_first_of('@');
            local = emails[i].substr(0, atPos);
            domain = emails[i].substr(atPos);
            int plusPos = local.find_first_of('+');
            local = local.substr(0, plusPos);
            /*int pointPos = local.find('.');
            while(pointPos != std::string::npos) {
                local.erase(pointPos);
                pointPos = local.find('.');
            }*/
            local.erase(std::remove(local.begin(), local.end(), '.'), local.end());
            res.emplace(local + domain);
        }
        
        return res.size();
    }
};