class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // brute force method
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        // bool present = false; this has to be updated everytime inside for loop and should start with false until updated
        int index; // to keep track of the index of its position int nums 2 of
                   // element of nums1
        for (int i = 0; i < n; i++)
         {
            bool present = false;
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    index = j;
                    present = true;
                    break;
                }
            }
            if (present) // search for next greatest element
            {
                for (int k = index ; k < m; k++) //start k with index as if index is direclty last element like in nums1 2,1,3 if and 3 is at last of nums2 then we should not skip it and fill -1 as no other number after 3 is greater than 3 to its right side .
                {
                    if (nums2[k] > nums2[index])
                    {
                        ans.push_back(nums2[k]);
                        break;
                    }
                    else if (k == m-1) {
                        ans.push_back(-1);
                    }
                }
            }
        }
        return ans;
    }
};