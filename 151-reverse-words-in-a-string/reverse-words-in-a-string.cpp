class Solution {
public:
    string reverseWords(string s)
     {
        reverse(s.begin() , s.end());
        int n = s.length();
        int i = 0;//pointer to read
        int j = 0;//pointer to overwrite the string 
        while ( i < n )
        {
            while ( s[i] == ' ' && i < n )
            {
                i++;
            }
            
            //imagine a scenario where at end there are many spaces then i will point to end of array at index n but we want i < n so first while loop above will break but then if we didn't apply i< n  and only applied j > 0 condition for next "if condition" then it will add redundent " " ( space ) at end making wrong answer.
            if ( j > 0 && i  < n)
            {
                s[j]=' ';
                j++;
            }
            int start = j;
            while ( s[i] != ' ' && i < n )
            {
                s[j] = s[i];
                i++;
                j++;
            }
           //reverse function follows [ start ,end) format.
            reverse(s.begin()+start , s.begin()+j);
        }

        //j points to index after completing our required sentence making it equal to total no of elements in our string . 
        s.resize(j);
        return s;
    }
};