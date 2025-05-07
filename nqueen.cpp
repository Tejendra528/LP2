#include <iostream>
#include <vector>
using namespace std;

const int N = 8; // You can change N as needed

void solve(int row, vector<int>& colUsed, vector<int>& diag1, vector<int>& diag2, vector<int>& board) {
    if (row == N) {
        for (int i = 0; i < N; i++)
            cout << board[i] << " ";
        cout << endl;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (!colUsed[col] && !diag1[row - col + N - 1] && !diag2[row + col]) {
            board[row] = col;
            colUsed[col] = diag1[row - col + N - 1] = diag2[row + col] = 1;

            solve(row + 1, colUsed, diag1, diag2, board);  // Recursive step

            // Backtrack
            colUsed[col] = diag1[row - col + N - 1] = diag2[row + col] = 0;
        }
    }
}

int main() {
    vector<int> colUsed(N, 0), diag1(2 * N - 1, 0), diag2(2 * N - 1, 0), board(N);
    cout << "Solutions to " << N << "-Queens using Backtracking with B&B:\n";
    solve(0, colUsed, diag1, diag2, board);
    return 0;
}
