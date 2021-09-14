/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    //策略：最短路径类问题不能用dfs，所有路径用dfs
    //参考答案：优化策略-双向bfs
    int diff(string& s1,string&s2){
        int d = 0;
        for(int i= 0;i < s1.size();++i){
            if(s1[i]!=s2[i]){
                if(d) return -1;
                ++d;
            }
        }
        return d;
    }
    //tip1:审题!begin word可以不在wordList里
    //tip2:由于超时，所以更改存储方法为vector<set<>>
    //tip4:一旦出现中间样例超时一定要想整体思路改进，抠细节没用
    //tip5：边界条件和非重复遍历是一定不能忘的!
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        if(!n) return 0;
        int begin = -1,end = -1;
        //vector<vector<int> > d(n,vector<int> (n,-1));
        vector<set<int> > d(n,set<int> {});
        for(int i = 0;i < n;++i){
            if(wordList[i]==beginWord) begin = i;
            else if(wordList[i]==endWord) end = i;
            for(int j = i+1;j < n;++j){
                int df = diff(wordList[i],wordList[j]);
                if(df == 1) {
                    d[i].emplace(j);
                    d[j].emplace(i);
                }
            }
        }
        if(end==-1) return 0;
        vector<int> visited(n,0);
        queue<int> q1,q2;
        int cnt1 = 1,cnt2 = -1;
        visited[end] = cnt2--;
        q2.emplace(end);
        //int res = n + 2;
        if(begin!=-1){
            visited[begin] = cnt1++;
            q1.emplace(begin);
        }
        else{
            cnt1++;
            if(diff(beginWord,endWord)==1) return 2;
            for(int i = 0;i < n;++i){
                if(diff(beginWord,wordList[i])==1){
                    if(visited[i]) return 3;
                    visited[i]=cnt1;
                    q1.emplace(i);
                }
            }
            cnt1++;
        }
        while(!q1.empty()&&!q2.empty()){
            int len = q1.size();
            while(len--){
                int f = q1.front();
                q1.pop();
                for(auto iter= d[f].begin();iter!=d[f].end();iter++){
                    if(visited[*iter]<0) {
                        return cnt1-visited[*iter]-1;
                        //continue;
                        //return res;
                    }
                    if(visited[*iter] > 0) continue;
                    visited[*iter] = cnt1;
                    q1.emplace(*iter);
                }
            }
            cnt1++;
            len = q2.size();
            while(len--){
                int f = q2.front();
                q2.pop();
                for(auto iter= d[f].begin();iter!=d[f].end();iter++){
                    if(visited[*iter]>0) {
                        return visited[*iter]-cnt2-1;
                        //continue;
                        //return res;
                    }
                    if(visited[*iter] < 0) continue;
                    //遍历问题一定要有visited防止闭环
                    visited[*iter] = cnt2;
                    q2.emplace(*iter);
                }
            }
            --cnt2;
        }
        return 0;
        //"hit"\n"cog"\n["hot","cog","dot","dog","hit","lot","log"]
        //tip3:!注意这种特殊情况，右侧标记碰上右侧标记
        //"cet"\n"ism"\n["kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"]
        //"ymain"\n"oecij"\n["ymann","yycrj","oecij","ymcnj","yzcrj","yycij","xecij","yecij","ymanj","yzcnj","ymain"]
        //tip6:想到是不是有一个就是最小的了！！！两层相交之后不会再更新
        //tip7:层次遍历cnt记录层次而不是node个数！    
    }
};
// @lc code=end

