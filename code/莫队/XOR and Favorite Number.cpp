#include <bits/stdc++.h>
const int N = 2e6+10;
#define int long long
using namespace std;
int n,m,a[N],cnt[N<<1],sum[N],k,ans;
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
void add(int pos){
	ans += cnt[sum[pos]^k];
	cnt[sum[pos]]++;
}
void del(int pos){
	cnt[sum[pos]]--; 
	ans -= cnt[sum[pos]^k];
}	
void solve(){
	cnt[0] = 1;
	for(int i = 1,l = 0, r = 0; i <= m; i++){
//		cout << ask[i].l << ' ' <<ask[i].r << endl; 
		while(r < ask[i].r){
			add(++r);
		}
		while(r > ask[i].r){
			del(r--);
		}
		while(l < ask[i].l){
			del(l++);
		}
		while(l > ask[i].l){
			add(--l);
		}
		ask[i].a = ans;
		
	}
}
signed main(){
	cin >> n >> m >> k;
	for(int i = 1;i <= n; i++) cin >> a[i];
	for(int i =1;i <= n; i++){
		sum[i] = sum[i-1]^a[i];
	}
	block = sqrt(n);
	for(int i =1; i <= m; i++){
		cin >> ask[i].l >> ask[i].r;
		ask[i].l--;
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
