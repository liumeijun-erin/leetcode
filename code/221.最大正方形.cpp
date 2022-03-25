/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //solution1:bad idea,but accepted
        /*int m = matrix.size(),n = matrix[0].size();
        vector<vector<int> > dp(m,vector<int> (n,0));
        int area = 0,i,j,k,len = 1,side=0;
        for(i = 0;i < m;++i){
            for(j = 0;j < n;++j){
                if(matrix[i][j] == '1'){
                    if(j == 0) dp[i][j] = 1;
                    else{
                        dp[i][j] = dp[i][j-1] + 1;
                    }
                }
            }
        }
        for(i = 0;i < m;++i){
            for(j = 0;j < n;++j){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        for(i = n - 1;i >= side;--i){
            j = 0;
            while(j < m){
                while(j < m&&dp[j][i] == 0) ++j;
                if(j >= m) break;
                k = j;
                len = dp[j][i];
                while(j<m && dp[j][i]){
                    len = min(dp[j][i],len);
                    side = min(j-k+1,len);
                    area = max(area,side*side);
                    ++j;
                }
                if(j-k+1 > len) j = k+1;
            }
        }
        return area;*/
        //solution2:答案：条件转化！几何转换！！！多画画图！！！
        int m = matrix.size(),n = matrix[0].size();
        int area = 0;
        vector<vector<int> > dp(m,vector<int> (n,0));
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(matrix[i][j] == '0') continue;
                if(i == 0||j==0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])) + 1;
                }
                area = max(area,dp[i][j]*dp[i][j]);
            }
        }
        return area;
    }
    //[["1","1","0","1"],["1","1","0","1"],["1","1","1","1"]]
    //[["1","1","1","1","0"],["1","1","1","1","0"],["1","1","1","1","1"],["1","1","1","1","1"],["0","0","1","1","1"]]
        // solution3: 直观，但是表现一般
        // int res = 0;
        // int m = matrix.size(), n = matrix[0].size();
        // vector<int> cnt_r(n,0);
        // vector<int> cnt_c(n,0);
        // vector<vector<int> > len(m+1, vector<int> (n+1, 0));

        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if (matrix[i][j] == '1') {
        //             cnt_r[j] = cnt_r[j] + 1;
        //             if (j == 0) cnt_c[j] = 1;
        //             else cnt_c[j] = cnt_c[j-1] + 1;
        //             int tmp_len = min(cnt_c[j], cnt_r[j]);
        //             len[i+1][j+1] = min(tmp_len, (len[i][j] + 1));
        //             res = max(res,len[i+1][j+1]);
        //         }
        //         else {
        //             cnt_r[j] = 0;
        //             cnt_c[j] = 0;
        //         }
        //     }
        // }
        
        // return res*res;
};
// @lc code=end

