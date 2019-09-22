class Solution {
public:
     void dfs(int i, int j, int len, string s, vector<string> &v, vector<vector<bool>> &dp,vector<vector<string>> &res)
        {
            if(j==len){
                res.push_back(v);
                for(int k=0;k<v.size();k++)
                    cout <<  v[k] << " ";
                cout << "\n";
                return ;
            }
            for(j=i;j<=len-1;j++){
                if(dp[i][j] ==1){
                    string output = "";
                    for(int k=0;k<(j-i+1);k++){
                       output = output + s[i+k];
                    }
                    //cout << output << " ";
                    //if(j<=len-1){
                    cout << "i:" << i << "-j:" << j << "   " ;
                    v.push_back(output);
                    dfs(j+1,j+1,len,s,v,dp,res);
                    v.pop_back();
                    //dfs(i,j+1,len,b,e,s);
                    //}
                }
            }
            
        }
        
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int len = s.size();
        //if(len == 0)return;
        int record[len] = {0};
        /*
        int x[len][len];
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
                x[i][j]=0;
        */
        for(int i=0;i<len;i++){
            dp[i][i] = 1;
            //x[i][i]=1;
             if(s[i]==s[i+1]){
                //x[i][i+1] = 1;
                dp[i][i+1] = 1;
            }
        }
        
        //DP
        for(int i=len-2;i>=0;i--){
            for(int j=i+1;j<len;j++){
                if(dp[i+1][j-1] && (s[i]==s[j])){
                    //x[i][j] = 1;
                    dp[i][j] = 1;
                }
            }
        }
        
        int max=0;
        int max_flag=0;
        vector<vector<string>> result;        
        vector<string> v;
        
        //for(int i=0;i<=len-1;i++){
            //for(int j=i;j<=len-1;j++){
                //if(x[i][j]==1 && j<=len-1){
                   dfs(0,0,len,s,v,dp,result);
                //}
            //}
        //}
        return result;
    }
};
