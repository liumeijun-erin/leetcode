/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        while(n > 0){
            while(i < flowerbed.size() && flowerbed[i]) ++i;
            if(i >= flowerbed.size()) break;
            if(!i||i < flowerbed.size() - 1&&!flowerbed[++i]){
                if(i == flowerbed.size() - 1||!flowerbed[i + 1]){
                    flowerbed[i] = 1;
                    --n;
                    continue;
                }
            }
            ++i;
        }
        return n == 0;
    }
};
// @lc code=end

