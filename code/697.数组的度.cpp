/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,pair<int,int> > cnt;
        int min_len = 50001;
        int maxm = -1;
        for(int i = 0;i < nums.size();i++){
            int num = nums[i];
            if(!cnt.count(num)) {
                cnt[num].first = i;
            }
            ++cnt[num].second;
            if(cnt[num].second > maxm){
                maxm = cnt[num].second;
                min_len = i - cnt[num].first + 1;
            }
            else if(cnt[num].second == maxm){
                min_len = min(i - cnt[num].first + 1,min_len);
            }
        }
        return min_len;
    }
};
// @lc code=end

