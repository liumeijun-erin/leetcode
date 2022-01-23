/*
 * @lc app=leetcode.cn id=2034 lang=cpp
 *
 * [2034] 股票价格波动
 */

// @lc code=start
class StockPrice {
    unordered_map<int,int> hash;
    priority_queue<pair<int,int> > pq;
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq_r;
    int timenow_ ,pricenow_;
public:
    StockPrice() {
        timenow_ = 0;
        pricenow_ = 0;
    }
    
    void update(int timestamp, int price) {
        hash[timestamp] = price;
        pq.emplace(make_pair(price, timestamp));
        pq_r.emplace(make_pair(price, timestamp));
        if (timestamp >= timenow_) {
            pricenow_ = price;
            timenow_ = timestamp;
        }
    }
    
    int current() {
        return pricenow_;
    }
    
    int maximum() {
        while (hash[pq.top().second] != pq.top().first) pq.pop();
        return pq.top().first;
    }
    
    int minimum() {
        while (hash[pq_r.top().second] != pq_r.top().first) pq_r.pop();
        return pq_r.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end

