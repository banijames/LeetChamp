class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int min_no = *min_element(nums.begin(),nums.end());
        int max_no = *max_element(nums.begin(),nums.end());

        vector<int> ans;

        for(int i=min_no; i<=max_no; i++){
            if(!seen.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};