/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */

// @lc code=start
class Solution {
public:
    //本题嫌太麻烦，参考答案写的.动态平衡想法！！！局部平衡条件+边界限制+初始化&用queue保存改变点更新受影响点！！
    //思路巧妙：利用变化关系和边界条件得到稳定值：先都设成最大值，然后从逆向泄水的角度考虑！
    //利用局部关系和边界一定泄水到height出发，用queue记录每次发生改变的值，然后遍历受影响的值。直到不变稳定状态！
    //dfs
    //思路：不是构造而是排除！！！而且从泄水点开始更新！
    //key pnt1:利用局部关系公式water[i][j]=max(heightMap[i],min(water[i−1][j],water[i+1][j],water[i][j−1],water[i][j+1]))
    //不填而是泄水，这样先设为最大可能值，！！！！//预先都设成最大，然后依次遍历
    //key pnt2!!!!:利用四周肯定泄水是边界，然后依次修改相邻受影响的部分.利用queue依次更新
    //tip：使用water记录全局状态，不要怕多用一点空间。只想着怎么求gap比较难
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(),n = heightMap[0].size();
        int max_height = 0;
        int res = 0;
        for (int i = 0; i < m; ++i) {
            // 这种写法max_element
            max_height = max(max_height, *max_element(heightMap[i].begin(), heightMap[i].end()));
        }
        vector<int> d{-1,0,1,0,-1};
        vector<vector<int> > water(m,vector<int> (n,max_height));
        queue<int> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (water[i][j] > heightMap[i][j]) {
                        water[i][j] = heightMap[i][j];
                        q.push(i *200 + j);
                    }
                }
            }
        }   
        while(!q.empty()){
            int x = q.front()/200;
            int y = q.front()%200;
            q.pop();
            for(int i = 0;i < 4;++i){
                int new_x = x + d[i],new_y = y + d[i+1];
                if(new_x < 0||new_x >= m||new_y < 0||new_y >= n) continue;
                if(water[new_x][new_y] > heightMap[new_x][new_y] &&water[new_x][new_y] > water[x][y] ){
                    water[new_x][new_y] = max(heightMap[new_x][new_y], water[x][y]);
                    q.emplace(new_x*200 + new_y);
                }
            }
        }
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                res += water[i][j] - heightMap[i][j];
            }
        }
        return res;
    }
};
// @lc code=end

