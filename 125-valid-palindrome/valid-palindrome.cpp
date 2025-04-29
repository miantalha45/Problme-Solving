class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if(n == 0) return true;
        
        int left = 0, right = n - 1;
        while(left < right)
        {
            if(!isalnum(s[left]))
            {
                left++;
            }
            else if(!isalnum(s[right]))
            {
                right--;
            }
            else{

            if(tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
                left++;
                right--;
            }
        }
        return true;
    }
};