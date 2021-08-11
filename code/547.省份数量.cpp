/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        vector<int> record (n,0);
        for(int i = 0;i < n;++i){
            if(record[i]) continue;
            record[i] = 1;
            ++cnt;
            stack<int> s;
            s.push(i);
            while(!s.empty()){
                int city = s.top();
                s.pop();
                for(int j = i+1;j < n;++j){
                    if(!record[j]&&isConnected[city][j]){
                        record[j] = 1;
                        s.push(j);
                    }
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

