using namespace std;

class Solution {
public:
    int maxProfit(vector<int> const prices) {
        int minPrice = 10001;
        int ret = 0;
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            ret = max(ret, prices[i] - minPrice);
        }
        return ret;
    }
};