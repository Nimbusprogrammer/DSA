class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        vector<int> ans;
        while ( low <= high)
        {
            int mid = (low +high)/2;
            int maxnum= INT_MIN;
            int maxnumrow;
            for ( int j = 0; j < n;j++)
            {
                if ( mat[j][mid] > maxnum )
                {
                    maxnum = max ( maxnum , mat[j][mid]);
                    maxnumrow = j;
                }
            }
            //so in the coloumn with with index = mid the largest element is at maxnumrowth row.
            int left = mid-1 >= 0 ? mat[maxnumrow][mid-1] : -1;
            int right = mid +1 <= m-1 ? mat[maxnumrow][mid+1] : -1;
            if ( mat[maxnumrow][mid] > left && mat[maxnumrow][mid] > right)
            {
                ans = {maxnumrow , mid};
                return ans;
            }
            else if ( mat[maxnumrow][mid] < left)
            {
                high = mid-1;
            }
            else 
            low = mid+1;
        }
        return {-1,-1};
    }
};