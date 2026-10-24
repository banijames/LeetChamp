class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;

        //creating a vector of strings for each row
        vector<string>rows(min(numRows,int(s.length())));//only create for specific no of rows
        int curRow = 0;
        bool goingDown = false;

        //traverse the string and place at appropriate rows
        for(char c:s){
            rows[curRow]+=c;

            //change rows at bottom and top
            if(curRow == 0 || curRow == numRows -1){
                goingDown = !goingDown;
            }

            //move up or down
            curRow += goingDown? 1 : -1;
        }
        //combine all rows together
        string result;
        for(string row : rows){
            result+=row;
        }
        return result;
    }
};