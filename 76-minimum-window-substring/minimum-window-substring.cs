public class Solution {
    public string MinWindow(string s, string t) {
        if (s.Length < t.Length || string.IsNullOrEmpty(t)) return "";

        Dictionary<char, int> countT = new Dictionary<char, int>();
        Dictionary<char, int> window = new Dictionary<char, int>();

        foreach (char c in t) {
            if (countT.ContainsKey(c)) countT[c]++;
            else countT[c] = 1;
        }

        int have = 0, need = countT.Count;
        int left = 0;
        int resLen = int.MaxValue;
        int resStart = 0; 

        for (int right = 0; right < s.Length; right++) {
            char c = s[right];
            if (window.ContainsKey(c)) window[c]++;
            else window[c] = 1;

            if (countT.ContainsKey(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((right - left + 1) < resLen) {
                    resLen = right - left + 1;
                    resStart = left;
                }

                char leftChar = s[left];
                window[leftChar]--;
                if (countT.ContainsKey(leftChar) && window[leftChar] < countT[leftChar]) {
                    have--;
                }
                left++;
            }
        }

        return resLen != int.MaxValue ? s.Substring(resStart, resLen) : "";
    }
}