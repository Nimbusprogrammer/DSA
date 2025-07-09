const long long mod = 1e9 +7;//INT_MAX IS AROUND 2 * 10^9.but ^ is bitwise operator

class Solution {
public:
    long long power ( long long num , long long n )
    {
        if ( n == 0)
        return 1;
        long long half = power ( num , n/2)%mod;
        if ( n%2 == 0)
        {
             return (half *half)%mod;
        }
        else 
        return (half* half*num)%mod;
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