/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
class Solution {
public:
    // 本题参考答案:一定要先画画图分析，考虑好先按什么排序
    // 策略要选准!!!-利用时序关系！！！贪心--先按截止时间排序！！！这样可以保证当前time+new_class_period > new_class_end 则往前放也一定不可能
    // 所以这是
    // 遍历会超时
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int>& course1, vector<int>& course2){
            return course1[1] < course2[1];
        });
        int time = 0;
        priority_queue<int> lens;
        int res = 0;
        for (vector<int>& course: courses) {
            if (time + course[0] <= course[1]) {
                time += course[0];
                lens.emplace(course[0]);
                ++res;
            }
            else {
                if (!lens.empty() && course[0] < lens.top()) {
                    time -= lens.top();
                    time += course[0];
                    lens.pop();
                    lens.emplace(course[0]);
                }
            }
        }
        return res;
    }
    // [[9,14],[7,12],[1,11],[4,7]] note2：边界注意
    // [[5,15],[3,19],[6,7],[2,10],[5,16],[8,14],[10,11],[2,19]]
    // [[3,2],[4,3]]  note3：异常
    // [[10,12],[6,15],[1,12],[3,20],[10,19]]
};
// @lc code=end

