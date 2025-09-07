class Solution {
public:
    long long sumMax(vector<int>& nums) {
        // find nme and pge stack ...
        stack<int> st;
        long long ans = 0;
        int n = nums.size();
        vector<int> pge(n);
        vector<int> nge(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pge[i] = st.top();
            } else
                pge[i] = -1;
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if (!st.empty()) {
                nge[i] = st.top();
            } else
                nge[i] = n;
            st.push(i);
        }
        // now we got both pge and nge indexes in vectors pge nad nge resp
        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i]-i;
            ans += ( left * right *1LL * nums[i]);
        }
        return ans;
    }
    long long sumMin( vector<int> &nums)
    {
        stack<int> st;
        long long ans = 0;
        int n = nums.size();
        vector<int> pse(n);
        vector<int> nse(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            } else
                pse[i] = -1;
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if (!st.empty()) {
                nse[i] = st.top();
            } else
                nse[i] = n;
            st.push(i);
        }
        // now we got both pse and nse indexes in vectors pse nad nse resp
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i]-i;
            ans += ( left * right *1LL * nums[i]);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        // basically just find all subarray maximums and minimums and then
        // subtract them
        long long ans = sumMax(nums) - sumMin(nums);
        return ans;
    }
};