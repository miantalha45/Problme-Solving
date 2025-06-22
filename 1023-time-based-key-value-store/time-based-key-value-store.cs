public class TimeMap {
    Dictionary<string, List<Tuple<string, int>>> map;
    public TimeMap() {
        map = new Dictionary<string, List<Tuple<string, int>>>();
    }
    
    public void Set(string key, string value, int timestamp) {
        if (map.ContainsKey(key))
        {
            map[key].Add(new Tuple<string, int>(value, timestamp));
        }
        else
        {
            map[key] = new List<Tuple<string, int>> { new Tuple<string, int>(value, timestamp) };
        }
    }
    
    public string Get(string key, int timestamp) {
        if(!map.ContainsKey(key))
        {
            return "";
        }

        var value = map[key];
        int l = 0, r = value.Count - 1;
        string res = "";
        while(l <= r)
        {
            int mid = (l + r) / 2;
            int val = value[mid].Item2;
            if(val == timestamp)
            {
                return value[mid].Item1;
            }
            else if(val < timestamp)
            {
                l = mid + 1;
                res = value[mid].Item1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return res;
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.Set(key,value,timestamp);
 * string param_2 = obj.Get(key,timestamp);
 */