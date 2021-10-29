/*
 * @lc app=leetcode.cn id=869 lang=cpp
 *
 * [869] 重新排序得到 2 的幂
 */

// @lc code=start
class Solution {
public:
    //dfs visited记得写引用！！！
    bool help(vector<int>& nums,vector<bool>& visited,int tmp,int len){
        //cout<<tmp<<endl;
        if(len == nums.size()) return (tmp & -tmp) == tmp;
        for(int i = 0;i < nums.size();++i){
            if(!visited[i]){
                if(tmp == 0&&nums[i] == 0) continue;
                visited[i] = true;
                if(help(nums,visited,10*tmp+nums[i],len+1)) return true;
                visited[i] = false;
            }
        }
        return false;
    }
    bool reorderedPowerOf2(int n) {
        if(n == 1||(n & -n) == n) return true;//注意位运算要有()
        if(n == 0) return false;
        vector<int> nums;
        while(n){
            nums.emplace_back(n%10);
            n /= 10;
        } 
        vector<bool> visited(nums.size(),false);
        return help(nums,visited,0,0);
    }
    //315872096
};
// @lc code=end

