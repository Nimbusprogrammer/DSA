class Solution {
public:
    int romanToInt(string s) {
        
        int n = s.length();
        vector<int> values(n);
        for ( int i = 0 ; i < n ;i++ )
            {
                if ( s[i] == 'I')
                    values[i] = 1;
                if ( s[i] == 'V')
                    values[i] = 5;
                if ( s[i] == 'X')
                    values[i] = 10;
                if ( s[i] == 'L')
                    values[i] = 50;
                if ( s[i] == 'C')
                    values[i] = 100;
                if ( s[i] == 'D')
                    values[i] = 500;
                if ( s[i] == 'M')
                    values[i] = 1000;
            }
            int ans = 0;
            if ( n == 1 )
            ans = values[0];
            else 
            {for ( int i = 0; i< n ;i++)
            {
                if ( i == n-1)
                ans += values[i];
                else if ( values [i] < values[i+1])
                {
                    ans -= (values[i]);
                }
                else 
                ans += (values[i]);
            }}
            return ans;
    }
};