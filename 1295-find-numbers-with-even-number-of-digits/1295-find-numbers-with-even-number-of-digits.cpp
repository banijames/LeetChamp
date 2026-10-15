class Solution {
public:
    int findNumbers(vector<int>& nums) {
        //using to string
        int length = 0;
        for(int i:nums){
            string s = to_string(i);
            if(s.size()%2==0){
                length++;
            }
        }
        return length;
    }
};