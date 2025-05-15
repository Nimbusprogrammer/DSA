
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int students(vector<int> arr, int n, int k, int mid)
    {
        int last = arr[0];
        int student = 1;
        for (int i = 1; i < n; i++)
        {
            if (last + arr[i] > mid)
            {
                student++;
                last = arr[i];
            }
            else
                last = last + arr[i];
        }
        return student;
    }
    int findPages(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        if (k > n)
            return -1;
        int ans = -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int noofstud = students(arr, n, k, mid);
            if (noofstud <= k)
            {
                
                    ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};