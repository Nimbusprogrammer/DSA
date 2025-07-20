class Solution {
public:
     
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        int i = 0;
        vector<int> temp;
         combosum( candidates , target , i , ans , temp);
         return ans;
    }
    void combosum(vector<int>& candidates  , int target ,  int i , vector<vector<int>> &ans , vector<int> temp)
    {
        int sum = 0;
            for( auto it : temp )
            {
                 sum += it;
            }  
            if( sum == target)
            {
                ans.push_back(temp);
                return;
            }
        if ( i > candidates.size()-1 || sum > target)
        { 
           return;
        }
         
        temp.push_back(candidates[i]);
        combosum( candidates , target , i , ans , temp );
        temp.pop_back();
        combosum(candidates , target , i+1 , ans , temp);
        
    }
    
};