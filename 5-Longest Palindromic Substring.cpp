class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 0)return "";
        int record[len] = {0};
        int x[len][len];
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
                x[i][j]=0;
        for(int i=0;i<len;i++){
            x[i][i]=1;
             if(s[i]==s[i+1]){
                x[i][i+1] = 1;
            }
        }
        
        //DP
        for(int i=len-2;i>=0;i--){
            for(int j=i+1;j<len;j++){
                if(x[i+1][j-1] && (s[i]==s[j]))
                    x[i][j] = 1;
            }
           
        }
        
        int max=0;
        int max_flag=0;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(x[i][j] == 1){
                    record[i] = (j-i+1);
                }
                //cout << x[i][j] << " ";
                //cout << record[i] << " ";
            }
            if(record[i]>=max){
                max = record[i];
                max_flag = i;
            }
            //cout << "\n";
        }
        string output = "";
        for(int i=0;i<max;i++){
            output = output + s[max_flag+i];
        }
        cout << output;

        return output;
    }
   
};
