class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if ( n % groupSize != 0 ) return false;
        map<int,int> mpp;
        for ( int i = 0; i < n ;i++){
            mpp[hand[i]]++;
        }
        while ( !mpp.empty()){
            int cardbegin = mpp.begin()->first;
            for ( int i = 0  ; i < groupSize ; i++){
                int presentcard = cardbegin +i;
                if ( mpp.find(presentcard) == mpp.end()) 
                return false;
                mpp[presentcard]--;
                if ( mpp[presentcard] == 0)
                mpp.erase(presentcard);//this is how you erase a map value , just do mpp.erase(key);
                //also to find if that key exists do mpp.find(key);
            }
        }
            return true;
        
    }
};