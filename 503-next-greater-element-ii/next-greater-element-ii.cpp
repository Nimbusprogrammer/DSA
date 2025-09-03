class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //method 2 : looping forward and storing indexes in stack 
        stack <int> st;
        int n = nums.size();
        vector<int> ans(n , -1);
        for ( int i = 0 ; i < 2*n-1 ; i++)
        {
            int curr = nums[i%n];
            while ( !st.empty() && nums[st.top()] < curr)
            {
                ans[st.top()] = curr;
                st.pop();
            }
            if (i < n )
            {
                st.push(i);
            }
        }
        return ans;
    }
};