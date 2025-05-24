class Solution {
public:
    string reverseWords(string s) 
           
    {
        string ans;
        reverse(s.begin() , s.end());
        int n = s.size();
        int count =1;
        for ( int i = 0 ; i < n ; i++)
        {
            string temp;
            while ( s[i] != ' ' && i < n )
            {
               temp.push_back(s[i]);
               i++;
            }
            reverse(temp.begin() , temp.end());
            if (  temp.size() > 0)
            {
                if ( count == 1)
                {
                    ans += temp;
                    count--;
                }
                else
                ans = ans + " " + temp;
            }
        }
        return ans;
    }
};