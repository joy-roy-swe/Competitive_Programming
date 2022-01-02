#include <iostream>
using namespace std;

int n;
int coins[15];

int getmaxscore(int l, int r, int n){
	int mscore = 0;
	for (int i = l + 1; i < r; i++) {
		int cs = getmaxscore(l, i, n) + getmaxscore(i, r, n);
		if (l == 0 && r == n)
			cs = cs + coins[i];
		else
			cs = cs + (coins[l] * coins[r]);

		if (cs > mscore)
			mscore = cs;
	}
	return mscore;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> coins[i];
	coins[0] = coins[n + 1] = 1;

	cout << getmaxscore(0, n + 1, n + 1) << "\n";

	return 0;
}