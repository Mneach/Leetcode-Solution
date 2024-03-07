class Tweet {
public:
        
    int userId;
    int tweetId;
    int tweetNumber;
    
    Tweet(int uid, int tid, int tnum) {
        userId = uid;
        tweetId = tid;
        tweetNumber = tnum;
    }
};

class Twitter {
public:
    
    int currentTweetNumber;
    vector<Tweet> vt;
    unordered_map<int,unordered_map<int, bool>> ump;
    
    Twitter() {
        currentTweetNumber = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        currentTweetNumber++;
        Tweet tweet(userId, tweetId, currentTweetNumber);
        vt.push_back(tweet);
    }
    
    vector<int> getNewsFeed(int userId) {
        
        vector<int> res;
        
        int count = 0;
        for(int i = vt.size() - 1; i >= 0; i--){            
            Tweet tweet = vt[i];
            
            if(tweet.userId == userId){
                res.push_back(tweet.tweetId);
                count++;
            }else if(ump[userId][tweet.userId] == true){
                res.push_back(tweet.tweetId);
                count++;
            }
            
            if(count == 10) break;
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        ump[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        ump[followerId][followeeId] = false;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */