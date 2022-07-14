#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 1;
const int mod = 1e9 + 7;
 
int dp[N];
 
int main() {
	int n;
	cin >> n;
 
	// dp[x] -> return the number of ways to construct x 
	dp[0] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=6; j++) {
			if(i - j >= 0)
				(dp[i] += dp[i-j]) %= mod;
		}
	}
	cout << dp[n] << endl;
}
