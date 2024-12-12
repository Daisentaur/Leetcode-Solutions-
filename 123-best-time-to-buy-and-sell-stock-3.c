#include<limits.h>

int maxProfit(int* prices, int pricesSize) {
    
    int sellTwo = 0;
    int holdTwo = INT_MIN;  //INT_MIN is used as an initial value(which is normally -2,147,483,648) for holdTwo and holdOne to represent an impossibly low initial profit. This allows the algorithm to compare and update these values as it processes stock prices.
    int sellOne = 0;
    int holdOne = INT_MIN;
    
    for (int i = 0; i < pricesSize; i++) {
        // Update sell two - max profit from two complete transactions
        sellTwo = (sellTwo > holdTwo + prices[i]) ? sellTwo : (holdTwo + prices[i]);
        // Update hold two - max profit after second buy
        holdTwo = (holdTwo > sellOne - prices[i]) ? holdTwo : (sellOne - prices[i]);
        // Update sell one - max profit from one complete transaction
        sellOne = (sellOne > holdOne + prices[i]) ? sellOne : (holdOne + prices[i]);
        // Update hold one - max profit after first buy
        holdOne = (holdOne > -prices[i]) ? holdOne : (-prices[i]);
    }
    
    return sellTwo;
}