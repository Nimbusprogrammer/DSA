class Solution {
public:
   int atmostsubarrays( vector<int> &nums , int goal){
       int l = 0 , r =0 , sum = 0 , count =0;
       if ( goal < 0){
        return 0;
       }
       while ( r < nums.size() ){
            sum += nums[r];
            while ( sum > goal){
                sum -= nums[l];
                l++;
            }
            count += r-l+1;
            r++;
       } 
          return count;//returning no of subarrays with atmost sum is goal
   }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
           return  atmostsubarrays(nums , goal)- atmostsubarrays(nums , goal-1);
    }
};