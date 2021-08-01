/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
class Solution {
public:
    struct cmp{
        bool operator ()(const vector<int>& a, const vector<int>& b){
            if(a[0] != b[0]) return a[0] > b[0];
            else return a[2] < b[2];
            //增加高度判断，这样同时开始得第二个直接折叠即可，出现第一个转折点保存即可
        };
    };
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //tip:使用sort还是priority_queue还要看过程中有没有新加入元素，有的话使用priority_queue更好
        //way1:自己写法
        priority_queue<vector<int> ,vector<vector<int> >,cmp> q;
        int right = 0;
        for(const vector<int>& build:buildings){
            q.push(build);
            right = max(right,build[1]);
        }
        vector<int> build;
        vector<vector<int> > res;
        int height = 0;
        int border = 0;
        while(!q.empty()){
            build = q.top();
            if(build[0] > border){
                if(border) res.push_back(vector<int>{border,0});
                res.push_back(vector<int>{build[0],build[2]});
                height = build[2];
                border = build[1];
            }
            else if(build[2] == height) border = max(border,build[1]);
            else if(build[0] == border||build[2] > height){
                res.push_back(vector<int>{build[0],build[2]});
                if(build[1] < border){
                    q.push(vector<int> {build[1],border,height});
                }
                height = build[2];
                border = build[1];
            }
            else if(build[1]>border){
                q.push(vector<int> {border,build[1],build[2]});
            }
            q.pop();
        }
        res.push_back(vector<int> {right,0});
        return res;
    }
    //way2：答案写法
    //tip:!!!审题 已知x按照非递减顺序，要合理利用
    //tip:emplace代替push_front,push,push_back可以省略中间变量，加快
    //tip：详解可见官方介绍，由于res肯定再边缘点上因此遍历buildings[i][0]即可
    //personal：遍历building边缘点，保证当前queue中的buildings（根据buildings按左坐标有序排列）范围包含当前点且按照高度下降，所以有一个即可看下一个边缘点！！！！
    //！！！利用priority_queue可变有序，过程中可以加入，也不用一次加入所有。
    //时间复杂度：由于每个building最多入列一次，出列一次，所以最多nlogn！
    //由于左边缘一直保证包含边缘点，所以不用保存
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> max_heap; // <高度, 右端>，
        //tip:默认先第一个排序再比较第二个！！
        int i = 0, len = buildings.size();
        int cur_x, cur_h;
        while (i < len || !max_heap.empty()) {
            if (max_heap.empty() || i < len && buildings[i][0] <= max_heap.top().second) {
                cur_x = buildings[i][0];
                while (i < len && cur_x == buildings[i][0]) {
                    //每遍历一个左边缘点，就把从它开始的都加进去，保证从当前点左边开始都加入了
                    max_heap.emplace(buildings[i][2], buildings[i][1]);
                    ++i;
                }   
            } else {
                cur_x = max_heap.top().second;
                while (!max_heap.empty() && cur_x >= max_heap.top().second) {
                    max_heap.pop();
                }
            }
            cur_h = (max_heap.empty()) ? 0 : max_heap.top().first;
            if (ans.empty() || cur_h != ans.back()[1]) {
                ans.push_back({cur_x, cur_h});
            }
        }
        return ans;
    }
};
// @lc code=end

