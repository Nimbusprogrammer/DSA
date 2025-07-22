class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0;
        int sum =0;
        sort(candidates.begin() , candidates.end());
        combosum(candidates ,target,ans , temp , i , sum);
        return ans;
    }
    void combosum( vector<int>& candidates, int target ,vector<vector<int>>& ans ,vector<int>& temp , int i , int sum )
    {
        if ( sum > target)
        return;
        if ( i == candidates.size())
        {
            if ( sum == target)
            {
                ans.push_back(temp);
                
            }
            return;
        }
        temp.push_back(candidates[i]);
        sum+=candidates[i];
        combosum(candidates ,target,ans , temp , i+1 , sum);
        int index = i+1;
        sum-=candidates[i];
        temp.pop_back();
        while ( index < candidates.size() && candidates[index] == candidates[i] )
        {
              index++;
        }
        combosum(candidates ,target,ans , temp , index , sum);
        
    }
};