class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=0)return 0;
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        // 1 2 3 4 1
        // become 2 cases:
        // -> 1 2 3 4
        // -> 2 3 4 1
        
        /*
        take :nums[i] + P[i-2]
        nonTake:P[i-1]
        */
        int max_0 = 0;
        int n = nums.size()-1;
        if(n==0)max_0 = 0;
        if(n==1)max_0 = nums[0];
        if(n==2)max_0 = max(nums[0],nums[1]);
        int dp[n] = {0}; 
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
            //if(dp[i]>=max_0)
            max_0 = dp[i]>=max_0 ? dp[i] : max_0;
        }
        
        for(int i=0;i<n;i++)
            dp[i] = 0;
        int max_1 = 0;
        if(n==0)max_1 = 0;
        if(n==1)max_1 = nums[1];
        if(n==2)max_1 = max(nums[1],nums[2]);
        dp[0] = nums[1];
        dp[1] = max(nums[2],nums[1]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-2]+nums[i+1], dp[i-1]);
            //if(dp[i]>=max_0)
            max_1 = dp[i]>=max_1 ? dp[i] : max_1;
        }
        
        cout << max_0 << endl;
        cout << max_1;
        if(max_0>=max_1)return max_0;
        else return max_1;
        //return max_0;
    }
};
