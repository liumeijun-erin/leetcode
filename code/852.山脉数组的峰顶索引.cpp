/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        /*for(int i = 1;i < arr.size()-1;++i){
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]) return i;
        }
        return -1;*/
        int i = 1,j = arr.size()-2;
        while(i < j){
            int k = (j-i)/2 + i;
            if(arr[k] <= arr[k-1]) j = k-1;
            else if(arr[k] <= arr[k+1]) i = k+1;
            else return k;
        }
        return i;
    }
};
// @lc code=end

