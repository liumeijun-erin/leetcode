/*
 * @lc app=leetcode.cn id=1036 lang=cpp
 *
 * [1036] 逃离大迷宫
 */

// @lc code=start
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        // 10*12 遍历爆栈，内存也溢出
        // 充分利用所有条件！
        // dfs 爆栈->结合具体情况(blocked nodes <= 200)提前结束遍历！--参考答案：
        // 分析不可能到达情况仅：src/tar被完全包裹起来
        // n个blocked nodes最多可包围区域一角落，等边三角形-- n * (n-1) /2
        long long n = 1e6;
        int max_area = (blocked.size()-1) * blocked.size() /2;
        int d[5] = {-1,0,1,0,-1};

        long long src = n*source[0] + source[1];
        long long tar = n*target[0] + target[1];

        unordered_set<long long> hash;
        for (const vector<int>&b : blocked) {
            hash.emplace(n*b[0]+b[1]);
        }

        queue<long long> q;
        q.emplace(src);
        hash.emplace(src);
        int area = 1;
        while (!q.empty() && area <= max_area) {
            long long cur = q.front();
            q.pop();
            int x = cur/n, y = cur %n;
            for (int i = 0; i < 4; ++i) {
                if (x +d[i]< 0 || x + d[i] >= n || y + d[i+1] < 0|| y + d[i+1] >= n) continue;
                long long next = cur + n * d[i] + d[i+1];
                if (next == tar) return true;
                if (hash.count(next)) continue;
                ++area;
                hash.insert(next);
                q.emplace(next);
            }
        }
        if (q.empty()) return false;
        while (!q.empty()) q.pop();
        q.emplace(tar);
        hash.emplace(tar);
        area = 1;
        while (!q.empty() && area <= max_area) {
            long long cur = q.front();
            q.pop();
            int x = cur/n, y = cur %n;
            for (int i = 0; i < 4; ++i) {
                if (x +d[i]< 0 || x + d[i] >= n || y + d[i+1] < 0|| y + d[i+1] >= n) continue;
                long long next = cur + n * d[i] + d[i+1];
                if (next == src) return true;
                if (hash.count(next)) continue;
                ++area;
                hash.insert(next);
                q.emplace(next);
            }
        }
        if (q.empty()) return false;
        return true;
        //[[0,1],[1,0]]\n[0,0]\n[0,2]
    }
};
// @lc code=end

 