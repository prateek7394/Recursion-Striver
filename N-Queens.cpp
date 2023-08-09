// The n-queens puzzle is the problem of placing n queens on an n x n chessboard 
// such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. 
// You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, 
// where 'Q' and '.' both indicate a queen and an empty space, respectively.


#include<bits/stdc++.h>
using namespace std;

// --------------------- Method 1: Using naive method of checking safe position  -------------------------

bool isSafe(int row, int col, vector<string> board , int n){
    // check if a queen lies in same row on the LHS
    for(int j=0; j<col; j++){
        if(board[row][j]=='Q') return false;
    }

    // check if a queen lies in NW direction of curr pos
    int i=row-1, j=col-1;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }

    // check if a queen lies in SW direction of curr pos
    i=row+1;
    j=col-1;
    while(i<n && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i++;
        j--;
    }

    return true;
}
void helper(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0; row<n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            helper(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    string s(n, '.');
    vector<string> board(n, s);
    helper(0, board, ans, n);

    return ans;
}


// --------------------- Method 1: Using Hashing technique to check for safe position  -------------------------

void helper(int col, vector<string> &board, vector<vector<string>> &ans, int n, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0; row<n; row++){
        if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+(col-row)]==0){
            leftRow[row]=1;
            lowerDiagonal[row+col]=1;
            upperDiagonal[n-1+(col-row)]=1;


            board[row][col] = 'Q';
            helper(col+1, board, ans, n, leftRow, lowerDiagonal, upperDiagonal);
            board[row][col] = '.';

            leftRow[row]=0;
            lowerDiagonal[row+col]=0;
            upperDiagonal[n-1+(col-row)]=0;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    string s(n, '.');
    vector<string> board(n, s);
    vector<int> leftRow(n, 0);
    vector<int> lowerDiagonal(2*n-1, 0);
    vector<int> upperDiagonal(2*n-1, 0);
    helper(0, board, ans, n, leftRow, lowerDiagonal, upperDiagonal);
    return ans;
}

int main()
{
    return 0;
}