class Solution {
public:
    bool isAnagram(string s, string t) {
        //just make 2 map all freq in hashmap for all chars in both and compare.
           unordered_map<char , int > map1;
           unordered_map<char , int > map2;
           int n = s.size();
           if ( n != t.size()) return false;
           for ( int i = 0 ; i < n ;  i++)
           {
                 map1[s[i]]++;
                 map2[t[i]]++;
           }
           if ( map1 == map2)
           return true;
           else 
           return false;
    }
};