/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        //solution1
        /*int res = 0;
        while(x||y){ 
            if(x%2 != y%2) ++res;
            x /= 2;
            y /= 2;
        }*/
        //solution2:
        int res = x ^ y,num = 0;
        while(res){
            num += res&1;
            res >>= 1;
        }
        return num;
    }
};
// @lc code=end

