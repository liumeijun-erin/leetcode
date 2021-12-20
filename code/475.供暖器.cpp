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
        int j = 0;
        int r1, r2;
        for (int i = 0; i < houses.size(); ++i) {
            while (j + 1 < heaters.size() && heaters[j+1] <= houses[i]) ++j;
            if (heaters[j] > houses[i]) r1 = heaters[j] - houses[i];
            else r1 = houses[i] - heaters[j];
            if (j + 1 < heaters.size()) {
                r2 = heaters[j+1] - houses[i];
                r1 = min(r2,r1);
            }
            res = max(res, r1);
        }
        return res;
    }
};
// @lc code=end

