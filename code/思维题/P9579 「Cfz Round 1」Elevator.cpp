#include <bits/stdc++.h>
const int N = 5e5 + 10;
using namespace std;
int n,cnt,ma,mi,ans;
pair<int,int> s[N];

int main() {
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> s[++cnt].first >> s[cnt].second;
		ma = max(ma,max(s[cnt].first,s[cnt].second));
		if(s[cnt].first < s[cnt].second) cnt--;
	}
	mi = ma;
	sort(s+1,s+1+cnt);
	for(int i = cnt; i >= 1; i--){
		if(s[i].first != s[i-1].first && mi > s[i].second){
			ans += (min(mi,s[i].first) - s[i].second)*2;
			mi = s[i].second;
			if(ans > ma - mi) ans = ma-mi;
		}
	}
	cout << ma + ans;
	return 0;
}
