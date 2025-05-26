class Solution {
public:
    bool rotateString(string s, string goal) {
        //observe the ppttern is similar to before problems
        int n = s.size();
        if (n != goal.size()) return false;
        for ( int i = n-1 ; i >= 0 ; i--)
        {
            if ( s.substr(i , n-(i)) + s.substr(0 , i ) == goal ) 
            return true;
        }
        return false;
    }
};