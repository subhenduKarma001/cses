#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define nline '\n'
 
int N, cnt[26];
string S, perm;
vector<string> perms;
 
 
void search() {
	if(perm.size() == S.size()) {
		perms.push_back(perm);
		return ;
	}
 
	for(int i=0; i<26; ++i) {
		if(cnt[i]) {
			--cnt[i];
			perm += char('a' + i);
			search();
			++cnt[i];
			perm.pop_back();
		}
	}
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> S;
	for(char c : S) 
		cnt[c - 'a']++;
	search();
	cout << perms.size() << nline;
	for(string t : perms) 
		cout << t << nline;
 
	return 0;
}