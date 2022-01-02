/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 */

// @lc code=start
class Solution {
public:
    // 本题来自答案!!!!妙哇！
    // 也是暴力搜索但是没必要对数组进行操作
    // 仅维护出发点start、步长量step等统计数据即可！！！
    // s1-对数组硬算超时
    // 1000000000
    int lastRemaining(int n) {
        // vector<int> nums;
        // for (int i = 1; i <= n; ++i) {
        //     nums.emplace_back(i);
        // }
        // while (nums.size() > 3) {
        //     vector<int> tmp = {};
        //     int pre = (nums.size()/2%2 == 1)? 3: 1;
        //     for(int i = pre; i < nums.size(); i += 4) {
        //         tmp.emplace_back(nums[i]);
        //     }
        //     swap(nums, tmp);
        // }
        // if (nums.size() == 1) return nums[0];
        // return nums[1];
        // 参考答案！
        // 将情况转换为状态变量：start  step n
        int start = 1;  // 既是索引也是值
        int step = 1;
        bool left2right = true;
        // 使用n维护当前队列长度
        while (n > 1) {
            // key pnt:提取start更改的条件
            // 这样可以只从一边考虑：只要确定长度的奇偶就都一样
            if (left2right || n%2) {
                start += step; 
            }
            step <<= 1;
            n >>= 1;
            left2right = !left2right;
        }
        return start;
    }

};
// @lc code=end

