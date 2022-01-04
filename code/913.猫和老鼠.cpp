/*
 * @lc app=leetcode.cn id=913 lang=cpp
 *
 * [913] 猫和老鼠
 */

// @lc code=start
const int MAXN = 51;
class Solution {
public:
    // 本题不会：参考答案--!!!!!!!博弈问题，interesting！！！
    // dp(a_id,b_id,turn)+递归+反证法
    //(利用反证法，turns >= 2n(0不可达),若mouse回到已去过位置，由于cat最优策略所以位置只能更有利于cat必胜/必败；
    // 同理mouse也是。所以肯定回到原位置 不断循环下去)
    // 策略：
    // * 当前状态可以胜利，选择胜利
    // * 否则递归：
    // * 当前状态后存在选择导致必败，留给对方必败
    // * 当前状态后所有选择都是必胜，主动选择求和
    // keypnt1：动态规划!!!:模拟博弈过程
    // keypnt2：dp[mouse][cat][turns]: turns%2-cat, turns%2==1-mouse
    // tip：turns>=2n的时候一定平局(由于最优策略).详见官方解析
    int m_n;
    vector<vector<int>> m_graph;
    int m_dp[MAXN][MAXN][2*MAXN];  // mouse, cat, turns
    int catMouseGame(vector<vector<int>>& graph) {
        memset(m_dp, -1, sizeof(dp));
        m_n = graph.size();
        m_graph = graph;
        return getResult(1,2,0);
    }
    int getResult(int mouse, int cat, int turns) {
        if (turns >= 2 * n) return 0;
         if (dp[mouse][cat][turns] < 0) {
            if (mouse == 0) {
                dp[mouse][cat][turns] = 1;
            } else if (cat == mouse) {
                dp[mouse][cat][turns] = 2;
            } else {
                getNextResult(mouse, cat, turns);
            }
        }
        return dp[mouse][cat][turns];
    }
    int getNextResult(mouse, cat, turns) {
        int curMove = turns % 2 == 0 ? mouse : cat;
        int defaultResult = curMove == mouse ? 2 : 1;
        int result = defaultResult;
        for (int next : graph[curMove]) {
            if (curMove == cat && next == 0) {
                continue;
            }
            int nextMouse = curMove == mouse ? next : mouse;
            int nextCat = curMove == cat ? next : cat;
            int nextResult = getResult(nextMouse, nextCat, turns + 1);
            if (nextResult != defaultResult) {
                result = nextResult;
                if (result != DRAW) {
                    break;
                }
            }
        }
        dp[mouse][cat][turns] = result;
    }
};
// @lc code=end

