#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

#define Weight first
#define Value second

pair<int, int> stock[101] = {};

int dp[101][100001]; // 수, 무게

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        int W, V;
        cin >> W >> V;

        stock[i].Weight = W;
        stock[i].Value = V;
    }

    for (int n = 1; n <= N; n++)
    {
        for (int w = 1; w <= K; w++)
        {
            int value = stock[n].Value;
            int weight = stock[n].Weight;

            if (w - weight < 0)
                dp[n][w] = dp[n - 1][w];
            else
                dp[n][w] = max(dp[n - 1][w], value + dp[n - 1][w - weight]);
        }
    }

    cout << dp[N][K];

    return 0;
}
