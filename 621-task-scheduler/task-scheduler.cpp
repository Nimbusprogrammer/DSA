class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         unordered_map <char,int> mpp;
         for ( int i = 0 ; i< tasks.size() ;i++){
            mpp[tasks[i]]++;
         }
         //create a maxheap of freq to find which is more freq and that has to be prioritized
         priority_queue<int> freq;
         for ( auto& it : mpp){
            freq.push(it.second);
         }
         //now run the while loop 
         int time = 0 ;
         while ( !freq.empty()){
             // each step need n+1 cycles to happen 
             int i = 0 ; 
             int cycle = n+1;
             vector<int> temp;//to temporarily store frequencies that need to update later after below while loop which fills n+1 spaces 
             while ( i < cycle && !freq.empty()){
                 int cnt = freq.top();
                 cnt--;
                 freq.pop();
                 if ( cnt > 0)
                 temp.push_back(cnt);
                 
                 i++;
                 time++;
             }
            
             for ( auto it : temp){
                      freq.push(it);
             }
             if ( freq.empty())// we don't want to add extra time even after the entire elements completed like it will just add extra empty slots if any at the end so check
             break;
             else
                time += cycle-i;// we can do it after knowing the future elements are going to come in next iterations , like we are here filling void time slots , we dont' want to add any void time slots after we did add all given elements so check if heap is empty after refilling with above for loop.
             
         }
         return time;

    }
};