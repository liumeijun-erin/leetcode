/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */

// @lc code=start
class MapSum {
    class LetterNode {
    public:
        int v = 0;
        LetterNode* child[26] = {nullptr};
        LetterNode(int x = 0): v(x) {}
    };
    LetterNode* root;
    
public:
    MapSum() {
        root = new LetterNode(0);
    }
    
    void insert(string key, int val) {
        LetterNode* pre = root;
        for (const char& c: key) {
            if (!pre->child[c-'a']) pre->child[c-'a'] = new LetterNode(0);
            pre = pre->child[c-'a'];
        }
        pre->v = val;
    }
    
    void helpSum(LetterNode* node, int& res) {
        if (!node) return ;
        res += node->v;
        for (int i = 0; i < 26; ++i) {
            if (node->child[i]) {
                helpSum(node->child[i], res);
            }
        }
    }

    int sum(string prefix) {
        LetterNode* pre = root;
        for (const char& c: prefix) {
            if (!pre->child[c-'a']) return 0;
            pre = pre->child[c-'a'];
        }
        int res = 0;
        helpSum(pre, res);
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

