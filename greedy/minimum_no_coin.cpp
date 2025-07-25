#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void coinChangeGreedy(vector<int>& coins, int amount) {
    // Sort coins in descending order
    sort(coins.rbegin(), coins.rend());

    cout << "Coins used to make amount " << amount << ":\n";

    for (int coin : coins) {
        while (amount >= coin) {
            amount -= coin;
            cout << coin << " ";
        }
    }

    if (amount != 0)
        cout << "\nCannot make exact amount with given coins.";
}

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000}; // Indian coin set
    int amount = 2758;

    coinChangeGreedy(coins, amount);

    return 0;
}