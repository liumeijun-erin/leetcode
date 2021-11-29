/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 */

// @lc code=start
class Solution {
public:
    vector<int> quickSort(vector<vector<int> >& f, int& k, int& p, int& q) {
        vector<int> front = f[p];
        if (p == q) return front;
        int pp = p, qq = q;
        while(pp < qq) {
            while (pp < qq&&f[qq][0] * front[1] > f[qq][1] * front[0]) --qq;
            swap(f[qq],f[pp]);
            while (pp < qq&&f[pp][0] * front[1] < f[pp][1] * front[0]) ++pp;
            swap(f[qq],f[pp]);
        }
        //cout<<p<<" "<<q<<" "<<pp<<":"<<front[0]<<"/"<<front[1]<<endl;
        if (qq - p + 1 > k) {
            q = pp - 1;
            front = quickSort(f, k ,p, q);
        }
        else if (qq - p + 1 < k) {
            k -= qq - p + 1;
            p = pp + 1;
            front = quickSort(f, k ,p, q);
        }
        return front;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<vector<int> > f;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i+1; j < arr.size(); ++j) {
                f.emplace_back(vector<int> {arr[i], arr[j]});
            }
        }
        int p = 0, q = f.size() - 1;
        return quickSort(f,k,p,q);
    }
    //[1,13,17,59]\n6
};
// @lc code=end

