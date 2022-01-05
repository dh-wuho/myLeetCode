class Solution { 
public: 
  int min_cost(vector<int> ropes){
      if(ropes.size() == 1) {
          return ropes[0];
      }  
      
      int res = 0;
      priority_queue<int, vector<int>, greater<int>> pq;
      
      for(int i = 0; i < ropes.size(); i++) {
          pq.push(ropes[i]);
      }
      
      while(pq.size() != 1) {
          int first = pq.top();
          pq.pop();
          int second = pq.top();
          pq.pop();
          pq.push(first + second);
          res += first + second;
      }
      
      return res;
  }
};