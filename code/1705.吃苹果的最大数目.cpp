/*
 * @lc app=leetcode.cn id=1705 lang=cpp
 *
 * [1705] 吃苹果的最大数目
 */

// @lc code=start
class Solution {
    struct cmp{
        bool operator() (pair<int,int> p1, pair<int,int> p2) {
            return p1.first > p2.first;
        }
    };
    
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        map<int,int> due;
        int day = 0;
        int res = 0;
        while (1) {
            if (day < apples.size() && apples[day]) {
                if (due.count(day + days[day])) due[day + days[day]] = apples[day];
                else due[day + days[day]] += apples[day];
            }
            while (!due.empty() && due.begin()->first <= day) due.erase(due.begin());
            if (!due.empty()) {
                ++res;
                --due.begin()->second;
                if(due.begin()->second == 0) due.erase(due.begin());
            }
            else if(day >= apples.size()) break;
            ++day;
        }
        return res;
    }
};
// @lc code=end

