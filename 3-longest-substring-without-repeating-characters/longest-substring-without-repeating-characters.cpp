class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int len = 0;
        int maxlen = 0;
        unordered_map<char, int> mpp;
        while (r < n) {
            // check if the elemnt existed before
            if (mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l) {
                
                    l = mpp[s[r]] + 1;
                    len = r - l + 1;
                    maxlen = max(len, maxlen);

                    mpp[s[r]] = r;
                    r++;
                
            } else {
                len = r - l + 1;
                maxlen = max(len, maxlen);
                mpp[s[r]] = r;
                r++;
            }
        }
        return maxlen;
    }
};