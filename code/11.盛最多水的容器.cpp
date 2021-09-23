/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        /*list<pair<int,int> > f;
        int area = 0;
        f.emplace_back(make_pair(height[0],0));
        for(int i = 1;i < height.size();++i){
            for(auto it = f.begin();it!=f.end();++it){
                area = max(area,(i-it->second)*min(it->first,height[i]));
            }
            if(height[i]>f.back().first){
                f.emplace_back(make_pair(height[i],i));
            }
        }
        return area;*/
        //solution2:双指针，但是不要总想着拿到里面再往外，而是应该从外往里随时记录
        //移动的条件为选择小的动!!!
        //不要总想着大跨步，比如先遍历一遍得到全升序再遍历全升序
        //一步一步走结果相同！
        int i= 0,j = height.size()-1,res = min(height[i],height[j])*(j-i);
        while(i < j){
            if(height[i]<height[j]) ++i;
            else --j;
            res = max(min(height[i],height[j])*(j-i),res);
        }
        
        return res;
    }
};
// @lc code=end

