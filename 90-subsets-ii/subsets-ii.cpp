class Solution {
public:
void powerset(vector<int>& nums , vector<int>& temp , int i , vector<vector<int>> &ans )
{
    if ( i == nums.size())
    {
        ans.push_back(temp);
        return ;
    }
    temp.push_back(nums[i]);
    powerset(nums, temp , i+1 , ans);
    temp.pop_back();
    int index = i+1;
    while ( index < nums.size() && nums[index ] == nums[index-1])
    {
        index++;
    }
    powerset(nums, temp , index , ans);

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