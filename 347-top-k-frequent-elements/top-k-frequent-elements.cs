public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {
        if(nums.Length == 1)
            return nums;

        Dictionary<int, int> map = new Dictionary<int, int>();

        foreach(int n in nums)
        {
            if(map.ContainsKey(n))
            {
                map[n]++;
            }
            else
            {
                map[n] = 1;
            }
        }

       List<int>[] buckets = new List<int>[nums.Length + 1];

        foreach(var pair in map)
        {
            int freq = pair.Value;
            if (buckets[freq] == null) {
                buckets[freq] = new List<int>();
            }
            buckets[freq].Add(pair.Key);
        }

        List<int> res = new List<int>();
        for(int i = buckets.Length - 1;i >= 0;i--)
        {
            if(buckets[i] != null)
            {
                res.AddRange(buckets[i]);
            }
        }

        return res.Take(k).ToArray();
    }
}