public class Solution {
    public bool ValidPalindrome(string s) {
        int n = s.Length;
        int l = 0, r = n - 1;
        while(l <= r)
        {
            if(s[l] != s[r])
            {
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
            l++; r--;
        }

        return true;
    }

    private bool isPalindrome(string s, int l, int r)
    {
        while(l <= r)
        {
            if(s[l] != s[r])
            {
                return false;
            }
            l++; r--;
        }
        return true;
    }
}