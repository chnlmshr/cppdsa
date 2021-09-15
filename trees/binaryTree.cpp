#include <bits/stdc++.h>

using namespace std;

class Node
{
  int data;
  Node *left, *right;

public:
  Node(int data)
  {
    this->data = data;
  }
  Node(int data, Node *left, Node *right)
  {
    this->data = data;
    this->left = left;
    this->right = right;
  }
};

class BinaryTree
{
  Node *root;
  void insert(int n)
  {
  }
};

int main()
{
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  return 0;
}