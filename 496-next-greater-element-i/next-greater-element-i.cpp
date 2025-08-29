class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            vector<int> temp;
            int n = nums1.size();
            vector<int> ans;
            vector<int> output;
            stack<int> st;
            int m = nums2.size();
            for ( int i = 0 ; i < n ; i++)
            {
                for ( int j = 0 ; j < m ; j++)
                {
                    if ( nums1[i] == nums2[j])
                    {
                          temp.push_back(j);
                          break;
                    }
                }
            }
            for ( int j = m-1 ;j >= 0 ; j--)
            {
                
                   
                
                while( !st.empty() && st.top() <= nums2[j])
                {
                    st.pop();
                }
                //result for the next big num should be checked after removing smaller elements from stack
                 if ( !st.empty() )
                    {
                        if ( st.top() > nums2[j])
                    output.push_back(st.top());
                    else 
                    output.push_back(-1);
                    }
                    else 
                    output.push_back(-1);

                if ( st.empty() || nums2[j] < st.top())
                {
                    st.push(nums2[j]);
                }
            }
            reverse(output.begin() , output.end());
            for ( int i = 0 ; i < n ; i++)
            {
               ans.push_back(output[temp[i]]);
            }
            return ans;
    }
};