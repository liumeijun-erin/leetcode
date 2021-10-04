/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int i = s.size()-1,j = s.size()-1,cnt = 0;
        while(j >= 0&&s[j] == '-') --j;
        for(i = s.size()-1;i >= 0&&j>=0;--i){
            if(s[j] >= 'a'&& s[j] <= 'z') s[j] += ('A'-'a');
            s[i] = s[j--];
            ++cnt;
            while(j >= 0&&s[j] == '-') --j;
            if(j>=0&&!(cnt%k)) s.insert(s.begin()+i,'-');
        }
        if(i>=0){
            s.erase(s.begin(),s.begin()+i+1);
        }
        return s;
    }
    //"abc-abc"\n3
    //"--a-a-a-a--"\n2
};
// @lc code=end

