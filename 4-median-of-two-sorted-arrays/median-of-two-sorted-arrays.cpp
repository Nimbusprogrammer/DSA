class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n1 = nums1.size();
            int n2 = nums2.size();
            if ( n1> n2) return findMedianSortedArrays( nums2 , nums1);
            int left = ( n1+n2)/2;//these are the number of numbers that are on the 
            //left side of merged array
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            //binary search on the number of digits that can be taken from the samllest array to form the left side of merged array.
            int low = 0;//nothing 
            int high = n1;
            while ( low <= high)
            {
                int mid1 = (low+high)/2;//no of numbers from nums1 that form left side of merged array.
                int mid2 = left - mid1;
                if ( mid1-1 >= 0)  l1= nums1[mid1-1];
                else l1 = INT_MIN;
                if ( mid2-1  >= 0)  l2 =  nums2[mid2-1];
                else l2 = INT_MIN;
                if (  mid1 < n1) r1 = nums1[mid1];
                else r1 = INT_MAX;
                if ( mid2 < n2) r2 = nums2[mid2];
                else r2 = INT_MAX;
                if (l1 <= r2 && l2 <= r1)
                {
                    if ( (n1+n2)%2 == 0)
                    return ( max(l1,l2) + min(r1,r2))/2.0;
                    else 
                    return min(r1,r2);
                }
                else if ( l1 > r2 )
                high = mid1-1;
                else 
                low = mid1+1;
            }
            return 0;
                   
    }
};