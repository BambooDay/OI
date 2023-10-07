#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n, a, b;
int w[100];
bool v[100];
ll ans = INF;
bool cmp(int x, int y){
	return w[x] < w[y]; 
}
void dfs(ll sum,int rest){
	if(rest == 0){
		ans = min(ans,sum);
		return;
	}
	for(int i = 1;i <= rest; i++){
		for(int l = 1; l +i <= n; l++){
			
			int x[110];
			int k = 1;
			for(int j = l; j <= n&&k <= i;j++){
				if(v[j]) continue;
				x[k++] = j;
				v[j] = 1;
			}
			if(k < i) break;
			sort(x+1,x+1+i,cmp);
			dfs(sum + a + b * (w[x[1]] - w[x[i]])*(w[x[1]] - w[x[i]]),rest - i);
			for(int j = 1;j <= i; j++){
				v[x[j]] = 0,x[j] = 0;
			} 
		}
	} 
}
int main(){
	cin >> n >> a >> b;
	bool flag = 1;
	for(int i =1;i <= n; i++){
		cin >> w[i];
		if(w[i] != w[i-1]&& i > 1) flag = 0;
	} 
	if(flag){
		cout << a;
		return 0;
	}
	dfs(0,n);
	cout << ans;
	return 0;
}
