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

        // int a = 0, b = 0, c = 0;
        // int state = 0; // 1-a,2-ab,3-abc;
        // for (const int& num: nums) {
        //     switch (state) {
        //         case 1: {
        //             if (num <= a) a = num;
        //             else {
        //                 b = num;
        //                 state = 2;
        //             }
        //             break;
        //         }
        //         case 2: {
        //             if (num > b) return true;
        //             else if (num > a) b = num;
        //             else {
        //                 c = num;
        //                 state = 3;
        //             }
        //             break;
        //         }
        //         case 3: {
        //            if (num > b) return true;
        //            else if (num > c) {
        //                a = c;
        //                b = num;
        //                state = 2;
        //            }
        //            else c = num;
        //            break;
        //         }
        //         default:{
        //             a = num;
        //             state = 1;
        //         }
        //     }
        // }
        // return false;
    }
};
// @lc code=end

