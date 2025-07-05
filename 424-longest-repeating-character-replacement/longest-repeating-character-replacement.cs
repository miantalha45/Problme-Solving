public class Solution {
    public int CharacterReplacement(string s, int k) {
        int n = s.Length;

        if(n < 2)
            return n;

        int[] freq = new int[26];
        
        int l = 0;
        int res = 0;
        int MaxFreq = 0;

        for(int r = 0;r < n;r++)
        {
            freq[s[r] - 'A']++;

            MaxFreq = Math.Max(MaxFreq, freq[s[r] - 'A']);
            while((r - l + 1) - MaxFreq > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }

            res = Math.Max(res, r - l + 1);

        }

        return res;
    }
}