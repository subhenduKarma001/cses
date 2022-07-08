#include<bits/stdc++.h>
using namespace std;
 
#define vi vector<int> 
 
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	for(auto&x : arr) cin >> x;
 
	vector<int> dp(x+1, 1e9);
	dp[0] = 0;
	// dp[x] -> number of minimum coins req. to produce x sum
	for(int i=1; i<=x; i++) {
		for(int j=0; j<n; j++) {
			if(i - arr[j] >= 0)
				dp[i] = min(dp[i], dp[i - arr[j]] + 1);
		}
	}
	cout << (dp[x] == 1e9 ? -1 : dp[x]) << endl;
}
