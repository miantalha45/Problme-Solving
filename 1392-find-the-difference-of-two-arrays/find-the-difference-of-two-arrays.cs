public class Solution {
    public IList<IList<int>> FindDifference(int[] nums1, int[] nums2) {
        HashSet<int> set1 = new HashSet<int>(nums1);
        HashSet<int> set2 = new HashSet<int>(nums2);

        var onlyInNums1 = new HashSet<int>(set1);
        onlyInNums1.ExceptWith(set2);

        var onlyInNums2 = new HashSet<int>(set2);
        onlyInNums2.ExceptWith(set1);

        return new List<IList<int>> {
            new List<int>(onlyInNums1),
            new List<int>(onlyInNums2)
        };
    }
}