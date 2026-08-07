class Twitter {
public:
    unordered_map<int, unordered_map<int,int>> tweets; // userId -> tweetCount,tweetId
    unordered_map<int, unordered_set<int>> followings; // userId -> people they follow
    int count = 0; //time when posted
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].insert({count,tweetId});
        count++;
        followings[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > followingTweets;
        //minHeap
        for(int following : followings[userId]){
            for(auto& tweet : tweets[following]){
                followingTweets.push(tweet);
                if(followingTweets.size() > 10){
                    followingTweets.pop();
                }
            }
        }

        vector<int> feedTweetIds;

        while(!followingTweets.empty()){
            feedTweetIds.push_back(followingTweets.top().second);
            followingTweets.pop();
        }

        reverse(feedTweetIds.begin(), feedTweetIds.end());
        return feedTweetIds;

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
