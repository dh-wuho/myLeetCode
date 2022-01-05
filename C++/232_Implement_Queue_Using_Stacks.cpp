class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> inStk;
    stack<int> outStk;
    int front;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(inStk.empty()) {
            front = x;
        }
        inStk.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(outStk.empty()) {
            while(!inStk.empty()) {
                outStk.push(inStk.top());
                inStk.pop();
            }
        }
        int res = outStk.top();
        outStk.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if(!outStk.empty()) {
            return outStk.top();
        }
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inStk.empty() && outStk.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */