#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define sz(x) ((int)x.size())
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define rrep(i, a, b) for(int i = b; i >= a; i--)

bool canPlace(vector<vector<int>>& board, int i, int j, int n, int num) {

    for(int x = 0; x < n; x++) {
        if(board[i][x] == num  ||  board[x][j] == num)
            return false;
    }

    int rn = sqrt(n);
    int i_sb = i / rn * rn;
    int j_sb = j / rn * rn;
    for(int x = 0; x < rn; x++) {
        for(int y = 0; y < rn; y++) {
            if(board[i_sb + x][j_sb + y] == num)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>>& board, int i, int j, int n) {
    if(i == n) {
        cout <<  "-----------------\n";
        rep(i, 0, n - 1){
            rep(j, 0, n - 1) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    if(j == n)
        return solve(board, i + 1, 0, n);

    if(board[i][j] != 0)
        return solve(board, i, j + 1, n);

    for(int num = 1; num <= n; num++) {
        if(canPlace(board, i, j, n, num)) {
            board[i][j] = num;
            bool is_solved = solve(board, i, j + 1, n);
            if(is_solved) {
                return true;
            }
        }
    }
    //Backtracking step
    board[i][j] = 0;
    return false;
    
}

signed main()
{ 
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    cout << "Enter 4 or 9 for solving 2x2 or 3x3 sudoku : \n";
    int n; cin >> n;
    cout << "Enter the sudoku with 0 as blank spaces : \n";

    vector<vector<int>> board(n, vector<int>(n));

    rep(i, 0, n - 1)
        rep(j, 0, n - 1)
            cin >> board[i][j];

    bool ans = solve(board, 0, 0, n);
    if(!ans)
        cout << "Wrong Sudoku !" << endl;

    return 0;
}