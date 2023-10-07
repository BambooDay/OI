#include <bits/stdc++.h>
const int N = 5e4+10;
#define int long long
using namespace std;
int n,m,color[N],cnt[N],ans;
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
	ans -= cnt[color[pos]] * cnt[color[pos]];
	cnt[color[pos]] += x;
	ans += cnt[color[pos]]*cnt[color[pos]];
}
void solve(){
	for(int i = 1,l = 1, r = 0; i <= m; i++){
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
		if(ask[i].l == ask[i].r){
			ask[i].a = 0;
			ask[i].b = 1;
			continue;
		}
		ask[i].a = ans - (ask[i].r - ask[i].l +1);
		ask[i].b = (ask[i].r - ask[i].l+1)*1ll*(ask[i].r - ask[i].l);
		int g = __gcd(ask[i].a,ask[i].b);
		ask[i].a /= g;
		ask[i].b /= g;
	}
}
signed main(){
	cin >> n >> m;
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
		cout << ask[i].a << '/' << ask[i].b << endl;
	}
	return 0;
}
