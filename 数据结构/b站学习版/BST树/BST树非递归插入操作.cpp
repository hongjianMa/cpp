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

    // 非递归查询操作
    bool n_query(const T &val)
    {
        Node *cur = root_;
        while (cur != nullptr)
        {
            if (cur->data_ == val)
            {
                return true;
            }
            else if (comp(cur->data_, val))
            {
                cur = cur->right;
            }
            else
            {
                cur = cur->left;
            }
        }
        return false;
    }

    // 递归插入操作
    void insert(const T &val)
    {
        root_ = insert(root_, val);
    }

    // 递归查询操作
    bool query(const T &val)
    {
        return nullptr != query(root_, val);
    }

    // 递归删除操作
    void remove(const T &val)
    {
        root_ = remove(root_, val);
    }

    // 递归前序遍历操作
    void preOrder()
    {
        cout << "[递归]前序遍历：";
        preOrder(root_);
        cout << endl;
    }

    // 递归中序遍历操作
    void inOrder()
    {
        cout << "[递归]中序遍历：";
        inOrder(root_);
        cout << endl;
    }

    // 递归后序遍历操作
    void postOrder()
    {
        cout << "[递归]后序遍历：";
        postOrder(root_);
        cout << endl;
    }

    // 递归层序遍历操作
    void levelOrder()
    {
        cout << "[递归]层序遍历：";
        int h = high(); // 树的层数
        for (int i = 0; i < h; i++)
        {
            levelOrder(root_, i);
        }
        cout << endl;
        cout << "BST树的层数为：" << h << endl;
        cout << "BST树的节点个数为：" << number() << endl;
    }

    // 递归求二叉树层数
    int high()
    {
        return high(root_);
    }

    // 递归求二叉树节点个数
    int number()
    {
        return number(root_);
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

    // 递归插入操作实现
    Node *insert(Node *node, const T &val)
    {
        if (node == nullptr)
        {
            // 递归结束，找到插入val的位置，生成新节点返回节点地址
            return new Node(val); // 生成新节点
        }
        if (node->data_ == val)
        {
            return node; // 相等不插入
        }
        else if (comp(node->data_, val)) // 当前节点比val小，往右边走
        {
            node->right = insert(node->right, val);
            return node;
        }
        else
        {
            node->left = insert(node->left, val);
            return node;
        }
        return node;
    }

    // 递归查询操作实现
    Node *query(Node *node, const T &val)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->data_ == val)
        {
            return node;
        }
        else if (comp(node->data_, val))
        {
            return query(node->right, val);
        }
        else
        {
            return query(node->left, val);
        }
    }

    // 递归删除操作实现
    Node *remove(Node *node, const T &val)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->data_ == val) // 找到待删除节点
        {
            // 情况3：有两个孩子
            if (node->left != nullptr && node->right != nullptr)
            {
                // 找前驱节点，右节点
                Node *prev = node->left;
                while (prev->right != nullptr)
                {
                    prev = prev->right;
                }
                node->data_ = prev->data_;
                // 通过递归直接删除前驱节点
                node->left = remove(node->left, prev->data_);
            }
            else // 情况1和情况2：最多有一个孩子或者没有孩子
            {
                if (node->left != nullptr)
                {
                    Node *left = node->left;
                    delete node;
                    return left;
                }
                else if (node->right != nullptr)
                {
                    Node *right = node->right;
                    delete node;
                    return right;
                }
                else // 删除没有
                {
                    delete node;
                    return nullptr;
                }
            }
        }
        else if (comp(node->data_, val))
        {
            node->right = remove(node->right, val);  // 记得更新当前孩子的右孩子
        }
        else
        {
            node->left = remove(node->left, val);
        }
        return node; // 把当前节点返回给父节点，更新父节点相应的地址域
    }

    // 递归前序遍历的实现 VLR
    void preOrder(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->data_ << " "; // 操作V
            preOrder(node->left);       // L
            preOrder(node->right);      // R
        }
    }

    // 中序遍历实现  LVR
    void inOrder(Node *node)
    {
        if (node != nullptr)
        {
            inOrder(node->left);
            cout << node->data_ << " ";
            inOrder(node->right);
        }
    }

    // 后序遍历实现 LRV
    void postOrder(Node *node)
    {
        if (node != nullptr)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data_ << " ";
        }
    }

    // 递归层序遍历的实现
    void levelOrder(Node *node, int i)
    {
        if (node == nullptr)
        {
            return;
        }
        if (i == 0) // 根节点
        {
            cout << node->data_ << " ";
            return;
        }
        levelOrder(node->left, i - 1);
        levelOrder(node->right, i - 1);
    }

    // 递归求二叉树层数  求以node为根节点的子树的高度并返回高度值
    int high(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int left = high(node->left);
        int right = high(node->right);
        return left > right ? left + 1 : right + 1;
    }

    // 递归求节点个数的实现 求以node为根节点的节点总数并返回
    int number(Node *node)
    {
        if (node == nullptr)
            return 0;
        int left = number(node->left);
        int right = number(node->right);
        return left + right + 1;
    }

    Node *root_; // 指向BST的根节点
    Comp comp;   // 定义一个函数对象
};

int main()
{
    int arr[] = {58, 24, 67, 0, 34, 62, 69, 5, 41, 64, 78};
    BSTree<int> bst;
    for (int v : arr)
    {
        bst.insert(v);
    }
    bst.n_insert(12);
    // bst.n_remove(58);//

    bst.preOrder();
    bst.inOrder();    
    bst.postOrder();
    bst.levelOrder();
    bst.remove(58);
    bst.levelOrder();
    // if (bst.query(12))
    //     cout << "找到了";
    return 0;
}
