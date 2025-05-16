class BrowserHistory {
public:
    stack<string> backStack;
    stack<string> forwardStack;
    string current;
    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        while(!forwardStack.empty())
        {
            forwardStack.pop();
        }
        backStack.push(current);
        current = url;
    }
    
    string back(int steps) {
        while(steps > 0 && !backStack.empty())
        {
            forwardStack.push(current);
            current = backStack.top();
            backStack.pop();
            steps--;
        }
        return current;
    }
    
    string forward(int steps) {
        while(steps > 0 && !forwardStack.empty())
        {
            backStack.push(current);
            current = forwardStack.top();
            forwardStack.pop();
            steps--;
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */