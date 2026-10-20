class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //optimized code
        unordered_map<int, int> nextGreater;
        stack<int> s;

        for(int num : nums2){
            //while stack is not empty and current elment greater thean stack top
            while(!s.empty() && s.top()<num){
                nextGreater[s.top()]= num;
                s.pop();
            }
            // Push current number to stack to find its next greater element later
            s.push(num);
        }
        // Step 2: Build the result array for nums1
        vector<int> ans;
        for(int num: nums1){
            if(nextGreater.count(num)){
                ans.push_back(nextGreater[num]);
            }else{
                ans.push_back(-1);
            }
        }
        
        return ans;
        
        
        
        
        
        
        
        
        //brute force approach
        // vector<int> ans;
        // for(int i=0; i<nums1.size(); i++){
        //     int j=0;
        //     bool found = false;
        //     //find exact postion of element
        //     while(j < nums2.size() && nums2[j] != nums1[i]) {
        //         j++;
        //     }
        //     // 3. From that position onwards, search for the next strictly greater number
        //     for(int k = j + 1; k < nums2.size(); k++) {
        //         if(nums2[k] > nums1[i]) {
        //             ans.push_back(nums2[k]);
        //             found = true;
        //             break; // Stop searching once we find the first greater element
        //         }
        //     }
        // // 4. If we reached the end without finding a greater number
        //     if(found == false) {
        //         ans.push_back(-1);
        //     }
        // }
        // return ans;
    }
};