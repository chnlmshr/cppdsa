#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode()
    {
        this->val = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class Tree
{
public:
    TreeNode *root;
    Tree()
    {
        this->root = new TreeNode();
    }

    void insert(int n)
    {
        if (this->root->val == 0)
        {
            this->root = new TreeNode(n);
        }
        else
        {
            queue<TreeNode *> q;
            q.push(this->root);
            while (!q.empty())
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                else
                {
                    node->left = new TreeNode(n);
                    break;
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
                else
                {
                    node->right = new TreeNode(n);
                    break;
                }
            }
        }
    }
};

void inOrder(TreeNode *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->val;
    inOrder(root->right);
}

int height(TreeNode *root)
{
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int diameter(TreeNode *root)
{
    if (!root)
        return 0;

    return max(1 + height(root->left) + height(root->right), max(diameter(root->left), diameter(root->right)));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Tree *t = new Tree();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        t->insert(a);
    }
    // inOrder(t->root);
    // cout << height(t->root);
    cout << diameter(t->root);
    return 0;
}