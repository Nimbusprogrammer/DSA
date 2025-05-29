class Solution {
public:
    int maxDepth(string s) {
        int ans = INT_MIN;
        int n = s.length();
        int temp = 0;
        for (int i = 0 ; i < n ; i++)
            {
                if ( s[i] == '(')
                {
                    temp++;
                }
                else if ( s[i] ==')')
                {
                    temp--;
                }
                ans = max( ans , temp);
            }
        return ans;
    }
};