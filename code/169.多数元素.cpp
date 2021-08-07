/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //way1:corrrect
        /*sort(nums.begin(),nums.end());
        return nums[nums.size()/2];*/
        int n = nums.size(),i;
        //way2：写了一个快速选择，结果是一个有序数组超时
        //增加了随机swap主元还是超时..
        //增加打乱数组！还是超时
        //达不到平均或者说用例要求很严，就不该继续打擦边球了
        //！！各种优化都试了之后还过不了说明应该转换思路！!!!不要在死磕改进了
        //way3：答案，利用这个数字n/2，说明比其他一切的和都多
        //利用数字特点发现隐含抓手！！！：因为所求的值比其他一切都多，因此可以一消一，看能留下的
        //摩尔投票法
        int cur = nums[0],cnt = 0;
        for(const int& num:nums){
            if (num == cur) {
                ++cnt;
                if(cnt > n/2) break;
            }
            else {
                --cnt;
                if(cnt == 0){
                    cur = num;
                    cnt = 1;
                }
            }
        }
        return cur;
    }
};
// @lc code=end

