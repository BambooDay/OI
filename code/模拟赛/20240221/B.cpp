#include <bits/stdc++.h>

using namespace std;
int n;
int w = 1,cnt = 1,tmp = 0;
void solve() {
	cin >> n;
	w = 1,cnt = 1,tmp = 0;
	bool flag = 1;
	for(int i = 1;i <= n; i++){
		int opt;
		cin >> opt;
		if(opt==1) {
			++w;
			++cnt;
		} else if(opt == -1) {
			if(cnt>1){
				cnt--; 
			}else if(cnt == 1) {
				if(tmp == 0){
					flag = 0;
				}else{
					tmp--;
					w++;
					cnt++;
				}
			}
		} else if(opt == 0) {
			if(cnt == 1) {
				cnt++;
				w++;
			} else {
				cnt--;
				tmp++;
			}
		}
	}
	if(!flag) {
		puts("-1");
		return;
	} else if(flag){
		int GCD = __gcd(w,cnt);
		w /= GCD;
		cnt /= GCD;
		cout << w << " " << cnt << endl;
		return;
	}
	return;
}
int main() {
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
