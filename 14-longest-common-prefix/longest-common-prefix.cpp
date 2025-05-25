class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //brute force Tc= O(n*m) n = size of strs , m = length of first string
        int n  = strs.size();
        string ans ;
        string prefix = strs[0];
        bool pushthat = true;
        for ( int i = 0 ; i <  prefix.length()  ; i++)
        {
            for ( int j = 1; j < n ; j++)
            {
                if ( prefix[i] != strs[j][i])
                {
                    pushthat = false;
                    return ans;
                }
            }
            //after checking that element from prefix string with whole other strings elements now add it to ans
            if ( pushthat)
            ans.push_back(prefix[i]);
        }
        return ans;

    }
};