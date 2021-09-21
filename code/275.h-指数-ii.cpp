/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
//条件判断真的是一团糟，下次理清头绪在写
//理清思路：就是要第一个大于等于的然后返回n-right即可，这样其实很快
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(citations[n-1]<=0) return 0;
        if(citations[0]>=n) return n;
        int left = 0,right = n-1;
        while(left < right){
            int mid = (right-left)/2 + left;
            //这里不应该增加两个判断mid和mid+1直接输出，而是应该用left+right判断终止，much faster
            if(citations[mid]<n-mid) left = mid+1;
            else right = mid;
        }
        return n- right;
        //[0,1,3,5,6]
        //[1,2,100]
        //[1,2]
        //[0,1]
        //[0,0,4,4]
    }
};
// @lc code=end

