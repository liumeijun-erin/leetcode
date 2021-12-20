/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */

// @lc code=start
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int i = 0, j = 0;
        if (heaters[j] > houses[i]) {
            res = heaters[j] - houses[i];
            while (i < houses.size() && houses[i] <= heaters[j]) ++i;
        }
        while (j + 1 < heaters.size()) {
            int mid = (heaters[j + 1] + heaters[j])/2;
            while (i < houses.size() && houses[i] <= heaters[j + 1]) {
                if(houses[i] <= mid) res = max(houses[i] - heaters[j],res);
                else res = max(heaters[j+1] - houses[i],res);
                ++i;
            }
            ++j;
        }
        if (i < houses.size()) {
            res = max(res, houses[houses.size()-1] - heaters[j]);
        }
        return res;
    }
};
// @lc code=end

