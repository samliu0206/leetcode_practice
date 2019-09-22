class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        int mx[len] = {0}, nx[len] = {0};
        for(int i=0;i<len;i++){
            mx[i] = count(strs[i].begin(), strs[i].end(), '0');
            nx[i] = count(strs[i].begin(), strs[i].end(), '1');
            //cout << mx[i] << " " << nx[i] << "\n";
        }
        int dp[len][m+1][n+1];
        for(int i=0;i<len;i++)
            for(int j=0;j<=m;j++)
                for(int k=0;k<=n;k++)
                    dp[i][j][k]=0;
        for(int j=0;j<=m;j++)
                for(int k=0;k<=n;k++)
                {
                    if (j - mx[0] >= 0 && k - nx[0]>=0) {
                        dp[0][j][k] = 1;
                    }
                }
        for (int i=1; i<len; i++) {
            for (int j=0; j<=m; j++) {
                for (int k=0; k<=n; k++){
                    if (j - mx[i] >= 0 && k - nx[i]>=0) {
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-mx[i]][k-nx[i]] + 1);
                    }else {
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        //dp[i][j][k]
        for (int i=0; i<len; i++) {
            for (int j=0; j<=m; j++) {
                for (int k=0; k<=n; k++){
                    //cout << dp[i][j][k];
                }
                //cout << "\n";
            }
            //cout << "\n";
        }
        cout << dp[len-1][m][n];
        return dp[len-1][m][n];
    }
};
