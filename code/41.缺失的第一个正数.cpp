/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // solution1：hash-table,只记录所有可能最小的部分
        // 分析：O(N) O(N)
        // note:use nums.size() instead of MAXN
        //
        // int len = nums.size()+2;
        // vector<bool> num(len+2);
        // for (const int& n: nums) {
        //     if (n > 0 && n <= len) num[n] = true;
        // }
        // for (int i = 1; i <= len; ++i) {
        //     if (!num[i]) return i;
        // }
        // return 1;

        // solution2：空间压缩--利用use existing array!!!!! as hash-table--brilliant:use sign - to tag visited!!!
        // 策略：不额外设置空间，而是用-1标记该idx+1有出现；利用id作为标记数值
        // 分析：O(N) O(1)
        // note:注意排除0和负数影响
        // int maxn = nums.size() + 1;
        // for (int& num: nums) {
        //     if (num <= 0 || num > maxn) num = maxn;
        // }
        // for(int i = 0; i < nums.size();++i){
        //     if(abs(nums[i]) < maxn && nums[abs(nums[i]) - 1] > 0){
        //         nums[abs(nums[i])- 1] *= -1;
        //     }
        // }
        // for(int i = 0;i < nums.size();++i){
        //     if(nums[i] > 0) {
        //         return i+1;
        //     }
        // }
        // return nums.size()+1;
       
        // solution3:同样是利用已有空间。标记方法不同。
        // 策略：移动数组，使用nums[i] = i标记存在
        //tip:use existing array as hash-table:swap nums to form:nums[i] = i
        //note1: consider cases with duplicate numbers,especially when nums[i]== nums[nums[i] - 1]
        //key pnts:always watch out for endless loop! e.g.[1,1],[1,2,5,4,5]
        for(int i = 0;i < nums.size();i++){
            while(nums[i] != i + 1 && nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]){
                swap(nums[i],nums[nums[i] - 1]);
            }     
        }
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};
// @lc code=end+

