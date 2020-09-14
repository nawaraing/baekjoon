#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
//#include <algorithm>

using namespace std;


int		ft_nC2(int n)
{
	return (n * (n - 1) / 2);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, r, pi, cnt, tmp, dot_sum[360000];
	long long		except = 0, tri;
	//  setting dot_sum
	cin >> n; cin >> r;
	cnt = 0; tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> pi;
		for (int j = tmp; j < pi; j++)
			dot_sum[j] = cnt;
		cnt++;
		tmp = pi;
	}
	for (int i = tmp; i < 360000; i++)
		dot_sum[i] = cnt;
	
	// ans = tiangle - jik-gak - doon-gak
	tri = n * (n - 1) * (n - 2) / 6;

	for (int i = 0; i < 180000; i++) {
		if ((!i && dot_sum[i] == 1 && dot_sum[i + 180000] == dot_sum[i + 180000 - 1] + 1) || 
				(i && dot_sum[i] == dot_sum[i - 1] + 1 && dot_sum[i + 180000] == dot_sum[i + 180000 - 1] + 1)) { // jik-gak triagle
			except += (n - 2);
		}
		else if ((!i && dot_sum[i] == 1) || dot_sum[i] == dot_sum[i - 1] + 1) { // behind line doon-gak triangle
			cnt = dot_sum[360000 - 1] - dot_sum[i + 180000] + dot_sum[i - 1];
			except += ft_nC2(cnt);
		}
		else if (dot_sum[i + 180000] == dot_sum[i + 180000 - 1] + 1) { // forward line doon-gak triangle
			cnt = dot_sum[i + 180000] - dot_sum[i] - 1;
			except += ft_nC2(cnt);
		}
	}
	cout << tri - except;
	return (0);
}
