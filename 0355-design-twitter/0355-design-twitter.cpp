class Twitter {
public:
    Twitter() {
        time = 0;
        maxFeed = 10;     
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
        if (tweets[userId].size() > maxFeed)  
            tweets[userId].pop_front();
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int> > feed;
        for (const auto& tweet : tweets[userId]) 
            feed.push(tweet);
        
        for (const auto& user : subscriptions[userId]) 
            for (const auto& tweet : tweets[user]) 
                feed.push(tweet);
            
        vector<int> result;
        while (!feed.empty()) {
            if (result.size() == maxFeed) 
                break;
            result.push_back(feed.top().second);
            feed.pop();
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            //if there is already such relation we do not need to do anything
            auto it = address.find(getKey(followerId, followeeId));
            if (it == end(address)) {
                subscriptions[followerId].push_front(followeeId);
                address[getKey(followerId, followeeId)] = begin(subscriptions[followerId]);    
            }
        }
    }

    void unfollow(int followerId, int followeeId) {
        auto key = getKey(followerId, followeeId);
        
        //delete only if it exists
        auto it = address.find(key);
        if (it != end(address)) 
            subscriptions[followerId].erase(address[key]);    
    }
private:
    int time, maxFeed;
    unordered_map<int, deque<pair<int, int>>> tweets;
    unordered_map<int, list<int>> subscriptions;
    unordered_map<long, list<int>::iterator> address;
    
    long getKey(int followerId, int followeeId) {
        return (long)followerId << 32 | (long)followeeId;
    }
};