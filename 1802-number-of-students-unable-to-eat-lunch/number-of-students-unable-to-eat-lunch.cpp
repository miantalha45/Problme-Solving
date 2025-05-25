class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0, count1 = 0;

        for(int s : students)
        {
            if(s == 0)
            {
                count0++;
            }
            else{
                count1++;
            }
        }

        for(int n : sandwiches)
        {
            if(n == 0 && count0 > 0) count0--;
            else if(n == 1 && count1 > 0) count1--;
            else break;
        }

        return count0 + count1;
    }
};