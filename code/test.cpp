#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int _val) {
        val = _val;
    }
};

int main(){
    TreeNode* node = new TreeNode(1);
    cout<<node->val<<endl;
    return 0;

}