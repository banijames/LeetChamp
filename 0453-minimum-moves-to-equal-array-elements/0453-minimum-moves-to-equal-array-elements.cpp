class Solution {
public:
    int minMoves(vector<int>& nums) {
        //find the min element
        int mn = *min_element(nums.begin(),nums.end());
        //we need to find out the difference b/w all elements
        //and add the difference gives the output
        long long moves = 0;
        for(int x : nums){
            moves += x-mn;
        }
        return moves;
    }
};
//given question 
//case 1 if all elements are equal then return 0
//case 2 given array has n elements in which for each move we can increment
//n-1 elements by 1
//the main idea is to understand that we need identify in how many moves are
//required to get in to the min element in the array


