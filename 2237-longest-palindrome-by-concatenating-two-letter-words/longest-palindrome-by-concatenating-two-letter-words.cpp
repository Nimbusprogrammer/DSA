class Solution {
public:
    int longestPalindrome(vector<string>& words)
     {
        int n = words.size();
        int ans = 0;
        bool samecentre = false;
        // create a hashmap with unique elements and then iterate over it .
        unordered_map<string , int > hashmap;//string is key and int is value
        for(int i = 0 ; i <  n; i++)
        {
            hashmap[words[i]]++;
        }
        for (auto &it : hashmap)
        {
            string req = it.first;//it gives key .(means the string)
            reverse(req.begin() , req.end());
            if ( req[0] == req[1])
            {
                int number = it.second;
                if ( number % 2 == 1)
                {
                    samecentre = true;
                    number-=1;
                }
            
                ans += (number)*2;
            }
            else if ( hashmap.find(req) != hashmap.end())
            {
                auto value = hashmap.find(req);//value is pointer so value->second use .

                ans= ans+ (min(it.second , value->second)) * 4;
                it.second = 0;
            }
            
        }
        if( samecentre)
        ans+=2;
        return ans;
    }
};