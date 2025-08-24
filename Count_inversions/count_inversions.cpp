#include <vector>
using namespace std;
class Solution {
  public:
  int mergeandcount(vector<int>& arr , int low , int mid , int high )
  {
      int left = low ;
      int tempans = 0;
      int right = mid+1;
      vector<int> temp;
      while( left <= mid && right <= high)
      {
          if ( arr[left] <= arr[right])
          {
              temp.push_back(arr[left]);
              left++;
          }
          else
          {
              tempans+=  ( mid-left+1);
              temp.push_back(arr[right]);
              right++;
          }
      }
      while ( left <= mid)
      {
          temp.push_back(arr[left]);
          left++;
      }
      while( right <= high)
      {
          temp.push_back(arr[right]);
          right++;
      }
      for ( int i = 0 ; i < temp.size() ; i++)
      {
          arr[low] = temp[i];
          low++;
      }
      return tempans;
  }
  void helper(vector<int> &arr, int low , int high , int & ans )
  {
      int mid = low + (high-low)/2;
      if ( low == high)
      {
          return;
      }
      helper(arr, low , mid , ans);
      helper(arr , mid+1 , high, ans);
      ans += mergeandcount(arr, low , mid , high);
  }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int low = 0 ; 
        int high = n-1;
        int ans =0;
        helper(arr,low,high,ans);
        return ans;
    }
};