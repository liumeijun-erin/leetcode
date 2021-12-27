/*
 * @lc app=leetcode.cn id=825 lang=cpp
 *
 * [825] 适龄的朋友
 */

// @lc code=start
class Solution {
public:
    // x<=y && 2*(x-7) > y 
    // x > 14时本身也可以 [16,16]
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        sort(ages.begin(), ages.end());
        int id = 0, left = 1;
        while (id < ages.size()) {
            int tmp = id + 1;
            while (tmp < ages.size() && ages[tmp] == ages[id]) ++tmp;
            if (tmp > id + 1 && ages[id] > 14) res += (tmp-id) * (tmp-id-1);
            left = max(left, tmp);
            while (left < ages.size() && 2 * (ages[id] - 7) > ages[left]) ++left;
            // cout<<tmp<<" "<<left<<endl;
            res += (tmp-id)*(left-tmp);
            id = tmp;
        }
        return res;
    }
};
// @lc code=end

