class Twitter {
public:
unordered_map<int , unordered_set<int>> followmap;//follower usesrId -> followees userId
unordered_map< int , vector<pair<int,int>>> tweets;//int is our userid and for each userId we are keepign a priorityQueue in the form of vector<pair<int,int>> where the values are sttored in pq in the order or first value of pair ie timestamp
int timestamp = 0;
    Twitter() {  
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++ , tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
           priority_queue< vector<int>> pq;// my pq needs to have {timeStamp to maxheap pq, tweetId to update to feed , userId to find all his tweetIds vector , index to immediately get his next most recent tweetId}
           vector<int> feed ;
           if ( tweets[userId].size() )
           {
            int idx = tweets[userId].size()-1;//last tweet
            pq.push({tweets[userId][idx].first , tweets[userId][idx].second , userId , idx});
           }
           //pushing lastest tweets of followees 
           for ( int followee : followmap[userId]){
            if ( tweets[followee].size()){
                int idx = tweets[followee].size()-1;
                pq.push({
                    tweets[followee][idx].first , tweets[followee][idx].second , followee , idx
                });
            }
           }
           //extracting top 10 newest tweets
           while ( !pq.empty() && feed.size() < 10){
            // taking newest timestamp
                 vector<int> top = pq.top();
                 pq.pop();
                 int timestamp = top[0];
                 int tweetId = top[1];
                 int userId = top[2];
                 int idx = top[3];
                 feed.push_back(tweetId);
                 //pushing users next most recent tweet into pq if its present 
                 if ( idx >0 ){
                    idx--;
                    pq.push({
                        tweets[userId][idx].first , tweets[userId][idx].second , userId , idx
                    });
                 }
           }
           return feed;

    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
    }
};//insert and erase are on sets operations 

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */