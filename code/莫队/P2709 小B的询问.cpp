#include <bits/stdc++.h>
const int N = 5e4+10;
#define int long long
using namespace std;
int n,m,color[N],cnt[N],ans,k;
struct ques{
	int l,r,id;
	int a,b;
	
}ask[N];
int block;
bool cmp(ques x, ques y){
	if((x.l-1)/block +1 != (y.l-1)/block+1) return  (x.l-1)/block +1 < (y.l-1)/block+1;
	if(((x.l-1)/block+1)%2) return x.r < y.r;
	return x.r > y.r;
}
bool cmp1(ques x, ques y){
	return x.id < y.id; 
}
void update(int pos, int x){
//	cout  << pos << " "  << x << " " << ans << " "; 
	ans -= cnt[color[pos]] * cnt[color[pos]];
	cnt[color[pos]] += x;
	ans += cnt[color[pos]]*cnt[color[pos]];
//	cout << ans << endl; 
}
void solve(){
	for(int i = 1,l = 1, r = 0; i <= m; i++){
//		cout << ask[i].l << ' ' <<ask[i].r << endl; 
		while(r < ask[i].r){
			update(++r,1);
		}
		while(r > ask[i].r){
			update(r--,-1);
		}
		while(l < ask[i].l){
			update(l++,-1);
		}
		while(l > ask[i].l){
			update(--l,1);
		}
		ask[i].a = ans;
		
	}
}
signed main(){
	cin >> n >> m >> k;
	for(int i = 1;i <= n; i++) cin >> color[i];
	block = sqrt(n);
	for(int i =1; i <= m; i++){
		cin >> ask[i].l >> ask[i].r;
		ask[i].id = i;
	}
	sort(ask+1,ask+1+m,cmp);
	solve();
	sort(ask+1,ask+1+m,cmp1);
	for(int i = 1;i <= m; i++){
		cout << ask[i].a <<  endl;
	}
	return 0;
}
