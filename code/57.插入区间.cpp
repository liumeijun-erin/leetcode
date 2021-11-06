/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    //note:!!!vector中！！erase太多不可！！会超时!!!
    //solution1:两个二分+删除中间--由于有删除所以超时了--自作聪明--failed
    //solution2-直接遍历
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        int a = newInterval[0], b = newInterval[1];
        int pos = 0;
        while(pos < intervals.size()&&intervals[pos][1] < a){
            ans.emplace_back(intervals[pos++]);
        }
        if(pos < intervals.size()) a = min(intervals[pos][0],a);
        while(pos < intervals.size()&&intervals[pos][1] <= b) pos++;
        if(pos < intervals.size()&&intervals[pos][0] <= b) b = intervals[pos++][1]; 
        ans.emplace_back(vector<int> {a,b});
        while(pos < intervals.size()) ans.emplace_back(intervals[pos++]);
        return ans;
        // int a = newInterval[0], pos_a = -1;
        // int b = newInterval[1], pos_b = -1;
        // int left = 0, right = intervals.size();
        // while(left < right){
        //     int mid = (right - left)/2 + left;
        //     if(intervals[mid][1] < a) left = mid + 1;
        //     else  right = mid;
        // }
        // if(left == intervals.size()) {
        //     intervals.emplace_back(newInterval);
        //     return intervals;
        // }
        // pos_a = left;//第一个y >= a的段
        // cout<<pos_a<<endl;
        // left = 0, right = intervals.size();
        // while(left < right){
        //     int mid = (right - left)/2 + left;
        //     if(intervals[mid][0] > b) right = mid;
        //     else  left = mid + 1;
        // }
        // if(left == 0) {
        //     intervals.insert(intervals.begin(),newInterval);
        //     return intervals;
        // }
        // pos_b = left;//第一个x > b的段
        // cout<<pos_b<<endl;
        // if(pos_a == pos_b) intervals.insert(intervals.begin()+pos_a,newInterval);
        // else {
        //     a = min(a,intervals[pos_a][0]);
        //     b = max(b,intervals[pos_b - 1][1]);
        //     intervals[pos_a][0] = a;
        //     intervals[pos_a][1] = b;
        //     int cnt = pos_b - pos_a - 1;
        //     //cout<<cnt<<endl;
        //     if(cnt > 0){
        //         while(cnt--){
        //             intervals.erase(intervals.begin() + pos_a + 1);
        //         }
        //     }
        // }
        // return intervals;
        //[[1,2],[3,5],[6,7],[8,10],[12,16]]\n[4,8] 
    }
};
// @lc code=end

