class Solution {
public:

    string getPermutation(int n, int k) {
        string ans;
        vector<int> nums(n+1);
        vector<int> factorial(n+1);
        factorial[0] =1 ;
        for ( int i = 0 ;i < n ;i++)
        {
            nums[i] = i+1;
            if ( i > 0)
            factorial[i] = factorial[i-1]*i;
            
        }
        int r = k-1;
        for ( int i = n ; i > 0 ; i--)
        {
             int blocksize =  factorial[i-1];
             int blockindex = r/blocksize;
             ans += to_string(nums[blockindex]);
             nums.erase( nums.begin() + blockindex);
             r = r%blocksize;
            
        }
        return ans;
    }
};