class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // for(int i=0;i<prices.size();i++){
        //     for(int j =i+1;j<prices.size();j++){
        //         maxProfit=max(maxProfit,prices[j]-prices[i]);
        //     }
        // }
        // return maxProfit;int maxProfit=0;
        int minPrice =prices[0];
        int maxProfit=0;


        for(int i=1;i<prices.size();i++){
            minPrice=min(minPrice,prices[i]);
            int profit=prices[i]-minPrice;
            maxProfit=max(maxProfit,profit);
        }
        
        return maxProfit;
    }
};