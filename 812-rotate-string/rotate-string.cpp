class Solution {
public:
    bool rotateString(string s, string goal) {
        //observe the ppttern is similar to before problems
        int n = s.size();
        if (n != goal.size()) return false;
        if ( (s+s).find(goal) != string::npos) //gives index where goal string starts in s+s string.
        return true;
        else 
        return false;
    }
};