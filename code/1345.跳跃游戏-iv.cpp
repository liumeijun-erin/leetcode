/*
 * @lc app=leetcode.cn id=1345 lang=cpp
 *
 * [1345] 跳跃游戏 IV
 */

// @lc code=start
class Solution {
public:
    // dp + queue -- 超时
    // 策略：从n-1开始向前bp
    // 参考答案： 用res记录各位置是否被visited
    // 问题出在同一级上有多个相同值的话要判断很多次 -- 补充一下对value记录的visited
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int> > hash;
        for (int i = 0;i < n; ++i) hash[arr[i]].emplace_back(i);

        vector<int> res(n, -1);
        res[n-1] = 0;
        unordered_set<int> visited;

        queue<int> q;
        q.emplace(n-1);
        while (!q.empty()) {
            int id = q.front();
            q.pop();
            if (id + 1 < n && res[id+1] == -1 ) {
                res[id+1] = res[id] + 1;
                q.emplace(id+1);
            }
            if (id > 0 && res[id-1] == -1) {
                res[id-1] = res[id] + 1;
                q.emplace(id-1);
            }
            if (visited.count(arr[id])) continue;
            visited.insert(arr[id]);
            for (const int& tmp_id: hash[arr[id]]) {
                if (res[tmp_id] != -1) continue;
                res[tmp_id] = res[id] + 1;
                q.emplace(tmp_id);
            }
        }
        return res[0];
    }
};
// @lc code=end

