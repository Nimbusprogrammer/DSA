#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  bool isitmax ( const vector<int> &stations, double mid , int k)
  {
      int count = 0;
      int n =  stations.size();
      for ( int i  = 1 ;i  < n  ; i++)
      {
            if ( stations[i] - stations[i-1] > mid)
            count += ceil((stations[i]-stations[i-1])/mid)-1;
            // when dis =10 and mid =2.5 required stations = 3 to create 4 gaps each of dis = maxdis ie 2.5 but if we use without
            //ceil then 10/2.5 =4 which is wrong . so to get these cases where dis = exactly the max distance values 
            // ceil helps us .
      }
      if ( count <= k)// like if more stations are added in this case then the max distance will reduce probably but do not inc more than mid
      return true ;
      else 
      return false;
  }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
         double left = 0.000001 ;// for floating point numbers generally we take 10^-6 for precision to get upto 2 decimal 
         //values correctly in final answer.
         int n =  stations.size();
         double ans ;
         double right =  stations[n-1] - stations[0];
         while ( left <= right)
         {
            double mid = left + (right-left)/2.0;
            if ( isitmax(stations , mid , k ))
            {
                ans = mid;
                right = mid - 0.000001;
            }
            else
            {
                left = mid + 0.000001;
            }
         }
         return  (round(ans*100))/100;
    }
};