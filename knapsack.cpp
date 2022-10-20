#include<bits/stdc++.h>
using namespace std;

#define mod 100000007
#define maxn 500000

typedef long long ll;


ll knapsack(ll v[], int w[], int n, int W)
{
	ll dp[n + 1][W + 1];
	for (int i = 0; i <= n; i++)dp[i][0] = 0;
	for (int i = 0; i <= W; i++)dp[0][i] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (w[i - 1] > j)dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
		}
	}
	return dp[n][W];
}

main()
{
	int n, W;
	cin >> n >> W;
	ll v[n];
	int w[n];
	for (int i = 0; i < n; i++)cin >> w[i] >> v[i];
	cout << knapsack(v, w, n, W) << endl;
}