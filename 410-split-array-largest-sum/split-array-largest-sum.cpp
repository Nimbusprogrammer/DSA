class Solution {
public:
    int maxsubarrays( vector<int> nums , int k , int n  , int mid)
    {
        int last = nums[0];
         int num = 1;
        for ( int i = 1 ; i  < n ; i++)
        {
              if ( last + nums[i] > mid)
              {
                last = nums[i];
                num++;
              }
              else
              last += nums[i];
        }
        return num;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin() , nums.end());
        int n = nums.size();
        int ans = -1;
        int right = accumulate(nums.begin() , nums.end() , 0);
        while ( left <= right)
        {
           int mid = ( left + right)/2;
           int number = maxsubarrays(nums ,  k , n  ,  mid);
           if ( number <= k)
           {
             ans = mid;
             right = mid-1;
           }
           else 
           left = mid+1;
        }
        return ans ;
    }
};