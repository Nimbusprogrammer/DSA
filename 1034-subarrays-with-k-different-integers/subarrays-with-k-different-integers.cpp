class Solution {
public:
int atmost(vector<int>& nums, int k ){
    if ( k <= 0){
        return 0;
    }
     map<int , int > mpp;
     int l = 0 , r= 0 , count = 0;
     while ( r < nums.size()){
           mpp[nums[r]]++;
           while ( mpp.size() > k ){
                 mpp[nums[l]]--;
                 if ( mpp[nums[l]] == 0)
                 mpp.erase(nums[l]);
                 l++;
           }
           count += r-l+1;
           r++;
           
     }
     return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
             //Find no of subarrays with atmost k distinct then atmost k-1 , after that atmost k- atmsot k-1 wallah will give you exactly those subarrrasy with k elements 
             return atmost(nums , k ) - atmost(nums , k-1);
    }
};