class Solution {
public:
   int atmost( vector<int>& nums, int k ){
    if ( k < 0) return 0;
       int l = 0 , r= 0 , sum = 0 , count = 0;//here sum -> no of odd numbers 
       while ( r < nums.size()){
        sum += nums[r]%2 ; // adds 1 to sum if nums[r] is odd or else 0 if its equla to k then it means we got our k no of odd numbers in subarrayy 
        while ( sum > k ){
            sum -= nums[l]%2;
            l++;
        }
        count += r-l+1;
        r++;
       }
       return count;
   }
    int numberOfSubarrays(vector<int>& nums, int k) {
            return atmost(nums , k)- atmost(nums , k-1);
    }
};