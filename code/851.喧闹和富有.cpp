/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 */

// @lc code=start
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> res(n,-1);
        vector<vector<int> > richer_v(n,vector<int> {});
        for (const vector<int>& pair: richer) {
            richer_v[pair[0]].emplace_back(pair[1]);
        }
        vector<pair<int,int> > quiet_pair_v;
        for (int i = 0; i < n; ++i) {
            quiet_pair_v.emplace_back(make_pair(i,quiet[i]));
        }
        sort(quiet_pair_v.begin(), quiet_pair_v.end(),[](pair<int,int>& p1, pair<int,int>& p2){
            return p1.second < p2.second; 
        });
        for (const pair<int,int>& quiet_pair: quiet_pair_v) {
            int id = quiet_pair.first;
            if (res[id] != -1) continue;
            res[id] = id;
            queue<int> q;
            q.emplace(id);
            while(!q.empty()) {
                id = q.front();
                q.pop();
                for (const int& poor: richer_v[id]) {
                    if (res[poor] != -1) continue;
                    res[poor] = quiet_pair.first;
                    q.emplace(poor);
                }
            } 
        }
        return res;
    }
    //[]\n[0]
    //[[0,1]]\n[0,1]
};
// @lc code=end

