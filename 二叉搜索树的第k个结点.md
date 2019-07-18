# 剑指offer - 二叉搜索树的第k个结点
题目描述： 给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。

## 解题思路：
- 中序遍历一遍二叉树，存储中序序列，输出第k个元素即可;


### 解法一：
- 中序遍历，并存储中序序列
- 注意对k的判断。超过序列长度的标号应返回空指针。

```c++
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<TreeNode*> inOrder;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==nullptr||k==0){return nullptr;}
        inOrderTraversal(pRoot);

        TreeNode* result = k<=inOrder.size() ? inOrder[k-1]: nullptr;
        return result;
    }


    void inOrderTraversal(TreeNode* pointer){
        if(pointer->left!= nullptr){inOrderTraversal(pointer->left); }
        inOrder.push_back(pointer);
        if(pointer->right!=nullptr){inOrderTraversal(pointer->right);}
    }


};
```
