class Solution {
public:
void giveperm( int index , vector<int>& nums , vector<vector<int>> &ans )
{
            if ( index == nums.size())
            {ans.push_back(nums);
            return;
            }
        for ( int i = index ; i < nums.size() ; i++)
        {
            
             swap(nums[i] , nums[index])  ;
             
              giveperm(index+1,nums, ans);
             swap( nums[i] , nums[index]);
             
           
        }

}


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        vector<int> arr(nums.size() , 0);
        int index  =0 ;
        giveperm(index ,nums, ans );
        return ans;
    }
};