class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        unordered_set<char> set;
        set.insert('a');
        set.insert('e');
        set.insert('i');
        set.insert('o');
        set.insert('u');
        set.insert('A');
        set.insert('E');
        set.insert('I');
        set.insert('O');
        set.insert('U');
        int left = 0, right = n - 1;
        while(left < right)
        {
            if(set.find(s[left]) != set.end() && set.find(s[right]) != set.end())
            {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                right--;
                left++;
                continue;
            }
            if(set.count(s[right]) == 0)
            {
                right--;
            }
            if(set.count(s[left]) == 0)
            {
                left++;
            }
        }

        return s;
    }
};