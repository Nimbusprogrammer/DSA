const int MOD = 1e9+7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
         //make vectors of pse and nse and store indexes in these to as we need those indexes only
         long long ans =0;
         vector<int> pse;
         vector<int> nse;
         
         int n = arr.size();
         stack<int> st;
         for ( int i=0 ; i<= n -1 ; i++)
         {
               while ( !st.empty() &&  arr[st.top()] >= arr[i])
               st.pop();
               if ( !st.empty())
               pse.push_back(st.top());
               else 
               pse.push_back(-1);
               st.push(i);

         }
         //st = stack<int>();//empties the existing stack with O(N) 
         stack<int> st2;
         for ( int i=n-1 ; i >= 0 ; i--)
         {
               while ( !st2.empty() &&  arr[st2.top()] > arr[i])
               st2.pop();
               if ( !st2.empty())
               nse.push_back(st2.top());
               else 
               nse.push_back(-1);
               st2.push(i);

         }
         reverse(nse.begin() , nse.end());
         //by now nse and pse are of size n and they only store indexes 
         for ( int i = 0  ; i < n ; i++)
         {
            long long left = i - pse[i];
            long long right = (nse[i] == -1 ? (n-i) : (nse[i]-i));
            long long contrib = ((long long )arr[i] *left)%MOD;
            contrib = (contrib*right)%MOD;
            //contrib *= right ;
            //contrib %= MOD;
            ans = (ans+ contrib)%MOD;
         }
          return (int)ans;
    }
};