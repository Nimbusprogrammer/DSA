class Solution {
public:
void powerset(vector<int>& nums , vector<int>& temp , int index , vector<vector<int>> &ans )
{
   
        ans.push_back(temp);
   
    for ( int i = index  ; i < nums.size() ; i++)
    {
        if ( i > index && nums[i] == nums[i-1])
        continue;
        temp.push_back(nums[i]);
        powerset(nums, temp , i+1  , ans);
        temp.pop_back();
        
    }
    

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0;
        sort(nums.begin() , nums.end());
        powerset( nums , temp , i , ans);
        return ans;
    }
};