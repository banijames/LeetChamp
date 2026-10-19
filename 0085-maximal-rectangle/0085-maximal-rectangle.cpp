class Solution {
private:
    vector<int> nextSmaller(int *arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){
            int curr = arr[i];

            while(s.top()!=-1 && arr[s.top()]>=curr){
                s.pop();
            }

            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int>prevSmaller(int *arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            int curr = arr[i];

            while(s.top()!=-1 && arr[s.top()]>=curr){
                s.pop();
            }

            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(int *heights, int n) {
        vector<int> next(n);
        next = nextSmaller(heights,n);
        vector<int> prev(n);
        prev = prevSmaller(heights,n);

        int area = 0; // Changed from INT_MIN to 0
        for(int i=0;i<n;i++){
            int l = heights[i];

            if(next[i]==-1){
                next[i]=n;
            }

            int b = next[i]-prev[i]-1;

            int newArea = l*b;
            area = max(area,newArea);
        }
        return area;
    }
    
public:
    // LeetCode function signature uses vector<vector<char>>
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        // Use a 1D array to keep track of column heights
        vector<int> heights(col, 0);
        int maxArea = 0;
        
        // Loop from 0 to row, updating the heights array on each row
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                // If it's the character '1', increase height. If '0', reset to 0.
                if(matrix[i][j] == '1'){
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            // Pass the heights vector to your existing function
            maxArea = max(maxArea, largestRectangleArea(heights.data(), col));
        }
        return maxArea;
    }
};