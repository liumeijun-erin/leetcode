/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    //tip1:注意这里必须static成员函数，传入cmp地址
    //静态成员函数不可以调用类的非静态成员。因为静态成员函数不含this指针,也不需要传入this参数
    //tip2：注意这里一定要写引用，否则可能超时！
    /*static bool cmp(const vector<int> &a,const vector<int> &b){
        return a[1] < b[1];
    }*/
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        //sort(intervals.begin(),intervals.end(),cmp);
        //tip3:这样写cmp
        sort(intervals.begin(),intervals.end(),[](const vector<int> & a,const vector<int> & b){return a[1]<b[1];});
        int border = intervals[0][1];
        int cnt = 1;
        //审题：区间可能为负，所以要考虑 
        for(int i = 1;i < intervals.size();++i){
            if(intervals[i][0] >= border){
                ++cnt;
                border = intervals[i][1];
            }
        }
        return intervals.size() - cnt;
    }
};
// @lc code=end

