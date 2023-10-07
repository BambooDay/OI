#include <bits/stdc++.h>

using namespace std;
int n;
//bool vis[20];
int ans[1000006];//,a[20],cnt = 1e9;
//void dfs(int ma,int mi, int step){
//	if(step > n){
//		if(ma-mi < cnt){
//			for(int i =1;i <= n; i++){
//				ans[i] = a[i];
//			}
//			cnt = ma - mi;
//		}
//		return;
//	}
//	for(int i = 1;i <= n;i++){
//		if(vis[i]) continue;
//		a[step] = i;
//		vis[i] = 1;
//		if(step == 1){
//			dfs(ma,mi,step+1);
//		}else if(step == n){
//			dfs(max(ma,max(i+a[step-1],i+a[1])),min(mi,min(i+a[step-1],i+a[1])),step+1);
//		}else{	
//			dfs(max(ma,i + a[step-1]),min(mi,i+a[step-1]),step+1);
//		}
//		vis[i] = 0;
//		
//	}
//}
int main(){
	cin >> n;
//	for(int i = 1; i <= n/2; i++){
//		cout << i << " " << n+1-i << " ";
//	}	
//	if(n%2){
//		cout << n/2+1 << endl;
//	}
//	dfs(0,1e9,1);
	if(n%2 == 0){
		int now = 1;
		for(int i = 1; i <= n/2; i += 2){
			ans[now] = i;
			now += 2;
		}
		for(int i =(n/2%2 ? n/2-1 : n/2); i; i -= 2){
//		cout << i << " ";
			ans[now] = i;
			now += 2;
		}
		now = 2;
		for(int i = n-1; i > n/2; i -= 2){
			ans[now] = i;
			now += 2;
		}
		for(int i = (n/2%2 ? n/2-1 : n/2)+2; i <= n; i += 2){
			ans[now] = i;
			now += 2;
		}
	}else{
		int now = 1;
		for(int i =1; i <= n; i+=2){
			ans[now] = i;
			now += 2;
		}
		now = 2;
		for(int i = n-1; i; i -= 2){
			ans[now] = i;
			now += 2;
		}
	}	
	for(int i =1; i <= n; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
