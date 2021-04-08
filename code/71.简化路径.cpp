/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        //note:cannot use str after clear/erase all letters
        //tip:necessary to take time to consider all(especially) complex situations,like: "/a/./b/../../c/"
        string new_path = "";
        for(int i = 0;i < path.length();i++){
            if(path[i] == '/'){
                if(new_path.length() && new_path[new_path.length() - 1] == '/') continue;
                else if(new_path.length() > 1 && new_path[new_path.length() - 1] == '.'){
                    if(new_path[new_path.size() - 2] == '/'){
                        new_path.erase(new_path.length()-1,1);
                        continue;
                    }
                    else if(new_path[new_path.size() - 2] == '.'){
                        if(new_path.size() > 2 && new_path[new_path.size() - 3] == '/'){
                            if(new_path.size() > 3) new_path.erase(new_path.size() - 3,3);
                            else new_path = "/";
                            int pos = new_path.rfind('/');
                            if(pos) new_path.erase(pos + 1,new_path.length() - pos - 1);
                            else new_path = "/";
                            continue;
                        }
                    }
                } 
            }
            new_path += path[i];
        }
        if(new_path[new_path.length() - 1] == '.' ){
            if(new_path[new_path.length() - 2] == '/'){
                new_path.erase(new_path.length() - 1,1);
            }
            else if(new_path[new_path.length() - 2] == '.' && new_path[new_path.length() - 3] == '/' ){
                if(new_path.size() > 3) new_path.erase(new_path.size() - 3,3);
                else new_path = "/";
                int pos = new_path.rfind('/');
                if(pos) new_path.erase(pos+1,new_path.length() - pos-1);
                else new_path = "/";
            }
        }   
        if(new_path.length() > 1 && new_path[new_path.length() - 1] == '/') new_path.erase(new_path.length() - 1,1);
        return new_path;
    }
};
// @lc code=end

