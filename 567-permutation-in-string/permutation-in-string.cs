public class Solution {
    public bool CheckInclusion(string s1, string s2) {
        if (s1.Length > s2.Length) return false;

        var map1 = new Dictionary<char, int>();
        var map2 = new Dictionary<char, int>();

        for (int i = 0; i < s1.Length; i++) {
            map1[s1[i]] = map1.GetValueOrDefault(s1[i], 0) + 1;
            map2[s2[i]] = map2.GetValueOrDefault(s2[i], 0) + 1;
        }

        if (CompareMaps(map1, map2)) return true;

        for (int i = s1.Length; i < s2.Length; i++) {
            char newChar = s2[i];
            char oldChar = s2[i - s1.Length];

            // Add new char
            map2[newChar] = map2.GetValueOrDefault(newChar, 0) + 1;

            // Remove old char
            if (map2.ContainsKey(oldChar)) {
                map2[oldChar]--;
                if (map2[oldChar] == 0) map2.Remove(oldChar);
            }

            if (CompareMaps(map1, map2)) return true;
        }

        return false;
    }

    private bool CompareMaps(Dictionary<char, int> map1, Dictionary<char, int> map2) {
        if (map1.Count != map2.Count) return false;

        foreach (var kvp in map1) {
            if (!map2.ContainsKey(kvp.Key) || map2[kvp.Key] != kvp.Value) return false;
        }

        return true;
    }
}