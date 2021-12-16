/*
 * @lc app=leetcode.cn id=1610 lang=cpp
 *
 * [1610] 可见点的最大数目
 */

// @lc code=start
class Solution {
public:
    // acos 对应0-1
    double countAngle(const vector<int>& src,const vector<int>& pnt) {
        double x_d = pnt[0] - src[0];
        double y_d = pnt[1] - src[1];
        double angle = acos(x_d / sqrt(x_d * x_d + y_d * y_d)) / M_PI  * 180;
        // cout<<angle<<endl;
        if (y_d > 0) angle = 360 - angle;
        return angle;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> pnt_angle;
        int same_loc = 0;
        for (const vector<int>& point: points) {
            if (point[0] == location[0] && point[1] == location[1]) ++same_loc;
            else pnt_angle.emplace_back(countAngle(location, point));
        }
        // vector<int> test_s {0,0};
        // vector<int> test_p {0,-1};
        // cout<<countAngle(test_s, test_p)<<endl;
        sort(pnt_angle.begin(), pnt_angle.end());
        // for (const double& angle: pnt_angle) {
        //     cout<<angle<<" ";
        // }
        // cout<<endl;
        int i = 0, j = 0, res = 0, tmp = 0;
        while(i < pnt_angle.size()) {
            //cout<<i<<" "<<j<<endl;
            while (j < i + pnt_angle.size()) {
                if (j < pnt_angle.size() && pnt_angle[j] > pnt_angle[i] + angle) break;
                else if (j >= pnt_angle.size() && pnt_angle[j % pnt_angle.size()] + 360 -  pnt_angle[i] > angle) break;
                ++j;
            }
            res = max(res, j - i);
            if (j == i + pnt_angle.size()) break;
            ++i;
        }
        return res + same_loc;
    }
    //[[41,7],[22,94],[90,53],[94,54],[58,50],[51,96],[87,88],[55,98],[65,62],[36,47],[91,61],[15,41],[31,94],[82,80],[42,73],[79,6],[45,4]]\n17\n[6,84]
};
// @lc code=end

