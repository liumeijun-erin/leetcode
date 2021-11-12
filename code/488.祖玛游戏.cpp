/*
 * @lc app=leetcode.cn id=488 lang=cpp
 *
 * [488] 祖玛游戏
 */

// @lc code=start
class Solution {
    unordered_map<string, int> hash;
public:
    // 唯二啥也不会的题 上一个是线段数组
    // 照着答案写了一个dfs + 从发球的角度出发开始剪枝 + 利用hash进行state记搜 + 较复杂功能要能拆出来 clean 
    // 有的时候不要总想着优化细节的堆叠。。。整体差不多写出来再说
    // 本题题意理解不清+测试用例超出思考范围+参考答案实现
    // note1:参考测试用例才想到：不一定有相同的才insert
    // note2:答案回溯遍历应用写法有意思，从hand手里发球角度出发，每个函数的作用就是往一个位置塞一个球,然后更新board+hand状态
    // TODO：我的写法是遍历位置，插入/不插，应该也可以吧...但是实在写不下去了
    // note3:记忆化搜错写法！！！unordered_map 结合str(board) + " " + str(hand:剩余手球)标记状态记录答案！
    // ！！！这里体现出遍历球而非位置的优越性：如果遍历球hash的时候就是最小的，不需要其他
    // note4：最后每处可以全清/全留--这点明确!!!
    // note5:参考答案：要么和一边相同的地方放置求，要么在相同的中间放球！！！这个没想到
    // ac中放b没有用，不起保护作用且添乱
    // note6：clean可以单独拆出一个函数
    // ...tricky...要考虑到可能在两边均不同的地方插入新球
    // eg1: "RRWWRRBBRR"\n"WB"--答案-2
    // RBRWWRRBBRR->RBRWWWRRBBRR-
    // eg2: "WWBBWBBWW"\n"BB"--答案-1
    // 2 key pnts:两侧不一定有相同的才insert；每处能清全清/不清
    // 现在思路遍历:
    // !!!!pos插入所有能插入的,而且每次插入不一定马上删；!!!!
    // !!!!删除所有能删除的!!!!
    // 参考答案：必须剪枝：比如插入颜色相同的球只在结束地方插入开始的时候不插；
    // tips：！！！dfs+记忆化搜索！！！因为会出现很多重复状态！！！
    //使用board + " "+ hand作为状态表示方法
    // dfs有点忘了都，可以不用&res 直接返回
    string clean(string s, int pos) {
        cout<<"clean:"<<s<<endl;
        while (pos >= 0 && pos < s.size()) {
            int next = pos + 1;
            while (pos > 0 && s[pos-1] == s[pos]) --pos;
            while (next < s.size() && s[next] == s[pos]) ++next;
            if(next - pos >= 3) s.erase(pos, next - pos);
            else break;
        }
        return s;
    }

    int help(string board, string& cnt) {
        if (board.size() == 0) return 0;
        if (hash.count(board + cnt)) return hash[board + cnt];  // 这个需要按球遍历才能实现
        int res = 6;  // 审题多余的条件
        // 按手里的球遍历
        for (int j = 0; j < cnt.size(); ++j) {
            if (cnt[j] == '0') continue; //剪枝1：相当于同色球剪枝
            char c = j + '0';
            for (int i = 0;i < board.size(); ++i) {
                if (i > 0 && board[i - 1] == c) continue;  // 剪枝2 插入与邻居相同的新球只在相同片段开头
                bool choose = false;
                if (i < board.size() && board[i] == c) choose = true;
                // 剪枝3 插入与邻居不同的新球只在相同片段中间：起拦截保护作用否则没用
                if (i > 0 && i < board.size() && board[i-1] == board[i] && board[i] != c) choose = true;
                if (choose) {
                    // board hand到底改不改要确定好,直接改，变拼接
                    string new_board = clean(board.substr(0,i) + c + board.substr(i), i);
                    --cnt[j];
                    res = min(res, help(new_board, cnt) + 1);
                    ++cnt[j];
                }
            }
        }
        hash[board+cnt] = res;
        //cout<<board+cnt<<" "<<res<<endl;
        return res;
    }
    int findMinStep(string board, string hand) {
        string cnt = "00000";
        for (const char& c:hand) {
            switch (c) {
                case 'R': ++cnt[0]; break;
                case 'Y': ++cnt[1]; break;
                case 'B': ++cnt[2]; break;
                case 'G': ++cnt[3]; break;
                case 'W': ++cnt[4]; 
            }
        }
        for (char &c: board) {
            switch (c) {
                case 'R': c = '0'; break;
                case 'Y': c = '1'; break;
                case 'B': c = '2'; break;
                case 'G': c = '3'; break;
                case 'W': c = '4'; 
            }
        }
        int res = help(board, cnt);
        if(res > 5) return -1;
        return res;
    }
    // "WWRRBBWW"\n"WRBRW"
    // "RBYYBBRRB"\n"YRBGB"
    // tricky:
    // "WWBBWBBWW"\n"BB"
    // "RRWWRRBBRR"\n"WB"
    // "BGGRRYY"\n"BBYRG"
};
// @lc code=end

