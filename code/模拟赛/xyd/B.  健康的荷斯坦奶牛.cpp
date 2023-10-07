#include <bits/stdc++.h>

using namespace std;
int n, m;
int need[30];
int a[20][30];
int ans[30];//ªπŒ¥≥ı ºªØ 
int res[30];
bool v[30];
bool check(int cnt){
	for(int i = 1; i <= cnt; i++){
		if(ans[i] > res[i]) return 1;
	}
	return 0;
}
void dfs(int cnt,int fa){
	bool f = 1;
	for(int i = 1; i <= n; i++){
		if(need[i] > 0) f = 0;
	}
	if(f){
		if(cnt < ans[0]){
//			cout << 1 << " ";
			ans[0] = cnt;
			for(int i = 1; i <= cnt;i++) ans[i] = res[i];
		}//else if(cnt == ans[0] && check(cnt)){
//			for(int i = 1; i <= cnt;i++) ans[i] = res[i];
//		}
		return;
	}
	if(fa >= m) return;
	for(int i = fa+1; i <= m; i++){
		if(v[i]) continue;
		v[i] = 1;
		for(int j =1; j<= n; j++){
			need[j] -= a[i][j];
		}
		res[cnt+1] = i;
		dfs(cnt+1,i);
		res[cnt+1] = 0;
		for(int j =1; j <= n; j++){
			need[j] += a[i][j];
		}	
		v[i] = 0;	
	}
}
int main(){
	memset(ans,0x3f,sizeof ans);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> need[i];
	}
	cin >> m;	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j<= n; j++){
			cin >> a[i][j];
		}
	}
	dfs(0,0);
//	cout << ans[0];
	for(int i =0; i <= ans[0]; i++){
		cout << ans[i] << " "; 
	}
	return 0;
}
