#include<bits/stdc++.h>
using namespace std;

#define mod 10000000000001
#define maxn 1000
#define inf INT_MAX-1

typedef long long ll;
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i < n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)

int dp[105][105];


int mcm(int arr[], int x, int y)
{
	if (x == y)return 0;
	if (dp[x][y] != -1)return dp[x][y];
	int ans = INT_MAX;
	for (int i = x; i < y; i++)ans = min(ans, mcm(arr, x, i) + mcm(arr, i + 1, y) + arr[x - 1] * arr[i] * arr[y]);
	return dp[x][y] = ans;
}

int mcm1(vector<int> arr, int n)
{
	int dp1[n][n];
	for (int i = 1; i < n; i++)dp1[i][i] = 0;
	for (int L = 2; L < n; L++)
	{
		for (int i = 1; i < (n - L + 1); i++)
		{
			int j = (i + L - 1);
			dp1[i][j] = INT_MAX;
			for (int k = i; k < j; k++)
			{
				int ans = dp1[i][k] + dp1[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
				if (dp1[i][j] >= ans)dp1[i][j] = ans;
			}
		}
	}
	return dp1[1][n - 1];
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		vector<int>a;
		rep(i, n)cin >> arr[i];
		rep(i, n)a.push_back(arr[i]);
		memset(dp, -1, sizeof(dp));
		cout << (mcm(arr, 1, n - 1)) << endl;
		cout << (mcm1(a, n)) << endl;
	}
}






















