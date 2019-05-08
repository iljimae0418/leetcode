class Solution {
public:
    const int INF = 987654321;  
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = number of ways to make up i 
        int dp[amount+1];  
        for(int i = 0; i<= amount; i++){
            dp[i] = INF;  
        }
        dp[0] = 0;  
        for (int i = 1; i <= amount; i++){
            for (int j = 0; j < coins.size(); j++){
                if (i-coins[j] >= 0){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);  
                }
            }
        }
        return (dp[amount] == INF ? -1 : dp[amount]);  
    }
};
