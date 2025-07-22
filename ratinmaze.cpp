
bool maze[N][N] , sol[N][N]; 
bool isSafe(int i, int j) {
    return (i < N && j < N && maze[i][j] == 1);
}

// Function similar to: boolean solveMazeRec(int i, int j)
bool solveMazeRec(int i, int j) {
    if (i == N - 1 && j == N - 1) {
        sol[i][j] = 1;
        return true;
    }

    if (isSafe(i, j)) {
        sol[i][j] = 1;

        if (solveMazeRec(i + 1, j)) 
            return true;

        if (solveMazeRec(i, j + 1)) 
            return true;

        sol[i][j] = 0; 
    }

    return false;
}
bool solveMaze() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sol[i][j] = 0;

    if (!solveMazeRec(0, 0)) {
        cout << "Solution doesn't exist\n";
        return false;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << "\n";
    }

    return true;
}
