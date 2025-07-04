class Solution {
public:

    int myfunction (string s , int i ,  int n , long long num , int sign)
    {
        //BASE CASE
         if ( i >= n || !isdigit(s[i]) || num*sign >= INT_MAX || num*sign <= INT_MIN)
         return clamp( num*sign, (long long)INT_MIN , (long long)INT_MAX );
        //PROCESS
        num = num*10 + (s[i]-'0');
        
        i++;
        //num *= sign; don't do this as sing flips in every recursive step . just change the sign in the end only.
        return myfunction(s , i  , n  , num , sign);
    }
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        long long num = 0;
         int sign =1 ;
         while ( !isdigit(s[i]))
         {
            if ( isspace(s[i]))
            i++;
            else if ( s[i] == '-' || s[i] == '+')
            {
                if (  s[i] == '-')
                sign = -1;
                else 
                sign = +1;
                i++;
                break;
            }
            else 
            break;
         }
        int ans = myfunction(s , i , n , num , sign);
        return ans;
    }
};