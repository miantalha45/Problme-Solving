public class Solution {
    public int CharacterReplacement(string s, int k) {
        int[] charCounts = new int[26];
    
        int maxFreq = 0;

        int left = 0, maxLength = 0;
        for(int right = 0; right < s.Length; right++)
        {
            charCounts[s[right] - 'A']++;
            
            maxFreq = Math.Max(maxFreq, charCounts[s[right] - 'A']);
            while((right - left + 1) - maxFreq > k)
            {   
                charCounts[s[left] - 'A']--;
                left++;
            }

            maxLength = Math.Max(maxLength, (right - left + 1));
        }
        return maxLength;
    }
}