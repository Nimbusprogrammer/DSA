class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // BRUTE FORCE : 2-POINTER TECHNIQUE.
        int n = nums1.size();
        int m = nums2.size();
        int mid1;
        int mid2;
        int midindex1 = (m + n) / 2;
        int midindex2 = (m + n) / 2 - 1;

        int left = 0;
        int realindex = 0;
        int right = 0;
        double answer;
        while (left <= n - 1 && right <= m - 1) {
            if (nums1[left] <= nums2[right]) {
                if (realindex == midindex1) {
                    mid1 = nums1[left];
                }
                if (realindex == midindex2)
                    mid2 = nums1[left];
                left++;
                realindex++;
            } else {
                if (realindex == midindex1) {
                    mid1 = nums2[right];
                }
                if (realindex == midindex2)
                    mid2 = nums2[right];
                right++;
                realindex++;
            }
        }
        while (left <= n - 1) {
            if (realindex == midindex1) {
                mid1 = nums1[left];
            }
            if (realindex == midindex2)
                mid2 = nums1[left];
            realindex++;
            left++;
        }
        while (right <= m - 1) {
            if (realindex == midindex1) {
                mid1 = nums2[right];
            }
            if (realindex == midindex2)
                mid2 = nums2[right];
            right++;
            realindex++;
        }
        if ((m + n) % 2 == 0) {
            answer =(double) (mid1 + mid2) / 2;
        } else
            answer = mid1;
        return answer;
    }
};