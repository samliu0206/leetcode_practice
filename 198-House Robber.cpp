class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int dp[n] = {0};
        /*
        take :nums[i] + P[i-2]
        nonTake:P[i-1]
        */
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        int max_0 = 0;
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
            //if(dp[i]>=max_0)
            max_0 = dp[i]>=max_0 ? dp[i] : max_0;
        }
        cout << max_0;
        return max_0;
    }
};
