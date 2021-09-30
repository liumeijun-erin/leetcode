/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        if(ax1>bx1) {
            swap(ax1,bx1);
            swap(ax2,bx2);
            swap(ay1,by1);
            swap(ay2,by2);
        }
        int area_a = abs((ax1-ax2)*(ay1-ay2));
        int area_b = abs((bx1-bx2)*(by1-by2));
        if(by1 >= ay2||bx1 >= ax2||by2<=ay1) return area_a + area_b;
        int overlap_w = 0,overlap_h = 0;
        overlap_h = min(ay2,by2) - max(ay1,by1);
        overlap_w = min(bx2,ax2) - bx1;
        return area_a + area_b - overlap_h * overlap_w;
    }
    //-2\n-2\n2\n2\n-4\n3\n-3\n4
    //-2\n-2\n2\n2\n-2\n2\n2\n4
};
// @lc code=end

