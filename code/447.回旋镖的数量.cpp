/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        //参考答案改进：无论简单题还是难题都一定要优化到最大程度，能保留局部就保留局部
        //这种方法少了存储和map遍历，但是计算多了一遍
        //发现最后性能提高
        int n = points.size();
        //vector<unordered_map<long long,int> > cnt(n);
        unordered_map<long long,int> cnt;
        int res = 0;
        for(int i = 0;i < n;++i){
            cnt.clear();
            for(int j = 0;j < n;++j){
                if(j==i) continue;
                long long d = (points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                /*if(cnt.count(d)) ++cnt[i][d];
                else cnt[i][d]=1;
                if(cnt[j].count(d)) ++cnt[j][d];
                else cnt[j][d]=1;*/
                if(cnt.count(d)) {
                    res += 2*cnt[d];
                    ++cnt[d];
                }
                else cnt[d] = 1;
            }
        }
        /*int res = 0;
        for(auto& m:cnt){
            for(auto iter = m.begin();iter != m.end();++iter){
                if((*iter).second) res += ((*iter).second)*((*iter).second-1);
            }
        }*/
        return res;
    }
};
// @lc code=end

