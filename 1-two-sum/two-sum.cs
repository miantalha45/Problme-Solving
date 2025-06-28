public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        List<int[]> arr = new List<int[]>();

        for(int i = 0;i < nums.Length;i++)
        {
            arr.Add(new int[]{nums[i], i});
        }

        arr.Sort((arr1, arr2) => arr1[0].CompareTo(arr2[0]));

        int left = 0, right = arr.Count - 1;

        while(left < right)
        {
            int sum = arr[left][0] + arr[right][0];
            if(sum == target)
            {
                return new int[] {arr[left][1], arr[right][1]};
            }
            else if(sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return new int[0];
    }
}