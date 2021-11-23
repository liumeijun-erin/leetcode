/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size() || s.size() <= 1) return false;
        vector<int> dif_id;
        unordered_set<int> cnt;
        bool has_dup = false;
        for (int i = 0; i < s.size(); ++i) {
            if (!has_dup) {
                if(cnt.count(s[i])) has_dup = true;
                else cnt.insert(s[i]);
            }
            if (s[i] != goal[i]) {
                dif_id.emplace_back(i);
                if (dif_id.size() > 2) return false;
            }
        }
        if (dif_id.empty()) return has_dup;
        if (dif_id.size() == 1) return false;
        return (s[dif_id[0]] == goal[dif_id[1]]) && \
        (s[dif_id[1]] == goal[dif_id[0]]);
    }
};
// @lc code=end

