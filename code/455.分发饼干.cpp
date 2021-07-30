/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        //简单题也要优化代码！写代码前一定要拿笔思考一下！
        //注意简单题也要仔细思考如何设计执行步骤能提高效率/代码可读性
        //注意简化变量，child就能做到的东西为何要有res
        //
        //solution1:自己瞎写
        /*
        int cookie = 0,res = 0;
        for(int child = 0;child < g.size();++child){
            while(cookie < s.size() && g[child] > s[cookie]){
                ++cookie;
            }
            if(cookie >= s.size()) break;
            ++cookie;
            res += 1; 
        }*/
        //
        //solution：模板
        int child = 0, cookie = 0;
        while(child < g.size() && cookie < s.size()){
            if(g[child] <= s[cookie]) ++child;
            ++cookie;
        }
        return child;

    }
};
// @lc code=end

