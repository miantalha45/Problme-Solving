public class Solution {
    public string MinWindow(string s, string t) {
        if(s.Length < t.Length)
            return "";
        
        Dictionary<char, int> window = new();
        Dictionary<char, int> tMap = new();

        foreach(char c in t)
        {
            if(tMap.ContainsKey(c))
            {
                tMap[c] += 1;
            }
            else
            {
                tMap[c] = 1;
            }
        }

        int required = tMap.Count;
        int formed = 0;
        int l = 0;
        int resLen = int.MaxValue;
        int resStart = 0; 
        for(int r = 0;r < s.Length; r++)
        {
            char c = s[r];
            if(tMap.ContainsKey(c))
            {
                if(window.ContainsKey(c)) window[c]++;
                else window[c] = 1;
            }

            if(tMap.ContainsKey(c) && window[c] == tMap[c])
            {
                formed++;
            }

            while(formed == required)
            {
                if(resLen > (r - l + 1))
                {
                    resLen = r - l + 1;
                    resStart = l;
                }
                if(tMap.ContainsKey(s[l]))
                {
                    window[s[l]]--;
                    if(window[s[l]] < tMap[s[l]]) 
                    {
                        formed--;
                    }
                }
                l++;
            }
        }

        return resLen != int.MaxValue ? s.Substring(resStart, resLen) : "";
    }
}