#include <iostream>
#include <vector>
using namespace std;

#define N 4

// Check if the current move is safe (within bounds and not blocked)
bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Recursive utility to solve the maze
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        sol[x][y] = 1;

        // Move right
        if (solveMazeUtil(maze, x, y + 1, sol))
            return true;

        // Move down
        if (solveMazeUtil(maze, x + 1, y, sol))
            return true;

        // Backtrack if no move is possible
        sol[x][y] = 0;
        return false;
    }

    return false;
}

// Print the solution path
void printSolution(int sol[N][N]) {
    cout << "Path from start to end:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

// Main function to solve the maze
void solveMaze(int maze[N][N]) {
    int sol[N][N] = { {0} };

    if (!solveMazeUtil(maze, 0, 0, sol)) {
        cout << "No path found." << endl;
    } else {
        printSolution(sol);
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    solveMaze(maze);
    return 0;
}