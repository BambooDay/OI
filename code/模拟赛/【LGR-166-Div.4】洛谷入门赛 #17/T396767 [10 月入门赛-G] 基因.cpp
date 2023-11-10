#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
string s,t;
void solve(){
	cin >> n >> s;
	t = s;
	int ans = 0;
	reverse(t.begin(),t.end());
	for(int i = 0; i < n; i++){
		if(s[i] == 'A'){
			ans += (t[i] == 'T')*(i+1); 
		} else if(s[i] == 'T'){
			ans += (t[i] == 'A')*(i+1); 
		}else if(s[i] == 'C'){
			ans += (t[i] == 'G')*(i+1);
		}else if(s[i] == 'G'){
			ans += (t[i] == 'C')*(i+1);
		}else{
			puts("0");
			return;
		}
	}
	cout << ans << endl;
}
signed main(){
	int T;
	cin >> T;
	while(T--) solve();	
	return 0;
} 
