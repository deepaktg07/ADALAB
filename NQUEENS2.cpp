#include <iostream>
using namespace std;
bool isSafe(int** board, int x, int y, int n) {
    for (int row = 0; row < x; row++) {
        if (board[row][y] == 1) return false;
    }
    int row = x, col = y;
    while (row >= 0 && col >= 0) {
        if (board[row][col] == 1) return false;
        row--; col--;
    }
    row = x; col = y;
    while (row >= 0 && col < n) {
        if (board[row][col] == 1) return false;
        row--; col++;
    }
    return true;
}
void printBoard(int** board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void nQueen(int** board, int x, int n, int& count) {
    if (x >= n) {
        count++;
        cout << "Solution " << count << ":\n";
        printBoard(board, n);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, x, col, n)) {
            board[x][col] = 1;
            nQueen(board, x + 1, n, count);
            board[x][col] = 0;
        }
    }
}
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int count = 0;
    int** board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n]();
    }
    nQueen(board, 0, n, count);
    cout << "Number of solutions: " << count << endl;
    return 0;
}
