#include <iostream>
#include <vector>

using namespace std;

const int N = 9;


void printgrid(const vector<vector<int>>& grid) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}


bool isSafe(const vector<vector<int>>& grid, int row, int col, int num) {
    for (int x = 0; x < N; ++x) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }
    int startrow = row - row % 3;
    int startcol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + startrow][j + startcol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& grid) {
    int row, col;
    bool found = false;
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            if (grid[row][col] == 0) {
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    if (!found) {
        return true;
    }
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true;
            }
            
            grid[row][col] = 0; 
        }
    }
    return false;
}

int main() {
    vector<vector<int>> grid(N, vector<int>(N, 0)); 

    cout << "Enter the Sudoku puzzle (Enter 0 for empty cells):\n";
    for (int i = 0; i < N; ++i) {
        cout << "Enter numbers for row " << i + 1 << ": ";
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    if (solveSudoku(grid)) {
        cout << "Solution\n";
        printgrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle.\n";
    }

    return 0;
}