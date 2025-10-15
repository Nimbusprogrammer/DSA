class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0 ;
        int maxlen = 0,len = 0 , zeros  =0;
        while ( r < nums.size()){
            if ( nums[r] == 0){
                zeros++;
            }
            if ( zeros <= k){
                len = r-l+1;
                maxlen = max ( maxlen , len);
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