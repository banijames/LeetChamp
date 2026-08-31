class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int rowIndex = 0;
        int maxCount = 0;

        for(int i=0; i<mat.size(); i++){
            //current occurenece of 1s
            int currentOnes = 0;
            //column
            for(int j=0; j<mat[i].size(); j++){
                currentOnes+=mat[i][j];
            }

            if(currentOnes > maxCount){
                maxCount = currentOnes;
                rowIndex = i;
            }
        }
           return {rowIndex, maxCount};
    }
};