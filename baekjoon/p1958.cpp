#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int		dp[101][101][101];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string	a, b, c;
	int		ans = 0;

	cin >> a >>  b >> c;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			for (int k = 1; k <= c.size(); k++) {
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
				{
					int	maxi = max(dp[i - 1][j][k], dp[i][j - 1][k]);
					maxi = max(maxi, dp[i][j][k - 1]);
					dp[i][j][k] = maxi;
				}
			}
		}
	}
	cout << dp[a.size()][b.size()][c.size()];
	return (0);
}