class Twitter {
    int time = 0;
    unordered_map<int, vector<pair<int,int>>> tweets;  // userId -> [(ts, tweetId)]
    unordered_map<int, set<int>> following;            // userId -> {followees}

public:
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> all;  // collect all tweets

        // add own tweets
        for (auto& t : tweets[userId])
            all.push_back(t);

        // add followees' tweets
        for (int uid : following[userId])
            for (auto& t : tweets[uid])
                all.push_back(t);

        // sort by timestamp descending
        sort(all.begin(), all.end(), [](auto& a, auto& b){
            return a.first > b.first;
        });

        vector<int> feed;
        for (int i = 0; i < min((int)all.size(), 10); i++)
            feed.push_back(all[i].second);

        return feed;
    }
};