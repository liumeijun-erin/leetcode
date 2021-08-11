/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
    vector<int> directions {-1,0,1,0,-1};
public:
    void flow(vector<vector<int>>& height,vector<vector<int> >& record,int x,int y){
        record[x][y] = 1;
        for(int i = 0;i < 4;++i){
            int a = x+directions[i],b = y+directions[i+1];
            if(a>=0&&a<record.size()&&b>=0&&b<record[0].size()&&height[a][b]>=height[x][y]&&!record[a][b]){
                flow(height,record,a,b);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(),n = m?heights[0].size():0;
        vector<vector<int> > record1(m,vector<int> (n,0));
        vector<vector<int> > record2(m,vector<int> (n,0));
        int i,j;
        for(i = 0; i < m;++i){
            if(!record1[i][0]) flow(heights,record1,i,0);
            if(!record2[i][n-1]) flow(heights,record2,i,n-1);
        }
        for(i = 0; i < n;++i){
           if(!record1[0][i]) flow(heights,record1,0,i);
           if(!record2[m-1][i]) flow(heights,record2,m-1,i);
        }
        vector<vector<int> > res;
        for(i = 0;i < m;++i){
            for(j = 0;j < n;++j) {
                if(record1[i][j]&&record2[i][j]) res.push_back(vector<int> {i,j});
            }
        }
        return res;
    }
};
// @lc code=end

