class Solution {
private:
    private:
    int gridways(int i, int j, int m, int n, vector<vector<int>>& memo) {
        // Destination reached
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        // Outside the grid
        if (i == m || j == n) {
            return 0;
        }

        // Already calculated
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int rightway = gridways(i, j + 1, m, n, memo);
        int downway = gridways(i + 1, j, m, n, memo);

        memo[i][j] = rightway + downway;

        return memo[i][j];
        
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return gridways(0,0,m,n,memo);
    }
};