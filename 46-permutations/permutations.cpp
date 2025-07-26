class Solution {
public:
void giveperm( vector<int>& nums , vector<vector<int>> &ans, vector<int> &temp , vector<int> &arr)
{
        if ( temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for ( int i = 0 ; i < nums.size() ; i++)
        {
            if( arr[i] == 0)
           {
           temp.push_back(nums[i]);
           arr[i] = 1;
           giveperm(nums, ans, temp,arr);
           temp.pop_back();
           arr[i] = 0;
           }
        }

}


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        vector<int> arr(nums.size() , 0);
        vector<int> temp ;
        giveperm(nums, ans ,  temp,arr);
        return ans;
    }
};