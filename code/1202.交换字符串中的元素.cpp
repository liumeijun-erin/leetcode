/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */

// @lc code=start
class Solution {
public:
    //  solution1-union find再组内sort、交换超时
    //  ！！！！important：路径压缩
    int find(vector<int>& id, int p) {
        while (p != id[p]) {
            id[p] = id[id[p]];  // 路径压缩！
            p = id[p];
        }
        return p;
    }
    void connect(vector<int>& id, const int& p,const int & q) {
        id[find(id, p)] = find(id, q);
    }
    void changeOrder(string& s, vector<int>& pos) {
        vector<char> tmp;
        for (const int& p: pos) tmp.emplace_back(s[p]);
        sort(tmp.begin(), tmp.end());
        sort(pos.begin(), pos.end());
        for (int i = 0; i < pos.size(); ++i) {
            s[pos[i]] = tmp[i];
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> id(s.size());
        iota(id.begin(),id.end(),0);
        for (const vector<int>& pair: pairs) {
            connect(id, pair[0],pair[1]);
        }
        unordered_map<int, vector<int> > connectedPos;
        for (int i = 0; i < id.size(); ++i) {
            int root = find(id, i);
            if (connectedPos.count(root)) connectedPos[root].emplace_back(i);
            else connectedPos[root] = {i};
        }
        for (auto it = connectedPos.begin(); it != connectedPos.end(); ++it) {
            changeOrder(s, it->second);
        }
        return s;
    }
};
// @lc code=end

