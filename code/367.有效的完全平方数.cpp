/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    //2147483647
    bool isPerfectSquare(int num) {
        //cout<<sqrt(2147483647)<<endl;
        for(int i = 2;i<46341&&i<= num/2;++i){
            if(i*i == num) return true;
        }
        return num==1;
    }
};
// @lc code=end

