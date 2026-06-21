#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
class Twitter {
public:
    Twitter() {
        user_database.clear();
        tweet_database.clear();
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(tweet_database.find(userId)==tweet_database.end()) tweet_database[userId]={{timestamp++,tweetId}};
        else tweet_database[userId].push_back({timestamp++,tweetId});
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        user_database[userId].insert(userId);
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        for(auto foll:user_database[userId]){
            for(auto tweet:tweet_database[foll]){
                heap.push(tweet);
                if(heap.size()>10){
                    heap.pop();
                }
            }
        }
        vector <int> feed = {};
        while(!heap.empty()){
            feed.insert(feed.begin(),heap.top().second);
            heap.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        user_database[followerId].insert(followeeId);
        if(tweet_database.find(followeeId)==tweet_database.end()) tweet_database[followeeId]={};
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        user_database[followerId].erase(followeeId);
        return;
    }
private:
    unordered_map<int, unordered_set<int>> user_database; //user:followed
    unordered_map <int, vector<pair<int,int>>> tweet_database; //user:tweets
    int timestamp;

};
