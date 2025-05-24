class MyQueue {
public:
    stack<int> stkA; 
    stack<int> stkB; 

    MyQueue() {}

    void push(int x) {
        stkA.push(x);
    }

    int pop() {
        if (stkB.empty()) {
            while (!stkA.empty()) {
                stkB.push(stkA.top());
                stkA.pop();
            }
        }
        int res = stkB.top();
        stkB.pop();
        return res;
    }

    int peek() {
        if (stkB.empty()) {
            while (!stkA.empty()) {
                stkB.push(stkA.top());
                stkA.pop();
            }
        }
        return stkB.top();
    }

    bool empty() {
        return stkA.empty() && stkB.empty();
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