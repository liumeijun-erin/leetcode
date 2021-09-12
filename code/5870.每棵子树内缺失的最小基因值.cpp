/*
 * @lc app=leetcode.cn id=5870 lang=cpp
 *
 * [5870] 每棵子树内缺失的最小基因值
 */

// @lc code=start
class Solution {
public:
    //整体思路：考虑筛选法：只有一支有1，其他的都是1；这时可以针对这支进行构造（回溯法）
    void postorder(int root,vector<int>& hasValue,vector<int>& res,vector<int>& nums,vector<vector<int> >&children,vector<int>& next,int &now){
        //tip1:注意要控制遍历的顺序 dfs先搜有1的
        if(!children[root].empty()){
            int n = next[root];
            //注意这里特殊root=1的时候
            if(n != -1) postorder(n,hasValue,res,nums,children,next,now);
            for(const int&child:children[root]){
                if(child != n) postorder(child,hasValue,res,nums,children,next,now);
            }
        }
        //！！！tip2：超时-这里参考答案优化！不从头开始 ,而是记录上一个位置在遍历！！！！
        //先预判一下数组长度，太长了一定要优化
        hasValue[nums[root]] = 1;
        if(res[root]==-1){
            for(;now <= 100000;++now){
                if(hasValue[now]==0){
                    break;
                }
            }
            res[root] = now;
            //tip3:这里要考虑一下超过100001的情况
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int node = -1;
        vector<int> res(nums.size(),1);
        vector<int> next(nums.size(),-1);
        vector<vector<int> > children(nums.size(),vector<int> {});
        for(int i = 0;i < nums.size();++i) {
            if(nums[i]==1){
                node = i;
            }
            if(i != 0) children[parents[i]].emplace_back(i);
        }
        if(node == -1) return res;
        vector<int> hasValue(100001,0);
        while(node != - 1){
            res[node] = -1;
            if(node!=0) next[parents[node]] = node;
            node = parents[node];
        }
        int now = 1;
        postorder(0,hasValue,res,nums,children,next,now);
        return res;
        //[-1,0,1,0,3,3]\n[5,4,6,2,1,3]--[7,1,1,4,2,1]
    }
};
// @lc code=end

