/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public://
    // 本题参考答案，贪心策略选择！
    int jump(vector<int>& nums) {
        //审题，分析题目特性为最大长度而不是固定长度，因此bfs有点亏
        /*vector<int> visited(nums.size(),-1);
        visited[0] = 0;
        queue<int> q;
        q.emplace(0);
        while(!q.empty()){
            int len = q.size();
            while(len--){
                int f = q.front();
                q.pop();
                for(int i = f+1;i<nums.size()&&i <= f+nums[f];++i){
                    if(visited[i] != -1) continue;
                    visited[i] = visited[f]+1;
                    if(i == nums.size()-1) return visited[i];
                    q.emplace(i);
                }
            }
        }
        return visited[nums.size()-1];*/
        //参考答案：每次只要挑选最优潜力的跳出去--贪心即可，因为远的跳不到的进的也跳不到且可以选择跳进；而在一组内远近之间的不用考虑，能一次不跳两次
        //贪心策略！！！在当前点出发如果能一次到最好，否则挑二次跳的最远的一点，因为加入挑一次跳的最远的可能二次不行且如果在一次和二次最远点之间为最优解的话也可以选择不跳到最远
        if(nums.size()==1) return 0;
        int pos = 0;
        int cnt = 0;
        while(pos < nums.size()){
            int max_range =0,max_index= pos;
            if(pos + nums[pos] >= nums.size()-1) return cnt+1;
            for(int i = pos+1;i <= nums[pos]+pos;++i){
                int range = i+nums[i];
                if(range > max_range) {
                    max_index = i;
                    max_range = range;
                }
            }
            pos = max_index;
            ++cnt;
        }
        return cnt;
    }
};
// @lc code=end

