class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string ans ;
        for ( int i = n-1 ; i >= 0 ; i--)
        {
            if (num[i]%2 != 0 )
            {
                return num.substr(0,i+1);
//while using substr( position of start(including),length of substring)
            }
        }
        return num.substr(0,0);
        //or just--> return "";
    }
};