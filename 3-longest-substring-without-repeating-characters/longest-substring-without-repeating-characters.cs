public class Solution {
    public int LengthOfLongestSubstring(string s) {
        int n = s.Length;
        if(n < 2)
            return n;
        HashSet<char> set = new HashSet<char>();
        int res = 0;
        int l = 0;
        set.Add(s[l]);
        for(int r = 1;r < n; r++)
        {
            while(set.Contains(s[r]))
            {
                set.Remove(s[l]);
                l++;
            }

            set.Add(s[r]);

            int len = r - l + 1;
            res = Math.Max(res, len);
        }

        return res;
    }
}