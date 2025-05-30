class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int n = s.length();
        int count = 1;
        int sign = 1;
        int i = 0;
          while ( i < n && s[i] ==' ')
          i++;
          if ( i < n  && (s[i] == '-' || s[i] == '+'))
          {
            if ( s[i] == '-')
            sign = -1;
            i++;
          }
          
            while ( i < n && isdigit(s[i]))
            {
                ans = ans * 10 + (s[i]-'0');//making characters into integers
                if ( sign * ans >= INT_MAX )
                return INT_MAX;
                else if ( sign * ans <= INT_MIN)
                return INT_MIN;
                i++;
            }

        
       return (int)(ans*sign);

    }
};