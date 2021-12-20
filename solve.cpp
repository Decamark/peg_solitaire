#include <bits/stdc++.h>
using namespace std;

enum Cell { S, P, W };
// vector<vector<Cell>> board = {
//   { W, W, W, W, W, W, W, W, W, W, W },
//   { W, W, W, W, W, W, W, W, W, W, W },
//   { W, W, W, W, P, P, P, W, W, W, W },
//   { W, W, W, W, P, P, P, W, W, W, W },
//   { W, W, P, P, P, P, P, P, P, W, W },
//   { W, W, P, P, P, S, P, P, P, W, W },
//   { W, W, P, P, P, P, P, P, P, W, W },
//   { W, W, W, W, P, P, P, W, W, W, W },
//   { W, W, W, W, P, P, P, W, W, W, W },
//   { W, W, W, W, W, W, W, W, W, W, W },
//   { W, W, W, W, W, W, W, W, W, W, W }
// };

// vector<vector<Cell>> board = {
//   { W, W, W, W, W, W, W, W, W, W, W },
//   { W, W, W, W, W, W, W, W, W, W, W },
//   { W, W, W, W, S, S, S, W, W, W, W },
//   { W, W, W, W, S, S, S, W, W, W, W },
//   { W, W, P, P, S, S, S, P, P, W, W },
//   { W, W, P, P, P, S, P, P, P, W, W },
//   { W, W, P, P, P, P, P, P, P, W, W },
//   { W, W, W, W, P, P, P, W, W, W, W },
//   { W, W, W, W, P, P, P, W, W, W, W },
//   { W, W, W, W, W, W, W, W, W, W, W },
//   { W, W, W, W, W, W, W, W, W, W, W }
// };

vector<vector<Cell>> board = {
  { W, W, W, W, W, W, W, W, W, W, W },
  { W, W, W, W, W, W, W, W, W, W, W },
  { W, W, W, W, S, S, S, W, W, W, W },
  { W, W, W, W, S, S, S, W, W, W, W },
  { W, W, P, P, S, S, S, S, S, W, W },
  { W, W, P, P, P, P, P, S, S, W, W },
  { W, W, P, P, P, S, P, S, S, W, W },
  { W, W, W, W, P, S, P, W, W, W, W },
  { W, W, W, W, P, P, P, W, W, W, W },
  { W, W, W, W, W, W, W, W, W, W, W },
  { W, W, W, W, W, W, W, W, W, W, W }
};

ostream& operator<<(ostream& os, Cell cell)
{
  if (cell == W) os << 'W';
  else if (cell == S) os << 'S';
  else os << 'P';
  return os;
}

void show()
{
  for (int i=2; i<9; i++) {
    for (int j=2; j<9; j++)
      cout << board[i][j] << ' ';
    cout << endl;
  }
}

int mn = 32;

bool search(int n)
{
  if (n < mn) { mn = n; cout << "updated: " << mn << endl;; }
  if (n == 1) return true;

  bool theEnd = true;

  for (int i=2; i<9; i++)
    for (int j=2; j<9; j++) {
      if (board[i][j] == W or board[i][j] == P) continue;

      if (board[i-1][j] == P and board[i-2][j] == P)
      {
        theEnd = false;
        board[i][j] = P; board[i-1][j] = S; board[i-2][j] = S;
        if (search(n-1)) {
          cout << "(" << i-2 << "," << j << ")" << " -> " << "(" << i << "," << j << ")" << endl;
          show();
          board[i][j] = S; board[i-1][j] = P; board[i-2][j] = P;
          return true;
        }
        board[i][j] = S; board[i-1][j] = P; board[i-2][j] = P;
      }
      if (board[i][j+1] == P and board[i][j+2] == P)
      {
        theEnd = false;
        board[i][j] = P; board[i][j+1] = S; board[i][j+2] = S;
        if (search(n-1)) {
          cout << "(" << i << "," << j+2 << ")" << " -> " << "(" << i << "," << j << ")" << endl;
          show();
          board[i][j] = S; board[i][j+1] = P; board[i][j+2] = P;
          return true;
        }
        board[i][j] = S; board[i][j+1] = P; board[i][j+2] = P;
      }
      if (board[i+1][j] == P and board[i+2][j] == P)
      {
        theEnd = false;
        board[i][j] = P; board[i+1][j] = S; board[i+2][j] = S;
        if (search(n-1)) {
          cout << "(" << i+2 << "," << j << ")" << " -> " << "(" << i << "," << j << ")" << endl;
          show();
          board[i][j] = S; board[i+1][j] = P; board[i+2][j] = P;
          return true;
        }
        board[i][j] = S; board[i+1][j] = P; board[i+2][j] = P;
      }
      if (board[i][j-1] == P and board[i][j-2] == P)
      {
        theEnd = false;
        board[i][j] = P; board[i][j-1] = S; board[i][j-2] = S;
        if (search(n-1)) {
          cout << "(" << i << "," << j-2 << ")" << " -> " << "(" << i << "," << j << ")" << endl;
          show();
          board[i][j] = S; board[i][j-1] = P; board[i][j-2] = P;
          return true;
        }
        board[i][j] = S; board[i][j-1] = P; board[i][j-2] = P;
      }
    }
  // if (theEnd) {
  //   cout << "--------------" << endl;
  //   show();
  // }
  return false;
}

int main()
{
  int pnum = 0;
  for (int i=2; i<9; i++)
    for (int j=2; j<9; j++)
      if (board[i][j] == P) pnum++;
  search(pnum);
}
