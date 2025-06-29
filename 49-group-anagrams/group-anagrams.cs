public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        Dictionary<string, List<string>> map = new Dictionary<string, List<string>>();

        for(int i = 0;i < strs.Length;i++)
        {
            string str = strs[i];
            string sorted = new string(str.OrderBy(c => c).ToArray());
            if(map.ContainsKey(sorted))
            {
                map[sorted].Add(str);
            }
            else
            {
                map[sorted] = new List<string>{str};
            }
        }

        IList<IList<string>> res = new List<IList<string>>();
        foreach(var pair in map)
        {
            res.Add(pair.Value);
        }

        return res;
    }
}