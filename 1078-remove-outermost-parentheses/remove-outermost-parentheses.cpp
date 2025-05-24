class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        int n = s.size();
        string ans;
        for ( int i = 0 ; i<  n ; i++)
        {
            if ( s[i] == '(')
            {
                 if ( count > 0)
                 ans.push_back(s[i]);
                 count++;

            }
            else 
            {
                count--;
                if ( count > 0)
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};