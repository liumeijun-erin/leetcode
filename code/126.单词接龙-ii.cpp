/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution {
    vector<vector<int> > res1;//保存当前节点左前一位，以便倒序求解
    vector<vector<int> > res2;//保存当前节点右后一位，以便倒序求解
public:
    //solution1-超时:完全使用回溯法，搜索的同时保存路径+大于当前min路径的要被剪枝
    //bug：listlen为95的时候显示超时了
    //分析:这里用深搜确实很慢，很多重复搜索，又不是需要所有路径
    //反思：n皇后等排列组合/要一条/所有通路问题可深搜/回溯
    //求最短路径，哪怕是所有是一定要bfs的
    /*void backtracking(vector<vector<string> >& ans,vector<vector<int> >& dist,vector<int> & res,vector<int>& visited,int src,int dst,vector<string>& wordList){
        if(src == dst){
            res.emplace_back(dst);
            if(!ans.empty()&&res.size() < ans[0].size()) ans.clear();
            if(ans.empty()||res.size() == ans[0].size()){
                vector<string> tmp;
                for(const int& index:res){
                    tmp.emplace_back(wordList[index]);
                }
                ans.emplace_back(tmp);
            }
            res.pop_back();
            return ;
        }
        if(!ans.empty()&&res.size() >= ans[0].size()) return;
        visited[src] = 1;
        res.emplace_back(src);
        for(int i = 0;i < wordList.size();++i){
            if(dist[src][i] == 1&&!visited[i]) {
                backtracking(ans,dist,res,visited,i,dst,wordList);
            }
        }
        visited[src] = 0;
        res.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int src = 0,dst = -1;
        for(const string& ss:wordList){
            if(ss == beginWord) src = -1;
        }
        if(!src) wordList.emplace_back(beginWord); 
        int n = wordList.size();
        //cout<<n<<endl;
        vector<vector<int> > dist(n,vector<int> (n,0));
        for(int i = 0;i < n;++i){
            if(wordList[i] == beginWord) src = i;
            if(wordList[i] == endWord) dst = i;
            dist[i][i] = 0;
            for(int j = i+1;j < n;++j){
                int cnt = 0;
                for(int k = 0;k < beginWord.size();++k){
                    if(wordList[i][k]!=wordList[j][k]) ++cnt;
                }
                dist[i][j] = dist[j][i] = cnt;
            }
        }
        ////cout<<src<<" "<<dst<<endl;
        vector<int> res;
        vector<vector<string> > ans;
        if(dst == -1) return ans;
        vector<int> visited(n,0);
        visited[src]  = 1;
        res.emplace_back(src);
        for(int i = 0;i < n;i++){
            if(dist[src][i] == 1&&!visited[i]) backtracking(ans,dist,res,visited,i,dst,wordList);
        }
        return ans;
    }*/
    //solution2：65%-41% bfs同时保存答案+逆序使用回溯法重建！
    /*void backtracking(vector<vector<string> > &ans, vector<vector<int> > &res,vector<string> & path,vector<string> & wordList,int &src,int pos){
        path.emplace_back(wordList[pos]);
        if(pos == src){
            //reverse 没有返回值
            reverse(path.begin(),path.end());
            ans.emplace_back(path);
            reverse(path.begin(),path.end());
        }
        else{
            for(const int pre:res[pos]) backtracking(ans,res,path,wordList,src,pre);
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int src = 0,dst = -1;
        for(const string& ss:wordList){
            if(ss == beginWord) src = -1;
        }
        if(!src) wordList.emplace_back(beginWord); 
        int n = wordList.size();
        vector<vector<int> > dist(n,vector<int> (n,0));
        for(int i = 0;i < n;++i){
            if(wordList[i] == beginWord) src = i;
            if(wordList[i] == endWord) dst = i;
            dist[i][i] = 0;
            for(int j = i+1;j < n;++j){
                int cnt = 0;
                for(int k = 0;k < beginWord.size();++k){
                    if(wordList[i][k]!=wordList[j][k]) ++cnt;
                }
                dist[i][j] = dist[j][i] = cnt;
            }
        }
        vector<vector<int> > res(n);//保存当前节点前一位，以便倒序求解
        vector<vector<string> > ans;
        if(dst == -1) return ans;
        vector<int> visited(n,0);
        int cnt = 1;
        visited[src]  = cnt++;
        queue<int> q;
        q.emplace(src);
        //bfs找到所有最短路径
        while(!q.empty()){
            int len = q.size();
            //cout<<len<<endl;
            while(len--){
                int t = q.front();
                q.pop();
                for(int i = 0;i < n;++i){
                    if((!visited[i]||visited[i] == cnt)&&dist[i][t]==1){
                        //cout<<i<<endl;
                        res[i].emplace_back(t);
                        if(i == dst) break;
                        //这里出现问题：visited[i] == cntres要继续算，但是不能重复加到q里
                        if(!visited[i]) q.emplace(i);
                        visited[i] = cnt;
                    }
                }
            }
            if(!res[dst].empty()) break;
            ++cnt;
        }
        //cout<<cnt<<endl;
        //dfs(回溯，因为对path进行回改）+逆序找到具体路径
        vector<string> path;
        backtracking(ans,res,path,wordList,src,dst);
        return ans;
    }*/
    //solution3：参考答案利用数据特性从两端开始搜索!!
    //参考答案:利用尾巴固定两侧同时bfs，选宽度小的更进一步降低搜索复杂度！！
    //性能没有明显提高：65/40，可能精简传递的数据结构/使用map、set等能faster
    void backtracking(vector<vector<string> > &ans, vector<vector<int> > &res,vector<string> & path,vector<string> & wordList,int &src,int pos){
        path.emplace_back(wordList[pos]);
        if(pos == src){
            //reverse 没有返回值
            reverse(path.begin(),path.end());
            ans.emplace_back(path);
            reverse(path.begin(),path.end());
        }
        else{
            for(const int pre:res[pos]) backtracking(ans,res,path,wordList,src,pre);
        }
        path.pop_back();
    }
    void bfs(vector<vector<string> > &ans,queue<int> &q,vector<vector<int> >&res,vector<int> &visited,vector<int> & other,vector<vector<int> > &dist,int&cnt,int&dst,int&src,vector<string>& wordList,bool& find){
        int len = q.size();
        while(len--){
            int t = q.front();
            q.pop();
            for(int i = 0;i < visited.size();++i){
                if((!visited[i]||visited[i] == cnt)&&dist[i][t]==1){
                    res[i].emplace_back(t);
                    if(!visited[i]) q.emplace(i);
                    visited[i] = cnt;
                    if(visited[i]&&other[i]) {
                        //bug1:这里出现问题，右端已达，而左端多路可达的时候重复计算了
                        find= true;
                    }
                }
            }
        }
        ++cnt;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int src = 0,dst = -1;
        for(const string& ss:wordList){
            if(ss == beginWord) src = -1;
        }
        if(!src) wordList.emplace_back(beginWord); 
        int n = wordList.size();
        vector<vector<int> > dist(n,vector<int> (n,0));
        for(int i = 0;i < n;++i){
            if(wordList[i] == beginWord) src = i;
            if(wordList[i] == endWord) dst = i;
            dist[i][i] = 0;
            for(int j = i+1;j < n;++j){
                int cnt = 0;
                for(int k = 0;k < beginWord.size();++k){
                    if(wordList[i][k]!=wordList[j][k]) ++cnt;
                }
                dist[i][j] = dist[j][i] = cnt;
            }
        }
        vector<vector<string> > ans;
        if(dst == -1) return ans;
        res1.resize(n);
        res2.resize(n);
        vector<int> visited1(n,0);
        vector<int> visited2(n,0);
        int cnt = 1;
        visited1[src]  = cnt++;
        visited2[dst]  = cnt++;
        queue<int> q1;
        q1.emplace(src);
        queue<int> q2;
        q2.emplace(dst);
        //双向bfs找到所有最短路径
        //双向同时也可/或参考答案每次选择size小的，faster
        //同时这里回溯的时候也是分两半在合并
        bool find = false;
        while(!q1.empty()&&!q2.empty()){
            if(q1.size() <= q2.size()) bfs(ans,q1,res1,visited1,visited2,dist,cnt,dst,src,wordList,find);
            else bfs(ans,q2,res2,visited2,visited1,dist,cnt,dst,src,wordList,find);
            if(find) break;
        }
        //dfs(回溯，因为对path进行回改）+逆序找到具体路径
        vector<string> s;
        for(int i = 0;i < n;++i){
         if(visited1[i]&&visited2[i]){
                cout<<i<<endl;
                cout<<"from_begin_res:";
                for (int j = 0 ; j < res1[i].size(); ++j) {
                    cout<<res1[i][j]<<" ";
                }
                cout<<endl;
                cout<<"from_end_res:";
                for (int j = 0 ; j < res2[i].size(); ++j) {
                    cout<<res2[i][j]<<" ";
                }
                cout<<endl;
                vector<vector<string> > ans1,ans2;
                vector<string> path1,path2;
                backtracking(ans1,res1,path1,wordList,src,i);
                backtracking(ans2,res2,path2,wordList,dst,i);
                for(vector<string>& s2:ans2){
                    //bug2:这里注意insert和reverse都对s1和s2有影响
                    //note:多次利用的值不要被影响！！
                    reverse(s2.begin(),s2.end());
                }
                for(vector<string> &s1:ans1){
                    for(vector<string> &s2:ans2){
                        //s1.insert(s1.end(),s2.begin()+1,s2.end());
                        s.assign(s1.begin(),s1.end());
                        s.insert(s.end(),s2.begin()+1,s2.end());
                        ans.emplace_back(s);
                    }
                }
            }
        }
        return ans;
    }
};
//"cat"\n"fin"\n["ion","rev","che","ind","lie","wis","oct","ham","jag","ray","nun","ref","wig","jul","ken","mit","eel","paw","per","ola","pat","old","maj","ell","irk","ivy","beg","fan","rap","sun","yak","sat","fit","tom","fin","bug","can","hes","col","pep","tug","ump","arc","fee","lee","ohs","eli","nay","raw","lot","mat","egg","cat","pol","fat","joe","pis","dot","jaw","hat","roe","ada","mac"]
//"red"\n"tax"\n["ted","tex","red","tax","tad","den","rex","pee"]
// @lc code=end

