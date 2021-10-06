/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int top[3],t = 0;
        for(const int& num:nums){
            bool appendEnd = true;
            for(int i = 0;i < t;++i){
                if(top[i] < num) {
                    for(int j = min(2,t);j > i;--j){
                        top[j] = top[j-1];
                    }
                    if(t<3) ++t;
                    top[i] = num;
                    appendEnd = false;
                    break;
                }
                else if(top[i]==num) {
                    appendEnd = false;
                    break;
                }
            }
            if(t < 3&&appendEnd) top[t++] = num;
        }
        if(t == 3) return top[2];
        else return top[0];
    }
    //[2, 2, 3, 1]
    //[2, 3, 1]
};
// @lc code=end

