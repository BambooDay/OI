#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
pair<int,int> a[N];
int sum[N];
int n;
int tr1[N*2],tr2[N*2];
void modify(int x, int y,int tr[]){
	for(int i = x;i <= n*2+10; i+=(i&-i)){
		tr[i] = min(tr[i],y);
	}
}
int ask(int x, int tr[]){
	int ans = 1e9;
	for(int i = x;i;i -= (i&-i)) ans = min(ans,tr[i]);
	return ans;
}
int main(){
	fill(tr1,tr1+N*2,N-1);
	fill(tr2,tr2+N*2,N-1);
	a[N-1].first = 1e9;
	cin >> n;
	for(int i = 1;i <= n; i++){
		int x; char ch;
		cin >> x >> ch;
		a[i] = {x,(ch == 'W' ? 1 : -1)};
	}	
	sort(a+1,a+1+n);
	int ans = 0;
	for(int i = 1;i <= n; i++){
		sum[i] = sum[i-1] + a[i].second;
		if(i > 1) ans = max(ans,a[i].first - a[ask(sum[i]+n+1,(i&1 ? tr1:tr2))].first);
		modify(sum[i]+n+1,i,(i&1?tr2:tr1));		
	}
	cout << ans << endl;
	return 0;
}
