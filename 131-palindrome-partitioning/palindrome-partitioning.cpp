class Solution {
public:
  bool ispalim(string temp)
  {
     int n = temp.size();
     int low = 0; 
     int high = n-1;
     while ( low < high)
     {
        if ( temp[low] != temp[high])
        return false;
        low++;
        high--;
     }
     return true;
  }
   void getallparts (vector<vector<string>> &ans , vector<string> &part , string s )
   {
        //idea is to go through all possible substrings and make substrings and if its a palindrome then only go next through recursion and when we reach empty string then its one of the answer 
        if ( s.size() == 0)
        {
            ans.push_back( part);
            return;
        }
        for ( int i = 0 ; i < s.size() ; i++)
        {
            string temp = s.substr(0,i+1);
            if ( ispalim(temp))
            {
               part.push_back(temp);
               getallparts(ans , part , s.substr(i+1) );
               part.pop_back();
            }
        }
   }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> part ;
        getallparts( ans , part , s );
             return ans;
    }
};