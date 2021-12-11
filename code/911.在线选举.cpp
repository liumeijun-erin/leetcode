/*
 * @lc app=leetcode.cn id=911 lang=cpp
 *
 * [911] 在线选举
 */

// @lc code=start
// 本题不会有点不应该--可以保存状态每个时刻对应一个id+二分查找
// 空间换时间！！！
class TopVotedCandidate {
    vector<pair<int,int> > rec;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times){
        for (int i = 0; i < persons.size(); ++i) {
            rec.emplace_back(make_pair(times[i],persons[i]));
        }
        sort(rec.begin(), rec.end(), [](pair<int,int>& p1, pair<int,int>& p2){
            return p1.first < p2.first;
        });
        unordered_map<int,int> hash;
        int max_id = -1;
        for (int i = 0;i < rec.size();++i) {
            if (hash.count(rec[i].second)) ++hash[rec[i].second];
            else hash[rec[i].second] = 1;
            if (max_id == -1||hash[rec[i].second] >= hash[max_id]) max_id = rec[i].second;
            rec[i].second = max_id;
        }
    } 
    int q(int t) {
        int l = 0, h = rec.size();
        while(l < h) {
            int mid = (h-l)/2 + l;
            if(rec[mid].first == t) return rec[mid].second;
            if(rec[mid].first > t) h = mid;
            else l = mid + 1;
        }
        return rec[l-1].second;
    }
    //["TopVotedCandidate","q","q","q","q","q","q","q","q","q","q"]\n[[[0,1,2,2,1],[20,28,29,54,56]],[28],[53],[57],[29],[29],[28],[30],[20],[56],[55]]
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end

