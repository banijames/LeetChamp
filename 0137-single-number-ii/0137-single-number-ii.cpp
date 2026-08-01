class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0;
        int twos=0;

        for(int i=0; i<nums.size(); i++){
            twos = twos | (ones&nums[i]);

            ones = ones^nums[i];

            int threes= ones&twos;

            ones = ones & ~threes;
            twos = twos & ~threes;
        }
        return ones;
    }
};