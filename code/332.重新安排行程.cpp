/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    //参考答案：一笔画问题
    //本题首先对图进行分析，巧妙利用特性进行转化！！！
    //首先本题强调所有点都用上的时候存在一个一笔画，也就是说一定存在一个点入度=出度+1，而其他点都不是
    //这样问题可以逆序考虑，每次都找那个入度大于出度的，也就是找到它的时候他没有边了即可；这个点一定是该步骤选定点
    //逆序思考问题!!!顺序麻烦！！
    //进一步分析，遍历边+删除边直到找到一个没有出度的点push_back vector，最后reverse即可；
    //且已经删去的边并不需要加回来，动态遍历删边的过程就相当于统计出度入度，不需要额外统计
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //personal:其实priority_queue也可
        unordered_map<string,multiset<string> > m;
        //tip:不需要的时候使用unordered_map,much faster
        for(const auto& ticket:tickets){
            m[ticket[0]].insert(ticket[1]);
        }
        stack<string> s;
        s.push("JFK");
        vector<string> res;
        while(!s.empty()){
            string cur = s.top();
            if(!m.count(cur)){
            //tip：erase之后考虑空集,并不是count == 0
                s.pop();
                res.emplace_back(cur);
            }
            else{
                string next = *(m[cur].begin());
                s.push(next);
                m[cur].erase(m[cur].begin());
                if(m[cur].empty()) m.erase(cur);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

