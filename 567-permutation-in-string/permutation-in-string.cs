public class Solution {
    public bool CheckInclusion(string s1, string s2) {
        if (s1.Length > s2.Length) return false;
        int n = s2.Length;

        Dictionary<char, int> s1_Map = new();
        Dictionary<char, int> s2_Map = new();

        for(int i = 0;i < s1.Length;i++)
        {
            s1_Map[s1[i]] = s1_Map.GetValueOrDefault(s1[i], 0) + 1;
            s2_Map[s2[i]] = s2_Map.GetValueOrDefault(s2[i], 0) + 1;
        }

        if(AreFrequenciesEqual(s1_Map, s2_Map))
        {
            return true;
        } 

        for (int i = s1.Length; i < n; i++) {
            char newChar = s2[i];
            char oldChar = s2[i - s1.Length];

            s2_Map[newChar] = s2_Map.GetValueOrDefault(newChar, 0) + 1;

            if (s2_Map.ContainsKey(oldChar)) {
                s2_Map[oldChar]--;
                if (s2_Map[oldChar] == 0) s2_Map.Remove(oldChar);
            }

            if (AreFrequenciesEqual(s1_Map, s2_Map)) return true;
        }

        return false;
    }

    private bool AreFrequenciesEqual(Dictionary<char, int> map1, Dictionary<char, int> map2)
{
    if (map1.Count != map2.Count) return false;

        foreach (var kvp in map1) {
            if (!map2.ContainsKey(kvp.Key) || map2[kvp.Key] != kvp.Value) return false;
        }

        return true;
}
}