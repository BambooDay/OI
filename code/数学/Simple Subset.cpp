#include <bits/stdc++.h>
using namespace std;
int n,num[1005],ans,c[3000005],pri[3000005],tot,cnt,flag1,flag2,flag3;
void get(){
	for(int i=2; i<=2000000; i++) {
		if(c[i]==0)pri[++tot]=i;
		for(int j=1; j<=tot; j++) {
			if((long long)i*(long long)pri[j]>2000000)break;
			c[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}	
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> num[i];
	sort(num+1,num+n+1);
	get();
	for(int i = 1; i <= n; i++){
		if(num[i] == 1) cnt++;
	}
	ans = cnt;
	flag1 = -1;
	for(int i = cnt+1; i <= n; i++) {
		if(c[num[i]+1] == 0) {
			if(ans >= cnt+1) continue;
			ans = cnt+1;
			flag1 = 1;
			flag2 = i;
		}
		for(int j = cnt+1; j <= n; j++) {
			if(c[num[i]+num[j]] == 0) {
				if(ans >= 2)continue;
				ans = 2;
				flag1 = 2;
				flag2 = i;
				flag3 = j;
			}
		}
	}
	if(ans == 0) {
		cout << 1 << endl << num[1] << endl;
		return 0;
	}
	cout << ans << endl;
	if(flag1 == -1) {
		for(int i = 1; i <= ans; i++)cout << 1 << " ";
		return 0;
	}
	if(flag1 == 1) {
		for(int i = 1; i <= ans-1; i++)cout << 1 << " ";
		cout << num[flag2] << endl;
		return 0;
	}
	cout << num[flag2] << " " << num[flag3] << endl;
	return 0;
}

