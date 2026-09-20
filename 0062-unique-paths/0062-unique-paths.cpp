class Solution {
private:
    private:
    int solve(int i, int j, int m, int n, vector<vector<int>>& path) {
        // Destination reached
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        // Outside the grid
        if (i == m || j == n) {
            return 0;
        }

        // Already calculated
        if (path[i][j] != -1) {
            return path[i][j];
        }

        int rightway = solve(i, j + 1, m, n, path);
        int downway = solve(i + 1, j, m, n, path);

        path[i][j] = rightway + downway;

        return path[i][j];
        
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>path(m,vector<int>(n,-1));
        return solve(0,0,m,n,path);
    }
};