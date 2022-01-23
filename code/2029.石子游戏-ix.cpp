/*
 * @lc app=leetcode.cn id=2029 lang=cpp
 *
 * [2029] 石子游戏 IX
 */

// @lc code=start
class Solution {
public:
    // 本题不会，参考答案
    // 策略类问题：多写几步
    // 看题解：
    // 对于类型为0的棋子：如果有偶数个，相当于没有；奇数个等价于只有一个
    // 对于类型为12的棋子：序列分为两种情况
    // alice-11212121212..
    // alice-22121212121..
    // p1-只有0:奇数alice输，偶alice输
    // p2-偶数个0：
    // bob获胜：alice先破坏规则+支撑到最后一个石子
    // alice获胜：bob必须先破坏规则
    // 总结：bob获胜
    // situation1:1 + num(2) < num(1)-1 ; 无2则a输; 1 + num(2) == num(1)
    // situation2:1 + num(1) < num(2)-1 ; 无1则a输; 1 + num(1) == num(2)
    //总结：alice获胜
    // 有1有2 (&& num(2)+2 >= num(1) || num(1)+2 >= num(2))
    // p3-奇数个0：利用对调在没有类型0石子的情况下，Bob 获胜且原因不是因为所有石子都被移除
    // situation1:1 + num(2) < num(1)-1 ; 无2则a输
    // situation2:1 + num(1) < num(2)-1 ; 无1则a输
    // ！！！取反思想
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int val: stones) {
            if (val % 3 == 0) {
                ++cnt0;
            }
            else if (val % 3 == 1) {
                ++cnt1;
            }
            else {
                ++cnt2;
            }
        }
        if (cnt0 % 2 == 0) {
            return cnt1 >= 1 && cnt2 >= 1;
        }
        return cnt1 - cnt2 > 2 || cnt2 - cnt1 > 2;
    }
};
// @lc code=end

