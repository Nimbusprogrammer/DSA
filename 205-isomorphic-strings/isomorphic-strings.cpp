class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //use a hashmap 
        int n = s.size();
        
        unordered_map <char , char > ans;
        for ( int i = 0 ; i< n ;i++)
        {
            if ( ans.find(s[i]) == ans.end())
            {
                for ( auto & it : ans )
                {
                    if ( it.second == t[i])
                    return false;
                }
                ans[s[i]] = t[i];
            }
            else if ( ans[s[i]] != t[i])
            return false;
        }
        return true;
        
    }
};