public class Solution {
    public int MinDeletions(string s) {
        int[] freq = new int[26];
        
        // Count frequency of each character
        foreach (char c in s) {
            freq[c - 'a']++;
        }

        var usedFrequencies = new HashSet<int>();
        int deletions = 0;

        foreach (int f in freq) {
            int currFreq = f;
            while (currFreq > 0 && !usedFrequencies.Add(currFreq)) {
                // Keep reducing until the frequency is unique
                currFreq--;
                deletions++;
            }
        }

        return deletions;
    }
}
