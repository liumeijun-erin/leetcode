/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 */

// @lc code=start
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //本题不会
        //参考答案：暴力遍历超时，将图问题转换为节点重复次数问题！！！！！
        //规律：正确解只有外围四个定点重复度为1，且正确解中不会有出现三次的点，因此只需要set异或即可
        //tip:条件筛选很重要：最后使用面积和与最外层相等+有且只有最外层四个点为单（3）次出现
        //利用层层贴合的条件：内部点重叠度2/4！！！
        //note:set可以pair做键值；unordered-不可，需要自己写麻烦
        const int base = 15000;
        unordered_set<int> s;
        int x1 = rectangles[0][0],x2 = rectangles[0][2];
        int y1 = rectangles[0][1],y2 = rectangles[0][3];
        int area_sum = 0;
        for(const vector<int>& r:rectangles){
            area_sum += (r[1]-r[3])*(r[0]-r[2]);
            x1 = min(r[0],x1);
            y1 = min(r[1],y1);
            x2 = max(r[2],x2);
            y2 = max(r[3],y2);
            if(s.count(base*r[0]+r[1])) s.erase(base*r[0]+r[1]);
            else s.insert(base*r[0]+r[1]);
            if(s.count(base*r[2]+r[1])) s.erase(base*r[2]+r[1]);
            else s.insert(base*r[2]+r[1]);
            if(s.count(base*r[0]+r[3])) s.erase(base*r[0]+r[3]);
            else s.insert(base*r[0]+r[3]);
            if(s.count(base*r[2]+r[3])) s.erase(base*r[2]+r[3]);
            else s.insert(base*r[2]+r[3]);
        }
        if(area_sum!=(x2-x1)*(y2-y1)||s.size()!=4||!s.count(x1*base+y1)||!s.count(x1*base+y2)||!s.count(x2*base+y1)||!s.count(x2*base+y2)) return false;
        return true;
        //[[1,1,2,2],[1,1,2,2],[2,1,3,2]]
        //[[0,0,1,1],[0,0,2,1],[1,0,2,1],[0,2,2,3]]由此得还是要增加4个点是外围且面积和相等的限制条件
    }
};
// @lc code=end

