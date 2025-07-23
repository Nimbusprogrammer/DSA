class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0;
        
        sort(candidates.begin() , candidates.end());
        combosum(candidates ,target,ans , temp , i );
        return ans;
    }
    void combosum( vector<int>& candidates, int target ,vector<vector<int>>& ans ,vector<int>& temp , int i  )
    {
       //base 
       if ( target == 0)
       {
          ans.push_back(temp);
          return;
       }
       for ( int index = i ; index < candidates.size() ; index++)
       {
           if ( index > i && candidates[index] == candidates[index-1]) 
           continue;
           if ( candidates[i] > target )
           return;
           temp.push_back(candidates[index]);
           combosum(candidates , target-candidates[index] , ans , temp , index+1);
           temp.pop_back();
       }
    
        
    }
};