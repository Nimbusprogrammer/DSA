class Solution {
public:
    int beautySum(string s) {
        //beauty of all its substrings.
        //find all substrings with beauty and then 
        int n = s.length();
        int beauty = 0;
        for  (int i =0 ;  i < n ; i++)
        {
            vector<int> freq(26,0);
            int maxi = 0;
            
            for ( int j = i ; j < n ; j++)
            {
                      freq[s[j]-'a']++;
                      maxi = max ( maxi , freq[s[j]-'a']);
                      int mini = INT_MAX;
                      for ( int k = 0 ; k < 26 ; k++)
                      {
                        if  ( freq[k] != 0)
                        {
                            mini = min( mini , freq[k]);
                        }
                      }
                      
                      beauty += (maxi - mini);
            }
        }
        return beauty;
    }
};