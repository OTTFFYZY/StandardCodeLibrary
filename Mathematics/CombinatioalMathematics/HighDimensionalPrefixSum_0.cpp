#include<bits/stdc++.h>
using namespace std;
int dp[10];
vector<int>G[10];
void trans(int x) {
	int a = x % 2; x /= 2;
	int b = x % 2; x /= 2;
	int c = x % 2; x /= 2;
	cout << c << b << a ;
}
void print(int x) {
	for (int s = 0; s < (int)G[x].size(); s++) {
		trans(G[x][s]); cout << " ";
	}
}
int main() {
	for (int s = 0; s < 8; s++) {
		G[s].push_back(s);
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 3; ++i) {
		cout << i << endl;
		for (int j = 0; j < 8; ++j) {
			if (!(j&(1 << (i))))
			{
				int v = (j | (1 << (i)));
				trans(j); cout << ":"; print(j); cout << endl;
				trans(v); cout << ":"; print(v); cout << endl;
				for (int s = 0; s < (int)G[v].size(); s++) {
					G[j].push_back(G[v][s]);
				}
				trans(j); cout << ":"; print(j); cout << endl;
				dp[j] += dp[j | (1 << (i))];
				cout << endl;
			}
		}
	}
	for (int s = 0; s < 8; s++) {
		trans(s); cout << ":"; print(s); cout << endl;
	}
	return 0;
}