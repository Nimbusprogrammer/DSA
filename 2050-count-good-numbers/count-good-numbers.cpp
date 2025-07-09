const long long mod = 1e9 +7;//INT_MAX IS AROUND 2 * 10^9.but ^ is bitwise operator

class Solution {
public:
    long long power ( long long num , long long n )
    {
        if ( n == 0)
        return 1;
        if ( n%2  == 0)
        {
            n /=2;
            
            long long ans = power((num*num)%mod  , n);
            
            return ans;
        }
        else 
        {
            n/=2;
            
            long long ans = num*power((num*num)%mod   , n);//num*... this also can be exceeding mod or cause integer overflow.
            ans%= mod;
            return ans;
        }
    }
    int countGoodNumbers(long long n) {
         long long even;
         long long odd  = n/2;
         if ( n% 2 == 0)
         even = n/2;
         else 
         even = n/2 +1;
         return ((power(5, even ) ) * power(4,odd))%mod;
    }
};