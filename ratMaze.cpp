#include <bits/stdc++.h>
using namespace std;

//Name: Bibaswan Roy
//The 1s represent the path, and 0s are blocks

const int n = 4;

bool isSafe(int (*maze)[n], int r, int c)
{
    if(maze[r][c] == 1 && r < n && c < n)
        return true;
    return false;
}

void solPrint(int sol[n][n])
{
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << sol[i][j] << "  ";
        cout << endl;
    }
}


bool mazeSolver(int maze[n][n], int sol[n][n], int r, int c)
{
    if(r == n-1 && c == n-1 && maze[r][c] == 1)
    {
        sol[r][c] = 1;
        return true;
    }
    sol[r][c] = 1;
    if(isSafe(maze, r, c))
    {
        if(mazeSolver(maze, sol, r+1, c))
            return true;
        if(mazeSolver(maze, sol, r, c+1))
            return true;
    }
    sol[r][c] = 0;
    return false;
}

int main()
{
    int maze[n][n] = {{1, 1, 0, 0},
                      {0, 1, 1, 1},
                      {0, 1, 0, 1},
                      {1, 1, 0, 1}};
    int sol[n][n] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};
    
    if(mazeSolver(maze, sol, 0, 0))
    solPrint(sol);
    else
    {
        cout << "\nThe rat cannot escape";
    }
    
    return 0;
}