class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)return 0;
        int low = prices[0];
        int n = prices.size();
        int profit = 0;
        for(int i=0;i<n;i++){
            low = min(prices[i],low);
            profit = max(profit, prices[i]-low);
        }
        cout << profit;
        return profit;
    }
};
