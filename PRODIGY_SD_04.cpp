#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
const int N = 9;

bool isSafe(std::vector<std::vector<int>>& grid, int row, int col, int num) {
    // Check if the number is already present in the row or column
    for (int i = 0; i < N; ++i) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check if the number is present in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool findEmptyLocation(std::vector<std::vector<int>>& grid, int& row, int& col) {
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(std::vector<std::vector<int>>& grid) {
    int row, col;

    if (!findEmptyLocation(grid, row, col)) {
        // If no empty location is found, the puzzle is solved
        return true;
    }

    for (int num = 1; num <= 9; ++num) {
        if (isSafe(grid, row, col, num)) {
            // Try placing the number in the current location
            grid[row][col] = num;

            // Recur to solve the rest of the puzzle
            if (solveSudoku(grid)) {
                return true;
            }

            // If placing the number leads to no solution, backtrack
            grid[row][col] = 0;
        }
    }

    // No number can be placed in the current location
    return false;
}

void printGrid(const std::vector<std::vector<int>>& grid) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> sudokuGrid(N, std::vector<int>(N, 0));

    // Input Sudoku puzzle
    cout << "Enter the Sudoku puzzle row-wise (0 for empty cells):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> sudokuGrid[i][j];
        }
    }

    if (solveSudoku(sudokuGrid)) {
        cout << "\nSolved Sudoku Puzzle:\n";
        printGrid(sudokuGrid);
    } else {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}
