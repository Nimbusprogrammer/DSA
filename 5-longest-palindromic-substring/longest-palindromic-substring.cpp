class Solution {
public:
    string longestPalindrome(string s) {
        // for each palindrome lets consider 2 types of palindromes like  "aiia" evenlenth sub palindrome
        //and "tayat" odd length palindrome .
        if ( s.length() <= 1) return s;
        int n = s.size();
        string ans;
        // to check all odd length palindromes .
        for (int i= 1; i < n;i++)
        {
            int low = i;
            int high = i;
            while (  low >= 0  && high <= n-1 && s[low] == s[high] )//first check low and high and then check s[low] && s[high] to avoid int overflow
            {
                low--;
                high++;
            }
            int templength = (high-1-(low+1) + 1);//length of that palindrome.
            if ( templength > ans.length())
            {
                 ans = s.substr(low+1 ,templength);
            }

                                 
        } 
        for ( int i = 0 ; i< n ; i++)
        {
            int low = i-1;
            int high = i;
            while ( low >= 0 && high <= n-1 && s[low ] == s[high])
            {
                low--;
                high++;
            }
            int templength = (high-1-(low+1) + 1);//length of that palindrome.
            if ( templength > ans.length())
            {
                 ans = s.substr(low+1 , templength);
            }

        }
        return ans;
    }
};