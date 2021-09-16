/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 */

// @lc code=start
class Solution {
public:
    //solution1:使用string，slow
    /*string toBinary(int a){
        string s ="";
        while(a){
            if(a%2) s = "1"+s;
            else s= "0"+s;
            a = a/2;
        }
        return s;
    }*/
    bool validUtf8(vector<int>& data) {
        /*
        int cnt = 0;
        for(const int& d:data){
            string s = toBinary(d);
            //cout<<s<<endl;
            if(cnt){
                if(s.size()!=8) return false;
                else if(s[1]!='0') return false;
                else --cnt;
            }
            else{
                if(s.size()==8){
                    int i = 0;
                    while(s[i]=='1') ++i;
                    cnt = i;
                    if(cnt==1||cnt > 4) return false;
                    --cnt;
                }
                else if(s.size()>8) return false;
            }
        }
        if(cnt) return false;
        return true;*/
        //solution2:使用纯数faster
        int cnt = 0;
        for(const int& d:data){
            if(cnt){
                if(d<128||d>191) return false;
                else --cnt;
            }
            else{
                if(d>128){
                    if(d < 192) return false;
                    else if(d < 224) cnt = 1;
                    else if(d < 240) cnt = 2;
                    else if(d < 248) cnt = 3;
                    else return false;
                }
            }
        }
        if(cnt) return false;
        return true;
    }
    //[255],注意结尾加判断cnt是否归零
    //[145],注意审题10-不可
};
// @lc code=end

 