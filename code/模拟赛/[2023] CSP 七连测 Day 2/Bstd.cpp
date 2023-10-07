#include<bits/stdc++.h>
const int N = 1e4+10;
using namespace std;
int n;
int a[N];
int ans1 = 1e9;
bool v1[N];
void dfs1(int step,int cnt){
	if(step > n){
		ans1 = min(ans1,cnt);
		return;
	}
	if(cnt > ans1) return;
	if(v1[a[step]]){
		dfs1(step+1,cnt);
	}else{
		v1[a[step]] = 1;
		dfs1(step+1,cnt+1);
		v1[a[step]] = 0;
	}
	if(v1[a[step]+1]){
		dfs1(step+1,cnt);
	}else{
		v1[a[step]+1] = 1;
		dfs1(step+1,cnt+1);
		v1[a[step]+1] = 0;
	}
	if(v1[a[step]-1]){
		dfs1(step+1,cnt);
	}else{
		v1[a[step]-1] = 1;
		dfs1(step+1,cnt+1);
		v1[a[step]-1] = 0;
	}
}

int ans2 = 0;
bool v2[N];
void dfs2(int step,int cnt){
	if(step > n){
		ans2 = max(ans2,cnt);
		return;
	}
//	if(cnt > ans2) return;
	if(v2[a[step]]){
		dfs2(step+1,cnt);
	}else{
		v2[a[step]] = 1;
		dfs2(step+1,cnt+1);
		v2[a[step]] = 0;
	}
	if(v2[a[step]+1]){
		dfs2(step+1,cnt);
	}else{
		v2[a[step]+1] = 1;
		dfs2(step+1,cnt+1);
		v2[a[step]+1] = 0;
	}
	if(v2[a[step]-1]){
		dfs2(step+1,cnt);
	}else{
		v2[a[step]-1] = 1;
		dfs2(step+1,cnt+1);
		v2[a[step]-1] = 0;
	}
}
int main(){
	freopen("party.in","r",stdin);
	freopen("party.ans","w",stdout);
	cin >> n;
	for(int i =1;i <= n; i++) cin >> a[i];	
	dfs1(1,0);
	dfs2(1,0);
	cout << ans1 << " " << ans2;
	return 0;
}
