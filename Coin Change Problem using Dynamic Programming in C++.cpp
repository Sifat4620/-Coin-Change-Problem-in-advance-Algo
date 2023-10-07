#include <bits/stdc++.h>
using namespace std;

int count(int coins[], int length, int amount)
{
    int table[length + 1][amount + 1]; // Increase array dimensions

    for (int i = 0; i <= length; i++) {
        for (int j = 0; j <= amount; j++) {
            if (i == 0) {
                table[i][j] = 0; // Initialize the first row to 0
            } else if (j == 0) {
                table[i][j] = 1; // Initialize the first column to 1
            } else if (coins[i - 1] > j) {
                table[i][j] = table[i - 1][j];
            } else {
                table[i][j] = table[i - 1][j] + table[i][j - coins[i - 1]];
            }
        }
    }

    return table[length][amount]; // Return the value at the last cell
}

int main()
{
    int coins[] = {1, 2, 3, 5};
    int amount = 7;

    cout << count(coins, sizeof(coins) / sizeof(coins[0]), amount);
    return 0;
}
