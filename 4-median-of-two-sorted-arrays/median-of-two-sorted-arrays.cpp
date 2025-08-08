class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int left = 0, right = min(m, (m + n + 1) / 2);

        while(left <= right)
        {
            int mid1 = (left + right) / 2;
            int mid2 = (m + n + 1) / 2 - mid1;

            int maxLeft1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int minRight1 = (mid1 == m) ? INT_MAX : nums1[mid1];
            int maxLeft2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int minRight2 = (mid2 == n) ? INT_MAX : nums2[mid2];

            if (maxLeft1 > minRight2) {
                right = mid1 - 1;
            } else if (maxLeft2 > minRight1) {
                left = mid1 + 1;
            } else {
                if((m + n) % 2 == 0)
                {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
                else
                {
                    return max(maxLeft1, maxLeft2);
                }
            }
        }
        return 0;
    }
};