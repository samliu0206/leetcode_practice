class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        //cout << len << "\n";
        int dp[amount+1] = {0};
        dp[0]=1;
        for(int i=0;i<len;i++){
            for(int j=1; j<=amount; j++){
                if(j>=coins[i]){
                    dp[j] += dp[j-coins[i]];
                    //cout << dp[j] << " " ;
                }
            }
            cout << "\n";
        }
        
        return dp[amount];
    }
};
