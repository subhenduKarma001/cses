#include<bits/stdc++.h>
using namespace std;
 
#define vi vector<int> 
 
const int mod = 1e9 + 7;
 
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	for(int&x : arr) cin >> x;
 
	vector<int> dp(x, 0);
	dp[0] = 1;
	// dp[x] -> number of ways to make x 
	for(int i=1; i<=x; i++) {
		for(int j=0; j<n; j++) {
			if(i-arr[j] >= 0) 
				(dp[i] += dp[i-arr[j]]) %= mod;
		}
	}
	cout << dp[x] << endl;
}
