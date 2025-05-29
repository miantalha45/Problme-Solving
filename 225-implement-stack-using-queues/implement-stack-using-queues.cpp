class MyStack {
private:
    queue<int> q;
    int topp;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        topp = x;
        int size = q.size();
        while(size > 1)
        {
            int n = q.front();
            q.pop();
            q.push(n);
            size--;
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        if (!q.empty()) {
            topp = q.front();
        }
        return val;
    }
    
    int top() {
        return topp;
    }
    
    bool empty() {
        return q.empty() ? true : false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */