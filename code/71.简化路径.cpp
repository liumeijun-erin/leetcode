/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        int pos = 0,tmp;
        while (pos < path.size()) {
            if (path[pos] == '/') {
                ++pos;
                continue;
            }
            tmp = pos;
            int cnt_dot = 0;
            while (tmp < path.size() && path[tmp] != '/') {
                if (path[tmp] == '.') ++cnt_dot;
                ++tmp;
            }
            if (cnt_dot == tmp - pos) {
                if (cnt_dot == 2 && res.size()) {
                    int pre = res.rfind('/');
                    if(pre != -1) res.erase(pre);
                }
                if (cnt_dot <= 2) {
                    pos = tmp + 1;
                    continue;
                }
            }
            res += '/' + path.substr(pos, tmp-pos);
            pos = tmp + 1;
        }
        if (res.size() == 0) res = "/";
        return res;
    }
};
// @lc code=end

