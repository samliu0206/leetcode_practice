class Solution {
public:
    int dfs(int i, int j, int len, string s, vector<string> &v, vector<vector<bool>> &dp,vector<vector<string>> &res, int count, int min)
        {
            if(j==len){
                if(count <= min || min ==0)
                    min = count;
                res.push_back(v);
                //for(int k=0;k<v.size();k++)
                //    cout <<  v[k] << " ";
                //cout << "\n";
                return min;
            }
            for(j=i;j<=len-1;j++){
                if(dp[i][j] ==1){
                    string output = "";
                    for(int k=0;k<(j-i+1);k++){
                       output = output + s[i+k];
                    }
                    //cout << output << " ";
                    //if(j<=len-1){
                    //cout << "i:" << i << "-j:" << j << "   " ;
                    v.push_back(output);
                    count++;
                    min = dfs(j+1,j+1,len,s,v,dp,res,count,min);
                    v.pop_back();
                    count--;
                    //dfs(i,j+1,len,b,e,s);
                    //}
                }
            }
            cout << min << "\n";
            
            return min;
            
        }
    int minCut(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        vector<int> d(s.size());
        int len = s.size();
        if(len == 0)return 0;
        int record[len] = {0};
        for(int i=0;i<len;i++){
            dp[i][i] = 1;
             if(s[i]==s[i+1]){
                dp[i][i+1] = 1;
            }
        }
        
        //DP
        for(int i=len-1;i>=0;i--){
            d[i] = len-i-1; // Max of minCut of i....(len-1)
            for(int j=i;j<len;j++){
                if(j>i){
                    if((dp[i+1][j-1] || j-i<2) && (s[i]==s[j])){
                        dp[i][j] = 1;
                        if(j==len-1)
                            d[i] = 0;
                        else
                            d[i] = min(d[j+1]+1,d[i]);
                    }
                }
                if(j==i){
                    if(j==len-1)
                            d[i] = 0;
                        else
                            d[i] = min(d[j+1]+1,d[i]);
                }
            }
        }
        
        int max=0;
        int max_flag=0;
        vector<vector<string>> result;
        vector<string> v;
        int count=0;
        int min=0;
        
        //int res = dfs(0,0,len,s,v,dp,result,count,min);
        //cout << res;
        
        return d[0];
    }
};
