/*
 * @lc app=leetcode.cn id=1995 lang=cpp
 *
 * [1995] 统计特殊四元组
 */

// @lc code=start
class Solution {
public:
    //  solution1-暴力 O(n^4)
    // int countQuadruplets(vector<int>& nums) {
    //     int res = 0;
    //     for (int i = 0; i + 3 < nums.size(); ++i) {
    //         for (int j = i + 1; j + 2 < nums.size(); ++j) {
    //             for (int p = j + 1; p + 1< nums.size(); ++p) {
    //                 int sum = nums[i] + nums[j] + nums[p];
    //                 for (int q = p + 1; q < nums.size(); ++q) {
    //                     if (sum == nums[q]) ++res;
    //                 }
    //             }
    //         }
    //     }
    //     return res;
    //     //[9,6,8,23,39,23]
    // }
   
    // solution2：参考答案简化d的搜索,使用hash从右往左遍历 O(n^3)
    // 由于d必须在最右边所以不能排序--利用遍历顺序进行优化
    // int countQuadruplets(vector<int>& nums) {
    //     int res = 0;
    //     for (int a = 0; a + 3 < nums.size(); ++a) {
    //         for (int b = a + 1; b + 2 < nums.size(); ++b) {
    //             unordered_map<int,int> hash;
    //             hash[nums.back()] = 1;
    //             for (int c = nums.size()-2; c > b; --c) {
    //                 if (hash.count(nums[a] + nums[b] + nums[c])) res += hash[nums[a] + nums[b] + nums[c]];
    //                 if (hash.count(nums[c])) ++hash[nums[c]];
    //                 else hash[nums[c]] = 1;
    //             }
    //         }
    //     }
    //     return res;
    // }

    // solution3:参考答案！！！从中间b开始遍历 ！后面存d-c--O(n^2)
    // d在最右 所以逆序遍历:利用b遍历每一次多一个c值遍历一下后面的d-c + 遍历一下前面的a
    // 充分利用条件化简：利用数值关系消掉一个变量 再利用d-c在b后，a在b前消掉一个变量，巧妙达O(n^2)
    int countQuadruplets(vector<int>& nums) {
        int res = 0;
        unordered_map<int,int> hash;
        for (int b = nums.size()-3; b -1 >= 0; --b) {
            for (int d = nums.size()-1; d-1 > b;--d) {
                if(hash.count(nums[d] - nums[b+1])) ++hash[nums[d] - nums[b+1]];
                else hash[nums[d] - nums[b+1]] = 1;
            }
            for (int a = b-1; a >= 0; --a) {
                if(hash.count(nums[a] + nums[b])) res += hash[nums[a] + nums[b]];
            }
        }
        return res;
    }
};
// @lc code=end

