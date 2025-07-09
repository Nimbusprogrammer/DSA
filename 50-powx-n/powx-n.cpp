class Solution {
public:
       double Power( double x , long long N)
       {
            if ( N == 0)
            return 1;
            else if ( N%2 == 0) 
            {
                N = N/2;
                return Power(x*x , N);
            }
            else
            {
                N = N/2;
                return x* Power(x*x , N);
            }
       }
    double myPow(double x, int n) {
        long long N = n ;
            if ( n < 0)
            {
                //   |INT_MIN| = |INT_MAX|+1 // SO IF
                // n == INT_MIN then if we do N = -n then it overflows as correspoding positive values goes out of bounds of int .so we convert N to long long ,then apply N = -n;
              //  N = -n; here -n overflows before assigning to N
               N = n;
               N *= -1;
                x = 1/x ;
            }
           return Power(x , N);
       

    }
};