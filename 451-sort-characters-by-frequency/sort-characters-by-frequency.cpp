class Solution {
public:
    string frequencySort(string s) {
        string ans;
        int n = s.size();
        unordered_map < char , int > hashmap;
        for ( int i = 0 ; i< n;i++)
        {
            hashmap[s[i]]++;
        }
        vector< pair<char, int>> vec(hashmap.begin() , hashmap.end());
        // sorting this vector according to 2nd element of pair ie freq
        sort ( vec.begin() , vec.end() , [](auto &a , auto & b)
              {
                  return a.second > b.second;// this sorts a first if its freq is more or b first if its freq is more or equal to a .
              });
        for ( auto & it : vec)
            {
                ans += string(it.second , it.first);
            }
        return ans;

    }
};