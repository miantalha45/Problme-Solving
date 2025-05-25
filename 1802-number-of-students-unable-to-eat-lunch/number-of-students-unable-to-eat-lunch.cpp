class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> que;
        stack<int> stk;
        int count = 0;

        for(int j = sandwiches.size() - 1; j >= 0; j--)
        {
            stk.push(sandwiches[j]);
        }

        for(int q : students)
        {
            que.push(q);
        }

        int i = 0;
        while(i < que.size())
        {
            if(!que.empty() && (que.front() == stk.top()))
            {
                que.pop();
                stk.pop();
                count++;
                i = 0;
            }
            else{
                que.push(que.front());
                que.pop();
                i++;
            }
        }

        return students.size() - count;
    }
};