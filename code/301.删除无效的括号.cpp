/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
class Solution {
public:
    //把整体分段变成一个一个思考，还挺简单!!!!逐个遍历，分情况处理，不要自己吓唬自己想复杂！
    //想好+用笔推一遍再写！！！！！
    //help(tmp,cnt_left,cnt_right,0,pos,fixed);
    //开始写题前确定原则是否正确：solution-)多的时候一定处理完整知道()平衡再下一段->错误，处理完全，也可以保持(多的状态不变因为要返回所有可能结果...
    //决定重写:cnt_left，cnt_right当前串;sum_left,sum_right当前加未来所有可能
    //1.确定最优解串长度：遍历sum_left,sum_right时候算每一对,这样可得(应删除的数目)
    //2.dfs针对每段重复串(((,)))，确定遍历范围(列方程组)
    void help(string& s,string tmp,int cnt_left,int cnt_right,int& res_pair,int pos,vector<string>& res){
        while(pos < s.size()&&s[pos] != '('&&s[pos] != ')'){
            tmp += s[pos++];
        }
        if(pos >= s.size()){
            if(cnt_left == res_pair&&cnt_right == res_pair) res.emplace_back(tmp);
            return;
        }
        if(cnt_right == res_pair){
            if(cnt_left == res_pair) help(s,tmp,cnt_left,cnt_right,res_pair,pos + 1,res);
            return;
        }
        int next = pos;
        while(next< s.size()&&s[next] == s[pos]) ++next;
        int num = next - pos;
        if(s[pos] == '('){
            help(s,tmp,cnt_left,cnt_right,res_pair,next,res);
            int cnt = min(num,res_pair - cnt_left);
            for(int i = 0;i < cnt;++i){
                tmp += '(';
                ++cnt_left;
                help(s,tmp,cnt_left,cnt_right,res_pair,next,res);
            }
        }
        else {
            help(s,tmp,cnt_left,cnt_right,res_pair,next,res);
            int cnt = min(num,res_pair - cnt_right);
            for(int i = 0;i < cnt;++i){
                ++cnt_right;
                tmp += ')';
                if(cnt_right > cnt_left) return;
                help(s,tmp,cnt_left,cnt_right,res_pair,next,res);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int res_pair = 0,pre_left = 0;
        for(const char&c : s){
            if(c == ')'){
                if(pre_left > 0) {
                    --pre_left;
                    ++res_pair;
                }
            }
            else if(c == '('){ 
                ++pre_left;
            }
        }
        vector<string> res;
        help(s,"",0,0,res_pair,0,res);
        return res;
    }
    //"(((k()((" 注意(可以不删光 k()
    //")()))())))" 注意)可以删光(())->刀子
};
// @lc code=end

