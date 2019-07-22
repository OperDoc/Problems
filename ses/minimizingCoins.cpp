#include <bits/stdc++.h>

using namespace std;

int arr[100], dp[1000010];

int main() {
  int n, x;
  cin >> n >> x;
  
  for(int i = 0; i < n; i++)
    cin >> arr[i];

  for(int i = 1; i < 1000010; i++)
    dp[i] = -1;
  
  for(int i = 1; i < 1000010; i++)
    for(int j = 0; j < n; j++)
      if(i - arr[j] >= 0 and dp[i - arr[j]] != -1) 
	dp[i] = dp[i] == -1 ? dp[i - arr[j]] + 1 : min(dp[i], dp[i - arr[j]] + 1);
     
  cout << dp[x]  <<  endl;
}
