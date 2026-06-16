class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if (n==0) return true;
 
        // 1. Convert all chars into lowercase
        for(int i = 0; i < n; i++) {
            s[i] = tolower(s[i]);
        }

        // 2. Remove the non-alphanumeric
        // 3. Check the chars from both end

        int l=0, r=n-1;
        while(l < r) {
            if(!isalnum(s[l])) {
                l++;
            }
            else if(!isalnum(s[r])) {
                r--;
            }
            else {
                if(s[l] != s[r]) {
                    return false;
                }
                l++;
                r--;
            }
        }

        return true;
    }
};