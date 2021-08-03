/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
class Solution {
public:
    /*struct cmp{
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
    }*/
    //
    //way2：答案写法
    //tip:!!!审题 已知x按照非递减顺序，要合理利用
    //tip:emplace代替push_front,push,push_back可以省略中间变量，加快
    //tip：详解可见官方介绍，由于res肯定再边缘点上因此遍历buildings[i][0]即可
    //personal：遍历building边缘点，保证当前queue中的buildings（根据buildings按左坐标有序排列）范围包含当前点且按照高度下降，所以有一个即可看下一个边缘点！！！！
    //！！！利用priority_queue可变有序，过程中可以加入，也不用一次加入所有。
    //时间复杂度：由于每个building最多入列一次，出列一次，所以最多nlogn！
    //由于左边缘一直保证包含边缘点，所以不用保存
    /*vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
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
    }*/
    //
    //way3:按照答案思路重写一遍
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //思路，遍历左端点，且对加入右端点的情况考虑全
        priority_queue<pair<int,int> > q;
        vector<vector<int> > res;
        int i = 0,len = buildings.size();
        //对比way2，每次以top().second为界限删去，而不是以builds[i][0]为界限删去
        //这样删完top考虑右边界限
        //分两种情况，加入的是左边界/右边界
        int cur_x,cur_h;
        while(i < len||!q.empty()){
            if(q.empty()||i < len &&buildings[i][0] <= q.top().second){
                //这边直接考虑左交点即可
                cur_x = buildings[i][0];
                while(i < len && buildings[i][0] == cur_x){
                    q.emplace(buildings[i][2],buildings[i][1]);
                    ++i;
                }
                cur_h = q.top().first;
            }
            else{
                //note:合理分类左右交点，然后每次关注局部->即一个交点怎么判断，合理利用迭代缩小问题复杂度
                //这边考虑右交点，首先删去只包含左交点
                //注意这里更新以q.top().second为界限，可以简化
                //思考why：如果针对buildings[i][0]左侧都删除，需要迭代考虑短top的右边界和长非top的交点。
                //这里使用迭代每次删除top->这种不会有左边界交点受影响，且每次考虑一个交点迭代进行，可以简化代码。
                //这样每次迭代考虑top的右侧即可
                cur_x = q.top().second;
                while(!q.empty()&&q.top().second <= cur_x) q.pop();
                if(!q.empty()) cur_h = q.top().first;
                else cur_h = 0;
            }
            if(res.empty()||cur_h != res.back()[1]){
                res.emplace_back(vector<int> {cur_x,cur_h});
            }
        }
        return res;
    }
};
// @lc code=end

