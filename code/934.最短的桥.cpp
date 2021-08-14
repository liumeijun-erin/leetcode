/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<int> d {-1,0,1,0,-1};
        int i,j,a,b;
        for(i = 0;i < grid.size();++i){
            for(j = 0;j < grid[0].size();++j){
                if(grid[i][j] == 1) break;
            }
            if(j < grid[0].size()) break;
            //note：!!!时刻考虑数组越界，这里如果if(grid[i][j] == 1) break;肯定不行
        }
        queue<int> island;
        grid[i][j] = -1;
        island.emplace(i*100+j);
        queue<int> border;
        while(!island.empty()){
            //考虑特殊形状[[0,1,0],[0,1,1],[1,1,0],[0,1,0]]
            i = island.front()/100;
            j = island.front()%100;
            island.pop();
            for(int k = 0;k < 4;++k){
                a = i + d[k];
                b = j + d[k+1];
                if(a>=0&&a<grid.size()&&b>=0&&b<grid[0].size()&&grid[a][b] != -1){
                    if(!grid[a][b]){
                        if(border.empty()||border.back()!=i*100+j) border.emplace(i*100+j);
                    }
                    else{
                        grid[a][b] = -1;
                        island.emplace(a*100+b);
                    }
                }
            }
        }
        int cnt = 0,len;
        cout<<border.size()<<endl;
        while(!border.empty()){
            len = border.size();
            while(len--){
                i = border.front()/100;
                j = border.front()%100;
                border.pop();
                for(int k = 0;k < 4;++k){
                    a = i + d[k];
                    b = j + d[k+1];
                    if(a>=0&&a<grid.size()&&b>=0&&b<grid[0].size()&&grid[a][b] != -1){
                        if(grid[a][b]) return cnt;
                        else{
                            grid[a][b] = -1;
                            border.emplace(100*a+b);
                        }
                    }
                }
            }
            ++cnt;
            //note:if(num)不能区分1和-1！
        }
        return cnt;
    }
};
//[[0,0,0,0,0,0,0,0],[0,0,0,0,1,0,0,0],[0,0,0,0,1,1,0,0],[0,0,0,1,1,0,1,0],[0,0,0,0,0,1,1,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0]]

// @lc code=end

