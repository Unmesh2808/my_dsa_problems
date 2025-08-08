int maxProfit(vector<int>& prices) {
        int lp = 0;
        int rp = prices.size()-1;
        int max_op=0;
        while (lp<rp){
            int earn = prices[rp]-prices[lp];
            if (earn<0) rp--;
            else lp++;
            // lp<rp ? lp++:rp--;
            max_op = max(max_op, earn);
        }
        return max_op;
    }

int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for (int i=1;i<prices.size();i++){
            if(prices[i]<buy){
                buy = prices[i]; 
            }
            else if ((prices[i]-buy)>profit){
                profit = prices[i]-buy;
            }
        }
        return profit;
    }