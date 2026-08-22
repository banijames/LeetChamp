class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        if(days>n) return -1;

        int s = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            s=max(s,weights[i]);
            sum+=weights[i];
        }
        int e = sum;
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            int num_days=1;
            int num_weights=0;
            for(int i=0; i<n; i++){
                if(num_weights+weights[i]<=mid){
                    num_weights+=weights[i];
                }else{
                    num_days++;
                   num_weights=weights[i];
                }
            }
            if(num_days<=days){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid+1;
            }
        }
        return ans;

    }
};