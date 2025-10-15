class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0 ;
        int maxlen = 0, zeros  =0;
        while ( r < nums.size()){
            if ( nums[r] == 0){
                zeros++;
            }
            if ( zeros <= k){
                
                maxlen = max ( maxlen ,  r-l+1);
            }
            else 
            {
                if ( nums[l] == 0)
                zeros--;
                l++;
            }
            r++;
        }
        return maxlen;

    }
};