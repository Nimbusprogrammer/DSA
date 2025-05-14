
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k)
     {
        int n = arr.size();
        // //brute force
        // for ( int i = 0 ; i  < n ; i++ ) 
        // {
        //     if ( arr[i] <= k ) {
        //         k++;
        //     }
        //     else 
        //     {
        //         break;
        //     }
        // }
        // return k;
         //optimal solution
         int left = 0 ; int right = n-1;
        while ( left <= right ) 
        {
               int mid = (left + right)/2;
               if ( arr[mid ] - (mid + 1) < k ) 
               {
                   left = mid + 1;
               }
               else 
               {
                   right = mid - 1;
               }
        }
        return (right+1+k);

    }
};

