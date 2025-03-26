public class Solution {
    public string LongestPalindrome(string s) {
        if (string.IsNullOrEmpty(s)) return "";

        int start = 0, maxLength = 0;
        for(int i = 0; i < s.Length; i++)
        {
            ExpandAroundCenter(s, i, i, ref start, ref maxLength);

            ExpandAroundCenter(s, i, i + 1, ref start, ref maxLength);
        }

        return s.Substring(start,maxLength);

    }

        private void ExpandAroundCenter(string s, int left, int right, ref int  start, ref int maxLength) {
        while (left >= 0 && right < s.Length && s[left] == s[right]) {
            int length = right - left + 1;
            if (length > maxLength) {
                start = left;
                maxLength = length;
            }
            left--;
            right++;
        }
    }
}