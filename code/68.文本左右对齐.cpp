/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int cnt,i = 0;
        while(i < words.size()){
            cnt = 0;
            int tmp = i;
            while(i < words.size()&&cnt + words[i].size()<= maxWidth){
                cnt += (words[i].size()+1);
                ++i;
            }
            --cnt;
            string s;
            if(i==words.size()&&cnt <= maxWidth||i-1==tmp){
                s = words[tmp++];
                while(tmp < i) {
                    s += " ";
                    s += words[tmp++];
                }
                while(s.size() < maxWidth) s+= " ";
            }
            else{
                //改正1：需要均匀分配maxWidth-cnt个空格到i-tmp-1个位置中
                int gap0 = (maxWidth-cnt)/(i-tmp-1)+1,gap;
                //cout<<gap0<<" "<<gap<<endl;
                s = "";
                for(int j = tmp;j < i-1;++j){
                    s += words[j];
                    gap = gap0;
                    if(j-tmp+1<=(maxWidth-cnt)%(i-tmp-1)) ++gap;
                    while(gap--) s += " ";
                }
                s += words[i-1];
            }
            //cout<<s.length()<<endl;
            res.emplace_back(s);
        }
        return res;
    }
    //["What","must","be","acknowledgment","shall","be"]\n16
    //["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]\20
};
// @lc code=end

