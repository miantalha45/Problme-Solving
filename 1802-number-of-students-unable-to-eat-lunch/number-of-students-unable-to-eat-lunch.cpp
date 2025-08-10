class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> s;
        queue<int> q;

        for(int student : students)
        {
            q.push(student);
        }

        for(int i = sandwiches.size() - 1; i >= 0; i--) {
            s.push(sandwiches[i]);
        }

        int count = 0;
        while(!s.empty())
        {
            int revise = 0;
            while(s.top() != q.front())
            {
                if(revise == q.size())
                {
                    return q.size();
                }
                q.push(q.front());
                q.pop();
                revise++;
            }

            if(s.top() == q.front())
            {
                s.pop();
                q.pop();
                count++;
            }

        }

        return q.size();
    }
};