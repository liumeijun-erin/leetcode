/*
 * @lc app=leetcode.cn id=846 lang=cpp
 *
 * [846] 一手顺子
 */

// @lc code=start
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) return false;
        unordered_map<int,int> hash;
        sort(hand.begin(),hand.end());
        for (const int& c: hand) {
            if (hash.count(c)) ++hash[c];
            else hash[c] = 1;
        }
        int cnt = hand.size() / groupSize;
        int pos = 0;
        for (int i = 0;i < cnt; ++i) {
            while (pos < hand.size() && hash[hand[pos]] == 0) ++pos;
            if (pos == hand.size()) return false;
            --hash[hand[pos]];
            int num = hand[pos];
            for (int j = 1; j < groupSize; ++j) {
                ++num;
                if (!hash.count(num) || hash[num] == 0) return false;
                --hash[num];
            }
        }
        return true;
        //[8,10,12]\n3
    }
};
// @lc code=end

