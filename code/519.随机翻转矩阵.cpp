/*
 * @lc app=leetcode.cn id=519 lang=cpp
 *
 * [519] 随机翻转矩阵
 */

// @lc code=start
class Solution {
    int m_;
    int n_;
    unordered_set<int> s;
public:
    Solution(int m, int n): m_(m), n_(n) {

    }
    
    vector<int> flip() {
        int pos = rand() % (m_ * n_);
        while (s.count(pos)) {
            pos = rand() % (m_ * n_);
        }
        s.insert(pos);
        return vector<int> {pos/n_, pos%n_};
    }
    
    void reset() {
        s.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
// @lc code=end

