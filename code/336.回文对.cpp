/*
 * @lc app=leetcode.cn id=336 lang=cpp
 *
 * [336] 回文对
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<int> left(words.size());
        vector<int> right(words.size());
        vector<int> mul {1};
        int base = 131,mod = 1000000007;
        for(int i = 0;i < words.size();++i){
            while(words[i].size() >= mul.size()){
                int new_mul = ((long long) mul.back() * base) % mod;
                mul.emplace_back(new_mul);
            }
            for(int j = 0;j < words[i].size();++j){
                left[i] = ((long long) left[i] * base + (words[i][j] - 'a')) % mod;
                right[i] = (right[i] + (long long) mul[j] * (words[i][j] - 'a')) % mod;
            }
        }
        vector<vector<int> > res;
        for(int i = 0;i < words.size();++i){
            for(int j = i+1;j < words.size();++j){
                //if(i == j) continue;
                //cout<<i<<" "<<j<<endl;
                long long left1 = ((long long) left[i] * mul[words[j].size()])  % mod;
                long long right2 = ((long long) right[j] * mul[words[i].size()]) % mod;
                //cout<<(left1 + left[j])%mod<<" "<<(right2 + right[i])%mod<<endl;
                if((left1 + left[j])%mod == (right2 + right[i])%mod){
                    res.emplace_back(vector<int> {i,j});
                }
                long long left2 = ((long long) left[j] * mul[words[i].size()])  % mod;
                long long right1 = ((long long) right[i] * mul[words[j].size()]) % mod;
                if((left2 + left[i])%mod == (right1 + right[j])%mod){
                    res.emplace_back(vector<int> {j,i});
                }
            }
        }
        return res;
    }
};
// @lc code=end

