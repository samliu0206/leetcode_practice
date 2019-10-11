class Solution {
public:
    int findIntegers(int num) {
        if (num < 3) return num + 1;
        string binary = bitset<40>(num).to_string(); //to binary
        cout<<binary<<"\n\n";
        int bin[40] = {0};
        for(int i=0;i<40;i++){
            if(binary[39-i] == '1')
                bin[i] = 1;
            else 
                bin[i] = 0;
        }
        int len = binary.length();
        int dp[100][2];
        for(int i=0;i<100;i++)
            for(int j=0;j<2;j++)
                dp[i][j] = 0;
        //DP
        // dp[i][0] = dp[i-1][0] + dp[i-1][1];
        // dp[i][1] = dp[i-1][0];
        dp[0][0]=1;
        dp[0][1]=1;
        
        // Build DP table
        for(int i=1;i<40;i++){
            for(int j=0;j<2;j++){
                if(j==0){
                    dp[i][j] = dp[i-1][0] + dp[i-1][1];
                }else{
                    dp[i][j] = dp[i-1][0];
                }
            }
        }
        int sum = 0, pre=-1, ok=1;
        for(int i=39;i>=0;i--){
            //cout << bin[i];
            if(bin[i]==1){
                sum+=(i==0?1:dp[i-1][1]+dp[i-1][0]);
                //往低位找，如果自己是1而前一位也是1則停止往下找，
                //因所有數皆符合，故dp[i-1][x]就是答案
                //反之，如果前一位是1而自己是0，則繼續往下找
                if(pre==1) {
                    ok=0;
                    break;
                }
            }
            if(pre==1) 
                pre=0;
            else 
                pre=bin[i];
        }
        cout << "ans:" << sum + ok  << endl;
        return sum+ok;
    }
};
