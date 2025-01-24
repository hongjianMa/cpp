#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int pre[N], in[N], post[N];
int k;
// 定义二叉树节点结构体
struct node
{
    int value;   // 节点值
    node *l, *r; // 左右子树指针
    // 构造函数
    node(int value = 0, node *l = nullptr, node *r = nullptr) : value(value), l(l), r(r) {}
};
// 根据先序和中序构建二叉树
void buildTree(int l, int r, int &t, node *&root)
{
    int flag = -1;
    // 找到根节点在中序中的位置
    for (int i = l; i <= r; i++)
    {
        if (in[i] == pre[t])
        {
            flag = i;
            break;
        }
    }
    if (flag == -1)
        return;
    // 创建根节点
    root = new node(in[flag]);
    t++; // 更新先序遍历索引
    // 递归构建左子树
    if (flag > l)
        buildTree(l, flag - 1, t, root->l);
    // 递归构建右子树
    if (flag < r)
        buildTree(flag + 1, r, t, root->r);
}

// 后序遍历二叉树
void postorder(node *root)
{
    if (root != nullptr)
    {
        postorder(root->l);      // 遍历左子树
        postorder(root->r);      // 遍历右子树
        post[k++] = root->value; // 记录当前节点值
    }
}

// 删除二叉树
void removeTree(node *root)
{
    if (root == nullptr)
        return;
    removeTree(root->l); // 递归删除左子树
    removeTree(root->r); // 递归删除右子树
    delete root;         // 释放当前节点内存
}

// 主函数
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &pre[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &in[i]);
        node *root;
        int t = 1;
        // 构建二叉树
        buildTree(1, n, t, root);
        k = 0;
        // 后序遍历并记录结果
        postorder(root);
        for (int i = 0; i < k; i++)
        {
            printf("%d%c", post[i], i == k - 1 ? '\n' : ' ');
        }
        removeTree(root);
    }
    return 0;
}