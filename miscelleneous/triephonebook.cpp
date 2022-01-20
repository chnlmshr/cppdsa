#include <bits/stdc++.h>

using namespace std;

class Trie
{
public:
    Trie()
    {
        isLeaf = false;
    }
    unordered_map<char, Trie *> children;
    bool isLeaf;
    vector<string> possibilities;
    void insert(string s)
    {
        auto root = this;
        for (auto &n : s)
        {
            if (!root->children[n])
            {
                root->children[n] = new Trie();
            }
            root->children[n]->possibilities.push_back(s);
            root = root->children[n];
        }
        root->isLeaf = true;
    }
    vector<vector<string>> search(string s)
    {
        auto root = this;
        vector<vector<string>> res;
        for (auto &n : s)
        {
            if (root->children[n])
            {
                res.push_back(root->children[n]->possibilities);
                root = root->children[n];
            }
            else
                return res;
        }
        return res;
    }
};

vector<vector<string>> displayContacts(int n, vector<string> contact, string s)
{
    Trie root;
    cout << "here";
    for (int i = 0; i < n; i++)
        root.insert(contact[i]);
    cout << "here";
    return root.search(s);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto ss = displayContacts(3, {"geeikistest", "geeksforgeeks", "geeksfortest"}, "geeips");

    return 0;
}