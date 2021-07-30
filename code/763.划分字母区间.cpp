/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int> > cnt(26,vector<int> {500,-1});
        for(int i = 0;i < s.length();i++){
            int key = s[i]-'a';
            cnt[key][0]= min(cnt[key][0],i);
            cnt[key][1]= max(cnt[key][1],i);
        }
        sort(cnt.begin(),cnt.end(),[](const vector<int> & a,const vector<int> & b){return a[0] < b[0];});
        vector<int> res;
        int i = 25;
        while(i >=0 && cnt[i][1] == -1) --i;
        int left = cnt[0][0],right = cnt[0][1];
        for(int j = 1;j <= i;j++){
            if(cnt[j][0] > right) {
                res.push_back(right -left + 1);
                left = cnt[j][0];
                right = cnt[j][1];
            }
            else {
                right = max(cnt[j][1],right);
            }
        }
        //注意结尾不要忘了！！最后一段！
        res.push_back(right -left + 1);
        return res;
    }
};
// @lc code=end

