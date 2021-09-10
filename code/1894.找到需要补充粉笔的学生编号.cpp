/*
 * @lc app=leetcode.cn id=1894 lang=cpp
 *
 * [1894] 找到需要补充粉笔的学生编号
 */

// @lc code=start
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        if(chalk.size() == 1) return 0;
        //long long sum = accumulate(chalk.begin(),chalk.end(),0);
        long long sum = 0;
        for(int i = 0;i < chalk.size();++i){
            sum += chalk[i];
        }
        k = k%sum;
        for(int i = 0;i < chalk.size();++i){
            if(k < chalk[i]) return i;
            k -= chalk[i];
        }
        return 0;
    }
};
// @lc code=end

