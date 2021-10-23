/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int state = 0;//0 未开始，1 已有a，2 已有b
        int a,b,min_pre;
        bool has_min = false;
        for(const int& n:nums){
            if(has_min&&n > min_pre) return true;
            if(state == 0) {
                a = n;
                state = 1;
            }
            else if(state == 1){
                if(n < a) a = n;
                else if(n > a) {
                    b = n;
                    state = 2;
                }
            }
            else if(state == 2) {
                if(n > b) return true;
                else if(n > a) b = n;
                else {
                    if(!has_min||b<min_pre) min_pre = b;
                    has_min = true;
                    a = n;
                    state = 1;
                }
            }
        }
        return false;
    }
};
// @lc code=end

