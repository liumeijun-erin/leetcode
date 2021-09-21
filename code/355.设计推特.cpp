/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */

// @lc code=start
class Twitter {
    //思想:只维护关系表，并保存每个用户发的信息上限10
    //solution1：认为应该回溯历史信息所以保存个人前10条 41/88->100/61
    //note:注意如果有很多删改，使用list更快一点！
    unordered_map<int,unordered_set<int> > ids;//follower_followee
    //vector<pair<int,int> > pool;//list faster
    list<pair<int,int> > pool;
    unordered_map<int,int> cnt;

public:
    /** Initialize your data structure here. */
    Twitter() {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        pool.emplace_back(make_pair(userId,tweetId));
        if(cnt.count(userId)) {
            if(cnt[userId]==10){
                /*
                for(int i = 0;i < pool.size();++i){
                    if(pool[i].first == userId){
                        pool.erase(pool.begin()+i);
                        --cnt[userId];
                        break;
                    }
                }*/
                for(auto it = pool.begin();it != pool.end();++it){
                    if((*it).first == userId){
                        pool.erase(it);
                        --cnt[userId];
                        break;
                    }
                }
            } 
        }
        else {
            cnt[userId] = 0;
        }
        ++cnt[userId];
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        /*for(int i = pool.size()-1;i >= 0&&res.size()<10;--i){
            if(pool[i].first == userId||ids.count(userId)&&ids[userId].count(pool[i].first)) res.emplace_back(pool[i].second);
        }*/
        for(auto it = pool.rbegin();it!=pool.rend()&&res.size()<10;++it){
            if((*it).first==userId||ids.count(userId)&&ids[userId].count((*it).first)) res.emplace_back((*it).second);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(!ids.count(followerId)){
            ids[followerId] = unordered_set<int> {};
        }
        ids[followerId].emplace(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(ids.count(followerId)){
            ids[followerId].erase(followeeId);
        }
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
// @lc code=end

