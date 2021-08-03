/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
class Solution {
public:
struct pair_hash
{
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};
    double returnCrossoverPnt(const vector<int> &a,const vector<int> &b){
        return a[1] - (b[1]-a[1])*a[0]/(b[0]-a[0]);
    }
    int maxPoints(vector<vector<int>>& points) {
        //暴力O(n^3),使用hashO(n^2)即可
        //note：（参考答案）这个记录还是按点记录比较好，如果在循环外面会多次计算共线点
        //且如果按照出发点后面点，一个斜率即可加在一起；不用存与y轴焦点
        //认真思考！设计数据结构！
        /*unordered_map<pair<double,double>,int,pair_hash> cnt;
        int maxn = 0;
        for(int i = 0;i < points.size() - 1;++i){
            int same_x = 1;
            for(int j = i+1;j<points.size();++j){
                if(points[i][0] == points[j][0]){
                    ++same_x;
                    maxn = max(maxn,same_x);
                }
                else{
                    double a = 1.0*(points[j][1] - points[i][1])/(points[j][0]-points[i][0]);
                    double b =returnCrossoverPnt(points[i],points[j]);
                    cout<<a<<" "<<b<<endl;
                    if(cnt.count(make_pair(a,b))) ++cnt[make_pair(a,b)];
                    else cnt[make_pair(a,b)] = 2;
                    maxn = max(maxn,cnt[make_pair(a,b)]);
                }
            }
        }
        return maxn;
        */
       //参考答案重写
       //别上来就硬写，想想其他思路,从一个点出发而不是遍历全局线段
       int maxn = 0;
       unordered_map<double,int> hash;
       for(int i = 0;i < points.size();++i){
           int same_x = 1;
           for(int j = i + 1;j < points.size();++j){
               if(points[j][0] == points[i][0]) ++same_x;
               else{
                   double a = 1.0*(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                   if(hash.count(a)) ++hash[a];
                   else hash[a] = 2;
                   maxn = max(hash[a],maxn);
               }
           }
           maxn = max(same_x,maxn);
           hash.clear();
       }
       return maxn;
    }
};
// @lc code=end

