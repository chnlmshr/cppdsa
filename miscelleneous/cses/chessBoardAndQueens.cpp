#include <bits/stdc++.h>

using namespace std;

const int N = 8;

bool isSafe(string *board, int x, int y) {
  for (int row = 0; row < x; row++)
    if (board[row][y] == '#')
      return false;

  int row = x;
  int col = y;
  while (row >= 0 && col >= 0)
    if (board[row--][col--] == '#')
      return false;

  row = x;
  col = y;
  while (row >= 0 && col >= 0) {
    if (board[row--][col++] == '#')
      return false;
  }
  return true;
}

void backTrack(string *board, int row, int &cnt) {
  if(row == N-1) {
    for(int col = 0; col < N; col++) {
      if(board[row][col] == '.' and isSafe(board, row, col)) {
        cnt++;
      }
    }
  } else {
    for(int col = 0; col < N; col++) {
      if(board[row][col] == '.' and isSafe(board, row, col)) {
        board[row][col] = '#';
        backTrack(board, row+1, cnt);
        board[row][col] = '.';
      }
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  string board[N];
  for(int i = 0; i < N; i++) cin >> board[i];
  int cnt = 0;
  backTrack(board, 0, cnt);
  cout << cnt << "\n";
  return 0;
}