/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    //solution2参考答案，看作多地平线的高楼问题：84拓展
    int maximalRectangle(vector<vector<char>>& matrix) {
        //solution1:按高度遍历，表现差
        /*int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size();
        if(!n) return 0;
        int res = 0,cnt = 0;
        vector<vector<int> > dp(m,vector<int> (n));
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                dp[i][j] = matrix[i][j]-'0';
                if(dp[i][j]) ++cnt;
            }
        }
        for(int j = 0;j < m;++j){
            int max_cnt = 0;
            for(int i = 0;i + j < m;++i){
                for(int k = 0;k < n;++k){
                    if(dp[i][k]&&matrix[i+j][k]=='1'){
                        if(k > 0) dp[i][k] = dp[i][k-1]+1;
                        max_cnt = max(max_cnt,dp[i][k]);
                    }
                    else dp[i][k] = 0;
                }
            }
            //cout<<j+1<<" "<<max_cnt<<endl;
            res = max(res,(j+1)*max_cnt);
        }
        return res;
        //[["1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","0"],["1","1","1","1","1","1","1","0"],["1","1","1","1","1","0","0","0"],["0","1","1","1","1","0","0","0"]]
        */
       //solution2:参考84思想单调栈+哨兵!!!
       int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size();
        if(!n) return 0;
        vector<vector<int> > dp(m,vector<int> (n));
        // 记录(i,j)上最大高度
        for(int j = 0;j < n;++j){
            for(int i = 0;i < m;++i){
                dp[i][j] = matrix[i][j]-'0';
                if(i>0&&dp[i][j]) dp[i][j] = dp[i-1][j] + 1;
            }
        }
        int res = 0;
        // 对每一行利用单调栈转换为题目84 + 单调栈+哨兵数组
        for(int i = m-1;i >= 0;--i){
            stack<int> s;
            vector<int> left(n,-1);
            for(int j = 0;j < n;++j){
                left[j] = j;
                while(!s.empty()&&(dp[i][j] == 0||dp[i][s.top()] >= dp[i][j])){
                    left[j] = left[s.top()];
                    res = max(res,dp[i][s.top()]*(j-1-left[s.top()]+1));
                    s.pop();
                }
                s.emplace(j);
            }
            // 注意思想策略在于针对每一个柱状遍历左右，所以用while每一个都遍历
            while(!s.empty()){
                res = max(res,dp[i][s.top()]*(n-left[s.top()]));
                s.pop();
            }
        }
        return res;
    }
};
// @lc code=end

