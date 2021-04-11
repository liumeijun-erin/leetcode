/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int count[10] = {0};
        int countB = 0;
        int countA = 0;
        for(int i = 0;i < secret.length();i++){
            if(secret[i] == guess[i]){
                countA++;
                continue;
            }
            if(count[secret[i]-'0'] < 0){
                countB++;
            }
            if(count[guess[i]-'0'] > 0){
                countB++;
            }
            count[secret[i]-'0']++;
            count[guess[i]-'0']--;
        }
        return to_string(countA)+"A"+to_string(countB)+"B";
    }
};
// @lc code=end

