class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            int j=0;
            bool found = false;
            //find exact postion of element
            while(j < nums2.size() && nums2[j] != nums1[i]) {
                j++;
            }
            // 3. From that position onwards, search for the next strictly greater number
            for(int k = j + 1; k < nums2.size(); k++) {
                if(nums2[k] > nums1[i]) {
                    ans.push_back(nums2[k]);
                    found = true;
                    break; // Stop searching once we find the first greater element
                }
            }
        // 4. If we reached the end without finding a greater number
            if(found == false) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};