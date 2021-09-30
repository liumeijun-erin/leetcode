/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(),ans,row;
        vector<int> visited(n);
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
        for(int i = 0;i < n;++i){
            pq.emplace(make_pair(matrix[i][0],i));
        }
        while(k--){
            ans = pq.top().first;
            row = pq.top().second;
            pq.pop();
            if(visited[row] < n-1){
                ++visited[row];
                pq.emplace(make_pair(matrix[row][visited[row]],row));
            }
        }
        return ans;
    }
    //[[1,3,5],[6,7,12],[11,14,14]]
};
// @lc code=end

