/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    // tip1:二叉搜索条件谨慎写，尤其是和其他组件迭代的时候检查好再进行其他步骤。tricky
    //tip2！！！：数据预处理很重要,这里参考了答案！！！使用w相同h逆序处理！！！这样避免12,1-12,5：[3,4],[12,2],[12,5]应该处理12的时候记录用前面的[3,4],最后替换成[12,2]
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& e1,vector<int>& e2){
            if(e1[0] == e2[0]) return e1[1] > e2[1];
            else return e1[0] < e2[0];
        });
        int n = envelopes.size();
        vector<int> dp(n,1);
        int w = 0,h = 0;
        vector<int> tmp ={0};//保持这里面按照高度dp值也递增
        int res = 1;
        for(int i = 1;i < n;++i){
            if(envelopes[i] == envelopes[i-1]) {
                dp[i] = dp[i-1];
                continue;
            }
            if(envelopes[i][0] > envelopes[tmp.back()][0]&&envelopes[i][1] > envelopes[tmp.back()][1]){
                dp[i] = dp[tmp.back()] + 1;
                tmp.emplace_back(i);
            }
            else{
                int left = 0,right = tmp.size();
                while(left <= right-1){
                    int mid = (right - left) / 2 + left;
                    if(envelopes[tmp[mid]][1] < envelopes[i][1]){
                        left = mid + 1;
                    }
                    else{
                        right = mid;
                    }
                }
                cout<<left<<endl;
                if(left > 0){
                    if(envelopes[i][1] == envelopes[tmp[left-1]][1]) continue;
                    else dp[i] = dp[tmp[left-1]] + 1;
                }
                if(left < tmp.size()&&dp[i] >= dp[tmp[left]]){
                    tmp[left] = i;
                }
                else tmp.insert(tmp.begin()+left,i);
                while(!tmp.empty()&&envelopes[tmp.back()][1] > envelopes[i][1]&& dp[tmp.back()] <= dp[i]) tmp.pop_back();
            }
            res = max(res,dp[i]);
        }
        return res;
        //tip1:单纯贪心不可
        //[[5,4],[6,4],[6,7],[2,3]]
        //[[4,5],[4,6],[6,7],[2,3],[1,1]]
        //[[1,1],[1,1],[1,1]]
        //[[2,100],[3,200],[4,300],[5,500],[5,400],[5,250],[6,370],[6,360],[7,380]]
        //[[30,50],[12,2],[3,4],[12,15]]
        //[[1,15],[7,18],[7,6],[7,100],[2,200],[17,30],[17,45],[3,5],[7,8],[3,6],[3,10],[7,20],[17,3],[17,45]]
        //[[1,15],[2,200],[3,10],[3,5],[3,6]]
        //[[46,89],[50,53],[52,68],[72,45],[77,81]]
    }
};
// @lc code=end

