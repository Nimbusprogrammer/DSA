class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        int n = s.size();
        string temp;
        string ans;
      for ( int i = 0 ; i < n ; i++ )
      {
           if ( s[i] == '(')
           {
              count++;
              temp.push_back(s[i]);
           }
           else
           {
              count--;
              temp.push_back(s[i]);
           }
           if ( count == 0)
           {
             temp.erase(temp.begin());
             temp.pop_back();
              ans= ans+temp;
            temp.clear();
           }
      }
      return ans;
    }
};