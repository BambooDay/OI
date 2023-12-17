#include <bits/stdc++.h>

using namespace std;
int n,m;
struct ques{
	int t,m,id;
	friend bool operator <(ques x, ques y){
		return x.t < y.t;
	}
}q[100005];
int dp[305][300*300+5];
struct obj{
	int c,v,t;
	friend bool operator <(obj x, obj y){
		return x.t < y.t;
	}
}a[305];
int ans[100005];
int main(){
	freopen("market.in","r",stdin);
	freopen("market.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++) cin >> a[i].c >> a[i].v >> a[i].t;
	sort(a+1,a+1+n);
	int ma = -1;
	for(int i = 1; i <= m; i++){
		cin >> q[i].t >> q[i].m;
		ma = max(ma,q[i].m);
		q[i].id = i;
	}
	ma = min(ma,300*300);
//	cout << ma << endl;
	sort(q+1,q+1+m);
	int now = 1;
	for(int i = 1; i <= m; i++){
		for(;now <= n && a[now].t <= q[i].t; now++){
//			cout << a[now].c << " " ;
			for(int j = 0; j <= ma; j++){
				dp[now][j] = dp[now-1][j];
				if(j >= a[now].c) {
					dp[now][j] = max(dp[now][j],dp[now-1][j-a[now].c]+a[now].v);		
//					cout<< dp[now][j] << " "; 
				}	
			}
		}
//		cout << now << " " << dp[now-1][] << endl;
		ans[q[i].id]= dp[now-1][min(q[i].m,ma)];
//		cout << q[i].id << " " << q[i].m << " " << now << " " << dp[now][q[i].m] << endl;
	}	
//	cout << now << endl;
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= 10; j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}

	for(int i = 1;i <= m; i++) cout << ans[i] << endl;
	return 0;
}
