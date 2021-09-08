/*
 * @lc app=leetcode.cn id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int> > option; 
        for(int i = 0;i <profits.size();++i){
            option.emplace_back(make_pair(profits[i],capital[i]));
        }
        //solution1-failed:这里不行 多次循环遍历会超时
        //k:10^5,profit.size()
        /*sort(option.begin(),option.end(),[](pair<int,int>& p1,pair<int,int> &p2){
            if(p1.first == p2.first) return p1.second<p2.second;
            else return p1.first > p2.first;
        });
        while(k--){
            for(int i = 0;i < option.size();++i){
                if(option[i].first == -1) continue;
                if(option[i].second <= w) {
                    w += option[i].first;
                    option[i].first = -1;
                    break;
                }
            }
        }*/
        //todo：可以保存 w+times*max_profit对应的索引，减少查找的次数
        //solution2:参考答案,数量级很大的时候不需要全体排序，可以多建立一个数组局部排序即可！
        //key pnt！多用一个数据结构处理局部数据，降低规模！！！
        sort(option.begin(),option.end(),[](pair<int,int>& p1,pair<int,int> &p2){
            return p1.second<p2.second;
        });
        priority_queue<pair<int,int> > pq;
        int i= 0 ;
        while(k--){
            while(i < option.size()&&option[i].second <= w) pq.emplace(option[i++]);
            if(!pq.empty()){
                w += pq.top().first;
                pq.pop();
            }
        }
        return w;
    }
};
// @lc code=end

