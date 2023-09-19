#include <bits/stdc++.h>
using namespace std;

int count(int coins[], int length, int amount)
{
    int table[length + 1][amount + 1];

    for (int i = 0; i <= length; i++) {
        for (int j = 0; j <= amount; j++) {
            if (i == 0 && j == 0) {
                table[i][j] = 1;    // first indexing value
            }
            else {
                if (coins[i - 1] > j) {
                    table[i][j] = table[i - 1][j];   // upper value copy
                } else {
                    table[i][j] = table[i - 1][j] + table[i][j - coins[i - 1]];   // include & exclude
                }
            }
        }
    }

    return table[length][amount];
}

int main()
{
    int coins[] = {1, 2, 3, 5};
    int amount = 7;
    cout << count(coins, sizeof(coins) / sizeof(coins[0]), amount);
    return 0;
}
