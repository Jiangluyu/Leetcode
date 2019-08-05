class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int mid = (len1 + len2 + 1) / 2;
        if (len1 > len2){
            nums1.swap(nums2);
            swap(len1, len2);
        }

        int start = 0;
        int end = len1;

        while (start <= end) {
            int i = (start + end) / 2;
            int j = mid - i;
            if (i < end && nums2[j-1] > nums1[i])
                start = i + 1;
            else if (i > start && nums1[i-1] > nums2[j])
                end = i - 1;
            else {
                int maxLeft = 0;
                if (i == 0)
                    maxLeft = nums2[j-1];
                else if (j == 0)
                    maxLeft = nums1[i-1];
                else
                    maxLeft = max(nums1[i-1], nums2[j-1]);

                if ((len1 + len2) % 2 == 1)
                    return maxLeft;

                int minRight = 0;
                if (i == len1)
                    minRight = nums2[j];
                else if (j == len2)
                    minRight = nums1[i];
                else
                    minRight = min(nums1[i], nums2[j]);
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};
