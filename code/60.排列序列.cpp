/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> p(n,1);
        vector<int> visited(n+1,0);
        for(int i = 1;i < n;++i){
            p[i] = p[i-1]*i;
        }
        string res = "";
        --k;
        for(int i = n-1;i >= 0;--i){
            int index = k/(p[i])+1;
            for(int j = 1;j <= n;++j){
                if(visited[j]==0){
                    --index;
                    if(!index){
                        res += (j+'0');
                        visited[j] = 1;
                        break;
                    }
                }
            }
            k = k%p[i];
        }
        return res;
    }
};
// @lc code=end

