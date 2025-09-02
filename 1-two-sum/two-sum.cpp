class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         int n = nums.size();
         unordered_map<int , int> hashmap;
         for ( int i = 0 ; i < n ;i++)
         {
            int need = target-nums[i];
            if ( hashmap.find(need) != hashmap.end())
            {
                return {hashmap[need] , i};
            }
            hashmap[nums[i]] = i;//storing current number as key

         }
         return {-1};

    }
};