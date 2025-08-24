class Solution {
public:
int factorial ( int j)
{
    
    int fact = 1;
    for  (int i = 1; i <= j ; i++)
    {
        fact *= i;
    }
   return fact;
}
    string getPermutation(int n, int k) {
        string ans;
        vector<int> nums(n+1);
        for ( int i = 0 ;i < n ;i++)
        {
            nums[i] = i+1;
        }
        int r = k-1;
        for ( int i = n ; i > 0 ; i--)
        {
             int blocksize =  factorial(i-1);
             int blockindex = r/blocksize;
             ans += to_string(nums[blockindex]);
             nums.erase( nums.begin() + blockindex);
             r = r%blocksize;
            
        }
        return ans;
    }
};