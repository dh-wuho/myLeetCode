class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        sAll.push(x);
        if(sMin.empty() || x <= sMin.top()) {
            sMin.push(x);
        }
    }
    
    void pop() {
        if(sAll.top() == sMin.top()) {
            sMin.pop();
        }
        sAll.pop();
    }
    
    int top() {
        return sAll.top();
    }
    
    int getMin() {
        return sMin.top();
    }
    
private:
    stack<int> sAll;
    stack<int> sMin;
};