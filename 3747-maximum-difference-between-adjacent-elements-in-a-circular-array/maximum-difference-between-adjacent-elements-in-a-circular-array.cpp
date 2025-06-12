class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxdiff =abs(nums[0]-nums[n-1]);
        for ( int i = 0 ; i< n-1 ; i++)
        {
           
                maxdiff = max(abs(nums[i]- nums[i+1]) , maxdiff);
            
        }
        
        return maxdiff;
    }
};