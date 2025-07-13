class Solution {
public:
 void power ( vector<int> &nums , vector<vector<int>> &ans , int i , vector<int> &temp)
 {
    //base case;
    if ( i == nums.size())
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    power(nums , ans , i+1, temp);
    temp.pop_back();
    power(nums , ans , i+1 , temp);
 }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        int i = 0;
        vector<int> temp;
        power(nums ,ans , i , temp );
        return ans ;

    }
};