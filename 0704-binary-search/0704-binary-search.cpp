class Solution {
public:
    int recursivesearch(vector<int>& nums, int target, int s, int e){
        if(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                return recursivesearch(nums,target,mid+1,e);
            }
            else{
                return recursivesearch(nums,target,s,mid-1);
            }
        }
        return -1;
    }
    int search(vector<int>& nums,int target){
        int e = nums.size()-1;
        return recursivesearch(nums,target,0,e);
    }
};