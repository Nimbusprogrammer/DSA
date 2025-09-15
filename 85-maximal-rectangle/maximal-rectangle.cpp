class Solution {
public:
//pse and nse containing indexes only
vector<int> NSE ( vector<int> &prefixsum){
    int n = prefixsum.size();
     vector<int> nse(n,n);
     stack<int> st;
     for ( int i = n-1; i >=0 ; i--){
          while ( !st.empty() && prefixsum[st.top()] >= prefixsum[i]){
            st.pop();
          }
          if ( !st.empty())
          nse[i] = st.top();
          st.push(i);
     }
     return nse;
 }
 vector<int> PSE ( vector<int> &prefixsum){
    int n = prefixsum.size();
     vector<int> pse(n,-1);
     stack<int> st;
     for ( int i = 0 ; i < n ; i++){
          while ( !st.empty() && prefixsum[st.top()] >= prefixsum[i]){
            st.pop();
          }
          if ( !st.empty())
          pse[i] = st.top();
          st.push(i);
     }
     return pse;
 }
int largestrec( vector<int> &prefixsum){
       vector<int> pse = PSE(prefixsum);
       vector<int> nse = NSE (prefixsum);
       int n = prefixsum.size();
       int area =0;
       int maxarea = 0;
       for ( int i = 0 ; i <n  ;i++){
             int  L = pse[i];//pse & nse vectors contain indexes 
             int R = nse[i];
             area = (R-L -1)* prefixsum[i];//to find area formed by rectangle of this side .
             maxarea= max ( maxarea , area);
       }
       return maxarea;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
               //make a 2d matrix of all prefix sums , then follow the largest rectangle in histogram method and find area max  and do it 
               int sum = 0;
               
               int n = matrix.size();//rows
               int m = matrix[0].size();//coloumns
               vector<vector<int>> prefixsum( n , vector<int>(m,0));
               for ( int j = 0 ; j < m; j++){
                 sum =0;//reset for every coloumn 
                      for ( int i = 0 ; i< n ; i++) {
                                sum += matrix[i][j] -'0';//char to int conversion do subtract '0' only 
                                 if ( matrix[i][j] == '0')
                                 sum = 0;
                                 prefixsum[i][j] = sum;
                      }      
               }
        //use the logic of largest rectangle while each row of this prefixsum is like an array of all heights until that particular row 
        int area = 0;
        int maxarea = 0;
        for ( int i = 0 ; i < n ; i++){
                area = largestrec(prefixsum[i]);
                maxarea = max (maxarea , area);
                
        }
        return maxarea;

    }
};