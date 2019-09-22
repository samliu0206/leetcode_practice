class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            sum = (sum + nums[i]);
        }
        if(sum%2!=0){
            return false;
        }
        sum = sum/2;
        //cout << sum/2;
        int dp[n+1][sum+1] = {0};
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++)
                dp[i][j] = 0;
         dp[0][0] = 1;
        for(int i=1;i<n+1;i++)
            dp[i][0] = 1;
        for(int j=1;j<sum+1;j++)
            dp[0][j] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j>=nums[i-1]){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        /*for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++)
                cout << dp[i][j] << " ";
            cout << "\n";
        }*/
            
        return dp[n][sum];
        
    }
};
