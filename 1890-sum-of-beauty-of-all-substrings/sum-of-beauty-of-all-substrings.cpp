class Solution {
public:
  
   int minfreq (unordered_map <char , int> & freqmap)
   {
       int ans = INT_MAX;
       for ( auto it : freqmap)
       {
        if ( it.second != 0)
        {
            ans = min( ans , it.second);
        }
       }
       return ans;

   }
    int beautySum(string s) {
        //beauty of all its substrings.
        //find all substrings with beauty and then 
        int n = s.length();
        int beauty = 0;
        for  (int i =0 ;  i < n ; i++)
        {
            unordered_map <char , int > freqmap;
            int maxi = 0;
            int mini = INT_MAX;
            for ( int j = i ; j < n ; j++)
            {
                      freqmap[s[j]]++;
                      maxi = max ( maxi , freqmap[s[j]]);
                      mini = minfreq(freqmap);
                      
                      beauty += (maxi - mini);
            }
        }
        return beauty;
    }
};