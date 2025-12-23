class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxindexReach = 0;
        for ( int i = 0 ;i < n ;i++){
             if ( i > maxindexReach){
                return false;
             }
             maxindexReach = max (maxindexReach , i+nums[i] );
        }
        return true;
    }
};