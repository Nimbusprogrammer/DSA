#include <bits/stdc++.h>
using namespace std;

class Solution 
{
  public:
    int minTime(vector<int>& arr, int k)
     {
        // code here
         int left = *max_element(arr.begin() , arr.end()) ; 
        int n = arr.size();
        int ans =-1;
        int right = accumulate ( arr.begin() , arr.end() ,0);
        while ( left <= right)
        {
            int mid = (left + right)/2;
            int last = arr[0];
            int painters = 1;
            for ( int i = 1 ; i < n ; i++)
            {
                if ( last + arr[i] > mid)
                {
                    last = arr[i];
                    painters++;

                }
                else 
                last += arr[i];
            }
            if ( painters <= k)
            {
                ans = mid;
                right = mid-1;
                
            }
            else 
            left = mid+1;
        }
        return ans;
        // return minimum ti
    }
};
