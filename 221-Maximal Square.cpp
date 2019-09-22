class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())return 0;
        int len = matrix[0].size();
        int row = matrix.size();
        
        int dp[row][len];
        for(int i=0;i<row;i++){
            for(int j=0;j<len;j++){
                //cout << matrix[i][j];
                if(matrix[i][j] == '1')
                    dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
            
        for(int i=1;i<row;i++){
            for(int j=1;j<len;j++){
                if(dp[i][j]!=0)
                    dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;        
                
            }
        }
        
        int max = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<len;j++){
                cout << matrix[i][j] << " ";
                if(dp[i][j]>=max)max=dp[i][j];
            }
            cout << "\n";

        }
        return max*max;
    }
};
