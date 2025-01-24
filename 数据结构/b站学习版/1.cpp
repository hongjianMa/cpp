#include <iostream>
#include <functional>
using namespace std;

// BST树代码实现
template <typename T, typename Comp = less<T>>
class BSTree
{
public:
    BSTree() : root_(nullptr) {}
    ~BSTree() {}

public:
    // 非递归插入操作
    void n_insert(const T val)
    {
        if (root_ == nullptr)
        {
            root_ = new Node(val);
            return;
        }
        Node *cur = root_;
        Node *parent = nullptr;
        while (cur != nullptr)
        {

            if (cur->data_ == val)
                return;                     // 等于关系
            else if (comp(cur->data_, val)) // 小于关系
            {
                parent = cur;
                cur = cur->right;
                /* code */
            }
            else // 大于关系
            {
                parent = cur;
                cur = cur->left;
            }
        }

        if (comp(val, parent->data_)) // 小于关系
        {
            parent->left = new Node(val);
        }
        else
        {
            parent->right = new Node(val);
        }
    }

    // 非递归删除操作
    void n_remove(const T val)
    {
        if (root_ == nullptr)
            return;

        Node *parent = nullptr;
        Node *cur = root_;
        while (cur != nullptr)
        {
            if (cur->data_ == val)
                break;
            else if (comp(val, cur->data_))
            {
                parent = cur;
                cur = cur->left;
            }
            else
            {
                parent = cur;
                cur = cur->right;
            }
        }

        // 没找到待删除节点
        if (cur == nullptr)
        {
            return;
        }

        // 处理情况 3
        if (cur->left != nullptr && cur->right != nullptr)
        {
            parent = cur;
            Node *pre = cur->left;
            while (pre->right != nullptr)
            {
                parent = pre;
                pre = pre->right;
            }
            cur->data_ = pre->data_;
            cur = pre; // 让cur指向前驱节点，转化成情况1，2
        }

        // cur指向删除节点， parent指向其父节点，统一处理情况1，2
        Node *child = cur->left;
        if (child == nullptr)
            child = cur->right;

        if (parent == nullptr) // 处理特殊情况，删除根节点
        {
            root_ = child;
        }
        else
        {
            // 把待删除的节点（nullptr或者不空）写入其父节点
            if (parent->left == cur)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
        }
        delete cur; // 删除当前节点
    }

private:
    // 节点定义
    struct Node
    {
        Node(T data = T()) : data_(data), left(nullptr), right(nullptr) {}
        T data_;     // 数据域
        Node *left;  // 左孩子
        Node *right; // 右孩子
    };

    Node *root_; // 指向BST的根节点
    Comp comp;   // 定义一个函数对象
};

int main()
{
    int arr[] = {58, 24, 67, 0, 34, 62, 69, 5, 41, 64, 78};
    BSTree<int> bst;
    for (int v : arr)
    {
        bst.n_insert(v);
    }
    bst.n_insert(12);
    bst.n_remove(58);
    return 0;
}
