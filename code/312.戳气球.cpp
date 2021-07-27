/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    /*unordered_map<string,int> record;
    string toString(vector<int>& nums){
        string res= "";
        string s;
        for(const int& num:nums){
            if(num == 100) s = "";
            else s = "0";
            if(num < 10) s += '0';
            s += to_string(num);
            res += s;
        }
        return res;
    }*/
    int maxCoins(vector<int>& nums) {
        //way1:简单分治会超时
        //way2:分治+memoization：采用将
        /*(nums.size() == 1) return nums[0];
        if(record.count(toString(nums))) return record[toString(nums)];
        int maxn = 0,res,v;
        for(int i = nums.size() - 1;i >= 0;i--){
            if(nums[i] == 0) nums.erase(nums.begin() + i);
        }
        for(int i = 0;i < nums.size();i++){
            res = nums[i];
            v =nums[i];
            if(i > 0) res *= nums[i - 1];
            if(i < nums.size() - 1) res *= nums[i + 1];
            nums.erase(nums.begin() + i);
            maxn = max(maxn,maxCoins(nums) + res);
            nums.insert(nums.begin() + i,v);
        }
        record[toString(nums)] = maxn;
        return maxn;*/
        //way3-看答案:官方answer!!倒过来想问题!!!，看成添加！！！这样改变的量就只有加入的left*mid*right，而不用考虑邻接情况的改变
        //思路：倒过来想即变成填满区间所需要的硬币数最多情况，这是需要确定的就是加入的时候的两边值left和right用于索引：val(left)*val(key)*val(right)
        //可以写成自顶向下分治，也可以写成自底向上动态规划
        int n = nums.size();
        //tip1：在nums前后加入1这样好计算
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int> > dp(n+2,vector<int> (n+2));
        //两端确定，所以可以看做往中间开区间内填空,填满的到的最大值,这样两端的即可确定
        for(int i = 2;i <= n + 1;i++){
            for(int j = 0;j <= n - i + 1;j++){
                int maxn = 0;
                for(int k = j+1;k < j+i;k++){
                    maxn = max(maxn,dp[j][k]+nums[k]*nums[j+i]*nums[j]+dp[k][j+i]);
                }
                dp[j][j+i] = maxn;
            }
        }
        return dp[0][n+1];
    }
};
// @lc code=end

