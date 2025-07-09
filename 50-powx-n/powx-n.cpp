class Solution {
public:
    double myPow(double x, int n) {
        if ( n >= 0 )
        {
            if ( n == 0)
            return 1;
            else if ( n%2 == 0) 
            {
                n = n/2;
                return myPow(x*x , n);
            }
            else
            {
                n = n/2;
                return x* myPow(x*x , n);
            }
        }
        else 
        {
            if ( n==0)
            return 1;
            else if ( n% 2 == 0) 
            {
                n = n/2;
                return myPow (x*x , n );
            }
            else 
            {
                n= n/2;
                return 1/x * myPow(x*x, n );
            }
        }
        return 0;

    }
};