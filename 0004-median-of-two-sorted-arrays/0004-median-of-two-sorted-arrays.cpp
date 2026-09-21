class Solution {
private:
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int total = n1+n2;
        int i=0;
        int j=0;

        int prev = 0;
        int curr = 0;

        for(int count=0; count<=total/2; count++){
            prev = curr;//inorder to find the new current
            //for both i and j in range
            if(i<n1 && j<n2){
                if(nums1[i]<=nums2[j]){
                    curr=nums1[i++];
                }else{
                    curr=nums2[j++];
                }
            }
            else if(i<n1){
                curr = nums1[i++];
            }else{
                curr = nums2[j++];
            }
        }
        if(total%2==1){
            return curr;
        }else{
            return (prev+curr)/2.0;
        }
    }
};