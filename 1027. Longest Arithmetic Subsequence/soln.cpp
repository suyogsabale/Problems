
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> dp;
        int ans = 0;
        
        for(int i = 0; i < A.size(); i++){
            for(int j = i+1; j < A.size(); j++){
                int d = A[j]-A[i];
                //sequence length of d and ends at j
                /*
                when dp[d][i] not exist, 
                dp[d][j] is first of such sequence, 
                so its length is 2.
                otherwise, we can concat j to the previous sequence ends at i
                */
                dp[d][j] = (dp[d].find(i) != dp[d].end()) ? dp[d][i]+1 : 2;
                ans = max(ans, dp[d][j]);
            }
        }
        
        return ans;
    }
};