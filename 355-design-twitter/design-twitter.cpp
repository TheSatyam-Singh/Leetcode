#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:

    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    // follower -> set of people they follow
    unordered_map<int, unordered_set<int>> following;

    int timer = 0;

public:

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({timer, tweetId});

        timer++;
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> ans;

        // Max heap:
        // {time, tweetId}
        priority_queue<pair<int, int>> pq;

        // User's own tweets
        for (auto tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // Tweets of followed users
        for (int followee : following[userId]) {

            for (auto tweet : tweets[followee]) {
                pq.push(tweet);
            }
        }

        // Take 10 newest tweets
        while (!pq.empty() && ans.size() < 10) {

            auto [time, tweetId] = pq.top();
            pq.pop();

            ans.push_back(tweetId);
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {

        if (followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
    }
};