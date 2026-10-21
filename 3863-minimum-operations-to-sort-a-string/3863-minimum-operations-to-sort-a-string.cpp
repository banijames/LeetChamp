class Solution {
public:
    int minOperations(string s) {
       
        
        //in case of already sorted
        bool isSorted = true;
        for(int i=1; i<s.length(); i++){
            if(s[i]<s[i-1]){
                isSorted = false;
                break;
            }
        }
        if(isSorted) return 0;
        if(s.length()==2 && !isSorted){
            return -1;
        }

        //find global min and max
        char mn=s[0] , mx=s[0];
        for(char ch : s){
            mn=min(mn,ch);//stores the minimum value in the string
            mx=max(mx,ch);//stores the maximum value in the string
        }

        // Case 3: Smallest is at the start OR largest is at the end
        //since we can take sub string of length -1
        if (s[0] == mn || s[s.length() - 1] == mx) {
            return 1;
        }

        // Case 4: Largest at the start AND smallest at the end
        if (s[0] == mx && s[s.length() - 1] == mn) {
            bool helper = false;
        
            // Scan strictly the middle characters
            for (int i = 1; i < s.length() - 1; i++) {
                if (s[i] == mx || s[i] == mn) {
                    helper = true;
                    break;
                }
            }
    
            // If no helpers exist in the middle, we are truly trapped
            if (!helper) {
                return 3;
            }
        }
        // Case 5: Everything else
        return 2;
    }
};