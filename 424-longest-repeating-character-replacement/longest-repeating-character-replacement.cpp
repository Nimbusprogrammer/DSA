class Solution {
public:
    int characterReplacement(string s, int k) {
        //to get longest substring with atmost k different alphabets
        int l = 0  , r = 0 , maxlen = 0;
        int maxfre =0;
        int chars;
        map < int ,int > mpp;
        while ( r < s.size()){
                    mpp[s[r]]++;
                    maxfre = 0;
                    for ( auto &p : mpp){
                         
                          maxfre = max( maxfre ,p.second);
                          
                    }
                    chars = r-l+1;
                    if ( chars - maxfre > k){
                        
                        mpp[s[l]]--;
                        if ( mpp[s[l]] == 0){
                            mpp.erase(s[l]);
                        
                        }
                        l++;
                    }
                    if ( chars-maxfre <= k){
                        maxlen = max ( maxlen , r-l+1);
                    }
                    r++;
        }
        return maxlen;
    }
};