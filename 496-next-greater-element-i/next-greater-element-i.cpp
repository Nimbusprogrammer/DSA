class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         int n = nums1.size();
         int m = nums2.size();
         vector<int> ans;
         //to maintain hashmap key(element from nums2), value(its corresponding ngm)
         unordered_map<int , int > nextgreater;
         stack<int> st;
         for ( int i = m-1 ; i >= 0 ; i--)
         {
              while( !st.empty() && st.top() <= nums2[i])
              {
                st.pop();
              }
              if ( st.empty() || st.top() > nums2[i])
              {
                if ( !st.empty())
                  nextgreater[nums2[i]] = st.top();
                  else 
                  nextgreater[nums2[i]] = -1;
                  
                  
              }
              st.push(nums2[i]);
         }
         for ( int i = 0 ; i < n ;i++)
         {
            ans.push_back(nextgreater[nums1[i]]);
         }
         return ans;
    }
};