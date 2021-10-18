/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        //solution:利用单调栈超时，改变策略不在过程中记录res
        //todo：可以用哨兵数组改进
        stack<pair<int,int> > s;
        int res = 0;
        for(int i = 0;i < height.size();++i){
            if(s.empty()||height[i] <s.top().first) s.emplace(make_pair(height[i],i));
            else if(height[i] >s.top().first){
                int left =  s.top().second,left_h =  s.top().first;
                while(s.size()>1&&height[i] > s.top().first){
                    left =  s.top().second;
                    left_h =  s.top().first;
                    s.pop();
                }
                if(s.size() == 1&&height[i] > s.top().first){
                    for(int j = s.top().second + 1;j < i;++j){
                        res += s.top().first - height[j];
                    }
                    s.pop();
                    s.emplace(make_pair(height[i],i));
                }
                else s.emplace(make_pair(height[i],left));
            }
        }
        int right = height.size();
        while(!s.empty()){
            int left = s.top().second;
            int left_h = s.top().first;
            //cout<<s.top().first<<" "<<s.top().second<<endl;
            for(int i = right-1;i >= left;--i){
                res += left_h - height[i];
            }
            right = left;
            s.pop();
        }
        return res;
        //[2,0,2]
    }
};
// @lc code=end

