public class Solution {
    public int LeastInterval(char[] tasks, int n) {
        if(n == 0) return tasks.Length;

        int[] freq = new int[26];
        foreach(char task in tasks)
        {
            freq[task - 'A']++;
        }

        Array.Sort(freq);
        int maxFreq = freq[25] - 1;
        int idleSlots = maxFreq * n;

        for (int i = 24; i >= 0 && freq[i] > 0; i--)
        {
            idleSlots -= Math.Min(freq[i], maxFreq);
        }

        idleSlots = Math.Max(0, idleSlots);

        return tasks.Length + idleSlots;
    }
}