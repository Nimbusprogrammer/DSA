#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  bool isitmax ( vector<int> stations, int mid , int k)
  {
      int count = 0;
               int n =  stations.size();

      for ( int i  = 1 ;i  < n  ; i++)
      {
            if ( stations[i] - stations[i-1] > mid)
            count += (stations[i]-stations[i-1])/mid;
      }
      if ( count <= k)// like if more stations are added in this case then the max distance will reduce probably but do not inc more than mid
      return true ;
      else 
      return false;
  }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
         double left = 0.01 ;
         int n =  stations.size();
         double ans ;
         double right =  stations[n-1] - stations[0];
         while ( left <= right)
         {
            double mid = left + (right-left)/2.0;
            if ( isitmax(stations , mid , k ))
            {
                ans = mid;
                right = mid - 0.01;
            }
            else
            {
                left = mid + 0.01;
            }
         }
         return ans;
    }
};