#include<iostream>
#include<vector>

using namespace std;


int dp[2][2000];

int main() {
	int n, r, a, b;
	cin >> n >> r;
	vector<int> arr(n), c(n);
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c[i];
		arr[i] = 2 * (a + b);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 2000; j++) dp[1][j] = dp[0][j];
		for(int j = 0; j <= 2000; j++) {
			if(arr[i - 1] + j <= r) {
				dp[1][arr[i - 1] + j] = max(dp[0][arr[i - 1] + j], dp[0][j] + c[i - 1]);
			}
		}
		for(int j = 0; j <= 2000; j++) dp[0][j] = dp[1][j];
	}
	int ans = 0;
	for(int i = 0; i <= 2000; i++) ans = max(ans, dp[1][i]);
		/*
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= 18; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	cout << ans << endl;
}