/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res(score.size(),"");
        priority_queue<pair<int,int> > pq;
        for (int i = 0; i < score.size(); ++i) {
            pq.emplace(make_pair(score[i], i));
        }
        int cnt = 1;
        while (!pq.empty()) {
            int pos = pq.top().second;
            pq.pop();
            if (cnt > 3) res[pos] = to_string(cnt);
            else if (cnt == 1) res[pos] = "Gold Medal";
            else if (cnt == 2) res[pos] = "Silver Medal";
            else res[pos] = "Bronze Medal";
            ++cnt;
        }
        return res;
    }
};
// @lc code=end

