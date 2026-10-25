class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> Strnums;
        //step 1 convert all integers to string
        for(int num : nums){
            Strnums.push_back(to_string(num));
        }
        //step 2 sort using custom comparator
        sort(Strnums.begin(),Strnums.end(),[](string &a,string &b){
            return a+b > b+a;
        });

        //edge case where array is just zeroes
        if(Strnums[0]=="0"){
            return "0";
        }
        //final answer
        string ans = "";
        for(string s:Strnums){
            ans+=s;
        }
        return ans;
    }
};