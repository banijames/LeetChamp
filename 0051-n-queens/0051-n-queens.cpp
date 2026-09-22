class Solution {
private:
    bool isSafe(int row, int col, vector<string>& grid, int n){
        //backward row
        for(int j=col-1; j>=0; j--){
            if(grid[row][j]=='Q'){
                return false;
            }
        }
        //upward col
        for(int i=row-1; i>=0; i--){
            if(grid[i][col]=='Q'){
                return false;
            }
        }
        //upward left diagonal
        for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        //downward left diagonal
        for(int i=row+1,j=col-1; i<n && j>=0; i++,j--){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        
        return true;

    }
    void solve(int n, int col, vector<vector<string>>& ans, vector<string>& grid){
            //reached the destination
            if(col==n){
                ans.push_back(grid);
                return;
            }
            for(int row=0;row<n;row++){
                if(isSafe(row,col,grid,n)){
                    grid[row][col]='Q';//after safety check placing the queen
                    solve(n,col+1,ans,grid);
                    grid[row][col]='.';//backtrack
                }
            }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>grid(n,string(n,'.'));//full dot n*n matrix
        vector<vector<string>>ans;
        solve(n,0,ans,grid);
        return ans;
    }
};