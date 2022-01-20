#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define int long long int
void build_tree(int tree[], int start, int end, int index)
{
  if (start == end)
  {
    tree[index] = 1;
  }
  else
  {
    int mid = (start + end) / 2;
    build_tree(tree, start, mid, 2 * index);
    build_tree(tree, mid + 1, end, 2 * index + 1);
    tree[index] = tree[2 * index] + tree[2 * index + 1];
  }
}
void update(int tree[], int start, int end, int left, int right, int lazy[], int index)
{
  if (lazy[index] != 0)
  {
    tree[index] = end - start + 1 - tree[index];
    if (start != end)
    {
      lazy[2 * index] ^= 1;
      lazy[2 * index + 1] ^= 1;
    }
    lazy[index] = 0;
  }
  if (left > end || start > right)
    return;
  else if (start >= left && end <= right)
  {
    tree[index] = end - start + 1 - tree[index];
    if (start != end)
    {
      lazy[2 * index] ^= 1;
      lazy[2 * index + 1] ^= 1;
    }
    return;
  }
  else
  {
    int mid = (start + end) / 2;
    update(tree, start, mid, left, right, lazy, 2 * index);
    update(tree, mid + 1, end, left, right, lazy, 2 * index + 1);
    tree[index] = tree[2 * index] + tree[2 * index + 1];
  }
}
int sum_query(int tree[], int start, int end, int left, int right, int lazy[], int index)
{
  if (lazy[index] != 0)
  {
    tree[index] = end - start + 1 - tree[index];
    if (start != end)
    {
      lazy[2 * index] ^= 1LL;
      lazy[2 * index + 1] ^= 1LL;
    }
    lazy[index] = 0;
  }
  if (left > end || start > right)
    return 0;
  else if (start >= left && end <= right)
    return tree[index];
  else
  {
    int mid = (start + end) / 2;
    int x = sum_query(tree, start, mid, left, right, lazy, 2 * index);
    int y = sum_query(tree, mid + 1, end, left, right, lazy, 2 * index + 1);
    return x + y;
  }
}
void dfs(int src, vector<int> adj[], int p, int size[], map<int, int> &mp, int &count)
{
  count++;
  mp[src] = count;
  size[src] = 1;
  for (int x : adj[src])
  {
    if (x != p)
    {
      dfs(x, adj, src, size, mp, count);
    }
  }
  for (int x : adj[src])
  {
    if (x != p)
      size[src] += size[x];
  }
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> adj[n];
  int j;
  for (j = 0; j < n - 1; j++)
  {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int tree[4 * n + 1] = {0};
  int lazy[4 * n + 1] = {0};
  map<int, int> mp;
  int count = -1;
  int size[n] = {0};
  dfs(0, adj, -1, size, mp, count);
  build_tree(tree, 0, n - 1, 1);
  int q;
  cin >> q;
  while (q--)
  {
    int query;
    cin >> query;
    if (query == 1)
    {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      if (size[u] < size[v])
      {
        int temp = u;
        u = v;
        v = temp;
      }
      int total = sum_query(tree, 0, n - 1, 0, n - 1, lazy, 1);
      int node = mp[v];
      count = size[v];
      int sub = sum_query(tree, 0, n - 1, node, node + count - 1, lazy, 1);
      int count2 = total - sub;
      int answer = sub * count2;
      cout << answer << endl;
    }
    else
    {
      int u;
      cin >> u;
      u--;
      int node = mp[u];
      count = size[u];
      update(tree, 0, n - 1, node, node + count - 1, lazy, 1);
    }
  }
}