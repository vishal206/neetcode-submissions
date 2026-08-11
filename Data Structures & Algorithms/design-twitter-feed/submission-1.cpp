class Twitter {
public:
    unordered_map<int, vector<int>> tweets; // userId -> tweetIds
    unordered_map<int, unordered_set<int>> followings; // userId -> people they follow
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(tweetId);
        followings[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> followingTweetIds;
        for(int following : followings[userId]){
            for(int tweetId : tweets[following]){
                followingTweetIds.push_back(tweetId);
            }
            
        }

        return followingTweetIds;

    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId)
            return;
        followings[followerId].erase(followeeId);
    }
};
